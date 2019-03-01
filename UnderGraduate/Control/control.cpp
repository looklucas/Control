#include "control.h"
#include "ui_control.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

Control::Control(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);
    instantAiCtrl = nullptr;
    instantDiCtrl = nullptr;
    instantDoCtrl = nullptr;

    graph_t = new SimpleGraph(ui->graphFrame);
    graph_t->setFixedSize(ui->graphFrame->size());
    graph_p = new SimpleGraph(ui->graphFrame_2);
    graph_p->setFixedSize(ui->graphFrame_2->size());
    for (int i = 0; i < 16; i++)
    {
        scaledData[i] = 0;
    }
    

    timer = new QTimer(this);
    timer_control = new QTimer(this);
    Time_total = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(TimerTicked()));
    connect(timer_control, SIGNAL(timeout()), this, SLOT(DutyControl()));

    connect(ui->sld_open, SIGNAL(valueChanged(int)), this, SLOT(sld_open_change(int)));
    connect(ui->lbl_open_show, SIGNAL(editingFinished()), this, SLOT(edit_open_change()));

    connect(ui->sld_ratio, SIGNAL(valueChanged(int)), this, SLOT(sld_ratio_change(int)));
    connect(ui->lbl_ratio_show, SIGNAL(editingFinished()), this, SLOT(edit_ratio_change()));

    connect(ui->sld_x_scale, SIGNAL(valueChanged(int)), this, SLOT(sld_x_scale_change(int)));
    connect(ui->sld_y_scale, SIGNAL(valueChanged(int)), this, SLOT(sld_y_scale_change(int)));
    connect(ui->sld_y_center, SIGNAL(valueChanged(int)), this, SLOT(sld_y_center_change(int)));
    connect(ui->sld_y_scale_2, SIGNAL(valueChanged(int)), this, SLOT(sld_y_scale_change_2(int)));
    connect(ui->sld_y_center_2, SIGNAL(valueChanged(int)), this, SLOT(sld_y_center_change_2(int)));

    connect(ui->btn_temp_start, SIGNAL(clicked()), this, SLOT(btn_start_click()));
    connect(ui->btn_temp_pause, SIGNAL(clicked()), this, SLOT(btn_pause_click()));
    connect(ui->btn_temp_end, SIGNAL(clicked()), this, SLOT(btn_end_click()));
    connect(ui->btn_duty, SIGNAL(clicked()), this, SLOT(btn_duty_click()));
    connect(ui->btn_open, SIGNAL(clicked()), this, SLOT(btn_open_click()));
    connect(ui->btn_close, SIGNAL(clicked()), this, SLOT(btn_close_click()));

}

Control::~Control()
{
    delete ui;
    if (instantAiCtrl != nullptr)
    {
        instantAiCtrl->Dispose();
    }
    if (instantDiCtrl != nullptr)
    {
        instantDiCtrl->Dispose();
    }
    if (instantDoCtrl != nullptr)
    {
        instantDoCtrl->Dispose();
    }
}

void Control::Initialize()
{
    this->setWindowTitle(tr("Run(") + configure.deviceName + tr(")——DaiQizheng"));

    ConfigureDevice();

    ui->sld_open->setValue(75);
    QString str = tr("");
    str.sprintf("%.2f", ui->sld_open->value()/100.0);
    ui->lbl_open_show->setText(str);
    old_open = ui->sld_open->value()/100.0;

    ui->sld_ratio->setValue(15);
    str.sprintf("%.1f", ui->sld_ratio->value()/10.0);
    ui->lbl_ratio_show->setText(str);
    old_ratio = ui->sld_ratio->value()/10.0;

    str.sprintf("%.2f", 1.0/(1.0+ui->sld_ratio->value()/10.0));
    ui->lbl_ratio_present->setText(str);

    graph_t->m_xCordTimeDiv = (ui->sld_x_scale->value()/10.0) * 1000 / 10;
    graph_t->m_yCordRangeMax = 50;
    graph_t->m_yCordRangeMin = -50;
    m_yCordRangeMid = ui->sld_y_center->value()-150.0;
    graph_t->Clear();
    graph_p->m_xCordTimeDiv = (ui->sld_x_scale->value()/10.0) * 1000 / 10;
    graph_p->m_yCordRangeMax = 1;
    graph_p->m_yCordRangeMin = 0;
    m_yCordRangeMid_2 = ui->sld_y_center_2->value()/1000.0;
    graph_p->Clear();

    ui->btn_duty->setEnabled(true);
    ui->btn_open->setEnabled(true);
    ui->btn_close->setEnabled(true);
    ui->btn_temp_start->setEnabled(true);
    ui->btn_temp_pause->setEnabled(false);
    ui->btn_temp_end->setEnabled(false);

    mode = 1;

    ui->lbl_do_pic->setAutoFillBackground(true);
    QPixmap pixMap_open(":/Resources/open.png");
    QPixmap pixMap_close(":/Resources/close.png");
    QPalette backPalette;
    backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
    ui->lbl_di_pic->setPalette(backPalette);
    ui->lbl_do_pic->setPalette(backPalette);

    ui->listWidget->clear();
    QListWidgetItem *item1 = nullptr;
    for (int i = 0; i < 1; i++)
    {
        item1 = new QListWidgetItem(tr("0.00"), ui->listWidget);
        item1->setBackgroundColor(SimpleGraph::lineColor[0]);
        item1->setSizeHint(QSize(70, 20));
        item1->setTextAlignment(Qt::AlignCenter);
    }
    ui->listWidget_2->clear();
    QListWidgetItem *item2 = nullptr;
    for (int i = 0; i < 1; i++)
    {
        item2 = new QListWidgetItem(tr("0.00"), ui->listWidget_2);
        item2->setBackgroundColor(SimpleGraph::lineColor[1]);
        item2->setSizeHint(QSize(70, 20));
        item2->setTextAlignment(Qt::AlignCenter);
    }
    QFile csvFile(OutputPath);
    QTextStream textStream(&csvFile);
    if (csvFile.open(QIODevice::Text | QIODevice::Append))
    {
        textStream<<"Real-Time Sampling Data"<<"\t"<<"V1"<<"\t"<<"T(Celsius)"<<"\t"<<"V2"<<"\t"<<"P(MPa)"<<"\t"<<"Do"<<endl;
        csvFile.close();
    }
}

void Control::ConfigureDevice()
{
    //Create instant_Ai
    if (instantAiCtrl == nullptr)
    {
      instantAiCtrl = InstantAiCtrl::Create();
    }

    std::wstring description = configure.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());

    ErrorCode errorCodeAi = instantAiCtrl->setSelectedDevice(selected);
    CheckError(errorCodeAi);
    errorCodeAi = instantAiCtrl->LoadProfile(configure.profilePath);
    CheckError(errorCodeAi);

    Array<AiChannel> *channels = instantAiCtrl->getChannels();
    for (int i = 0; i < channels->getCount(); i++)
    {
        channels->getItem(i).setValueRange(configure.valueRange);
    }

    //Create instant_Di
    if (instantDiCtrl == nullptr)
    {
      instantDiCtrl = InstantDiCtrl::Create();
    }
    ErrorCode errorCodeDi = instantDiCtrl->setSelectedDevice(selected);
    CheckError(errorCodeDi);
    errorCodeDi = instantDiCtrl->LoadProfile(configure.profilePath);
    CheckError(errorCodeDi);

    //Create instant_Do
    if (instantDoCtrl == nullptr)
    {
      instantDoCtrl = InstantDoCtrl::Create();
    }
    ErrorCode errorCodeDo = instantDoCtrl->setSelectedDevice(selected);
    CheckError(errorCodeDo);
    errorCodeDo = instantDoCtrl->LoadProfile(configure.profilePath);
    CheckError(errorCodeDo);
}

void Control::CheckError(ErrorCode errorCode)
{
    if (BioFailed(errorCode))
    {
        QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
            QString::number(errorCode, 16).right(8).toUpper();
        QMessageBox::information(this, "Warning Information", message);
    }
}

void Control::TimerTicked()
{
    //Read instant_Ai voltage signals
    ErrorCode errorCode = Success;
    errorCode = instantAiCtrl->Read(configure.channelStart, configure.channelCount, scaledData);
    CheckError(errorCode);
    if (errorCode != Success)
    {
        return;
    }

    //calculate the temperature and pressure frome voltage
    temperature[0] = (scaledData[0]-2.5)*8.0;
    graph_t->Chart(temperature, 1, 1, 10 / 1000.0);
    pressure[0] = scaledData[5]/5.0*6.0;
    graph_p->Chart(pressure, 1, 1, 10 / 1000.0);

    //show the real-time temperature and pressure
    QString str = tr("");
    QListWidgetItem *item;
    QString dataStr = tr("0.00");
    //for(int i = 0; i < 1; i++)
    {
        item = ui->listWidget->item(0);
        str.sprintf("%.2f", temperature[0]);
        dataStr = str;
        if (str.length() > 7)
        {
            dataStr = str.left(7);
        }
        item->setText(dataStr);
    }
    //for(int i = 5; i < 6; i++)
    {
        item = ui->listWidget_2->item(0);
        str.sprintf("%.2f", pressure[0]);
        dataStr = str;
        if (str.length() > 7)
        {
            dataStr = str.left(7);
        }
        item->setText(dataStr);
    }

    //Read and show the status of Di
    QPixmap pixMap_open(":/Resources/open.png");
    QPixmap pixMap_close(":/Resources/close.png");
    QPalette backPalette;
    quint8 *portStates = new quint8[1];
    ErrorCode errorCode2 = Success;
    errorCode2 = instantDiCtrl->Read(0, 1, portStates);
    CheckError(errorCode2);
    datain[0] = *portStates;
    if(datain[0] & 0x01)
    {
        backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
        ui->lbl_di_pic->setPalette(backPalette);
    }
    else
    {
        backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
        ui->lbl_di_pic->setPalette(backPalette);
    }

    //show the current time
    update_time = QDateTime::currentDateTime();
    update_time_string = update_time.toString("yyyy_MM_dd_hh_mm_ss_z");
    ui->lbl_time->setText(update_time.toString("hh")+tr(" : ")+update_time.toString("mm")+tr(" : ")+update_time.toString("ss"));

    //output the time, original voltage, pressure and Do status to txt
    int duty_status;
    if(mode == 1)
        duty_status = 1;
    else if(mode == 3)
        duty_status = 2;
    else
    {
        duty_status = counter_open>0?1:2;
    }

    QString str_v1 = tr("");
    str_v1.sprintf("%.4f", scaledData[0]);
    QString str_v2 = tr("");
    str_v2.sprintf("%.4f", scaledData[5]);
    QString str_t;
    str_t.sprintf("%.4f",temperature[0]);
    QString str_p;
    str_p.sprintf("%.4f",pressure[0]);
    QFile csvFile(OutputPath);
    QTextStream textStream(&csvFile);
    if (csvFile.open(QIODevice::Text | QIODevice::Append))
    {
        textStream<<update_time_string<<"\t"<<str_v1<<"\t"<<str_t<<"\t"<<str_v2<<"\t"<<str_p<<"\t"<<duty_status<<endl;
        csvFile.close();
    }
}

void Control::sld_x_scale_change(int value)
{
    graph_t->m_xCordTimeDiv = (value/10.0) * 1000 / 10;
    graph_p->m_xCordTimeDiv = (value/10.0) * 1000 / 10;

    QString str = tr("");
    str.sprintf("%.1f", ui->sld_x_scale->value()/(1000/100.0));
    ui->lbl_x_present->setText(str+tr("s/格"));
}

void Control::sld_y_scale_change(int value)//for graph_t
{
    graph_t->m_yCordRangeMax = m_yCordRangeMid + value/2.0;
    graph_t->m_yCordRangeMin = m_yCordRangeMid - value/2.0;

    QString str = tr("");
    str.sprintf("%.1f", value*1.0);
    ui->lbl_scale_show->setText(str+tr("℃"));
    str.sprintf("%.1f", graph_t->m_yCordRangeMax);
    ui->lbl_y_max->setText(str+tr("℃"));
    str.sprintf("%.1f", graph_t->m_yCordRangeMin);
    ui->lbl_y_min->setText(str+tr("℃"));
    str.sprintf("%.1f", m_yCordRangeMid);
    ui->lbl_y_mid->setText(str+tr("℃"));
}

void Control::sld_y_scale_change_2(int value)//for graph_p
{
    graph_p->m_yCordRangeMax = m_yCordRangeMid_2 + value/100.0/2.0;
    graph_p->m_yCordRangeMin = m_yCordRangeMid_2 - value/100.0/2.0;

    QString str = tr("");
    str.sprintf("%.2f", value/100.0);
    ui->lbl_scale_show_2->setText(str+tr("MPa"));
    str.sprintf("%.2f", graph_p->m_yCordRangeMax);
    ui->lbl_y_max_2->setText(str+tr("MPa"));
    str.sprintf("%.2f", graph_p->m_yCordRangeMin);
    ui->lbl_y_min_2->setText(str+tr("MPa"));
    str.sprintf("%.2f", m_yCordRangeMid_2);
    ui->lbl_y_mid_2->setText(str+tr("MPa"));
}

void Control::sld_y_center_change(int value)//for graph_t
{
    m_yCordRangeMid = value*1.0-150.0;
    graph_t->m_yCordRangeMax = m_yCordRangeMid + ui->sld_y_scale->value()/2.0;
    graph_t->m_yCordRangeMin = m_yCordRangeMid - ui->sld_y_scale->value()/2.0;

    QString str = tr("");
    str.sprintf("%.1f", value*1.0-150.0);
    ui->lbl_center_show->setText(str+tr("℃"));
    str.sprintf("%.1f", graph_t->m_yCordRangeMax);
    ui->lbl_y_max->setText(str+tr("℃"));
    str.sprintf("%.1f", graph_t->m_yCordRangeMin);
    ui->lbl_y_min->setText(str+tr("℃"));
    str.sprintf("%.1f", m_yCordRangeMid);
    ui->lbl_y_mid->setText(str+tr("℃"));
}

void Control::sld_y_center_change_2(int value)//for graph_p
{
    m_yCordRangeMid_2 = value/1000.0;
    graph_p->m_yCordRangeMax = m_yCordRangeMid_2 + ui->sld_y_scale_2->value()/100.0/2.0;
    graph_p->m_yCordRangeMin = m_yCordRangeMid_2 - ui->sld_y_scale_2->value()/100.0/2.0;

    QString str = tr("");
    str.sprintf("%.2f", value/1000.0);
    ui->lbl_center_show_2->setText(str+tr("MPa"));
    str.sprintf("%.2f", graph_p->m_yCordRangeMax);
    ui->lbl_y_max_2->setText(str+tr("MPa"));
    str.sprintf("%.2f", graph_p->m_yCordRangeMin);
    ui->lbl_y_min_2->setText(str+tr("MPa"));
    str.sprintf("%.2f", m_yCordRangeMid_2);
    ui->lbl_y_mid_2->setText(str+tr("MPa"));
}

void Control::btn_start_click()
{
    timer->start(100);
    timer_control->start(100);
    ui->btn_temp_start->setEnabled(false);
    ui->btn_temp_pause->setEnabled(true);
    ui->btn_temp_end->setEnabled(true);
}

void Control::btn_pause_click()
{
    timer->stop();
    timer_control->stop();
    ui->btn_temp_start->setEnabled(true);
    ui->btn_temp_pause->setEnabled(false);
    ui->btn_temp_end->setEnabled(true);
}

void Control::btn_end_click()
{
    timer->stop();
    timer_control->stop();
    graph_t->Clear();
    graph_p->Clear();
    ui->btn_temp_start->setEnabled(true);
    ui->btn_temp_pause->setEnabled(false);
    ui->btn_temp_end->setEnabled(false);
}

void Control::btn_duty_click()
{
    mode = 2;
    counter_open = qRound((ui->sld_open->value()/100.0)*(1000/100.0));
    counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*(1000/100.0));
}

void Control::btn_open_click()
{
    mode = 1;
}

void Control::btn_close_click()
{
    mode = 3;
}

//Control mode
void Control::DutyControl()
{
    QPixmap pixMap_open(":/Resources/open.png");
    QPixmap pixMap_close(":/Resources/close.png");
    QPalette backPalette;
    if(mode == 1)
    {
        quint8 data_tmp[1];
        data_tmp[0] = 0x01;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &data_tmp[0]);
        CheckError(errorCode);
        backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
        ui->lbl_do_pic->setPalette(backPalette);

    }
    else if (mode == 3)
    {
        quint8 data_tmp[1];
        data_tmp[0] = 0x00;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &data_tmp[0]);
        CheckError(errorCode);
        backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
        ui->lbl_do_pic->setPalette(backPalette);
    }
    else
    {
        quint8 data_tmp[1];
        if(counter_open>0 && counter_close>0)
        {
            counter_open--;
            data_tmp[0] = 0x01;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &data_tmp[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
            ui->lbl_do_pic->setPalette(backPalette);
        }
        else if (counter_open == 0 && counter_close>0)
        {
            counter_close--;
            data_tmp[0] = 0x00;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &data_tmp[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
            ui->lbl_do_pic->setPalette(backPalette);
        }
        else if (counter_open == 0 && counter_close == 0)
        {
            counter_open = qRound((ui->sld_open->value()/100.0)*(1000/100.0));
            counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*(1000/100.0));
        }
        else
        {
            counter_open = qRound((ui->sld_open->value()/100.0)*(1000/100.0));
            counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*(1000/100.0));
        }
        qDebug()<<counter_open<<" and "<<counter_close;

    }
}

void Control::sld_open_change(int value)
{
    QString str = tr("");
    str.sprintf("%.2f", value/100.0);
    ui->lbl_open_show->setText(str);
    old_open = value/100.0;
    counter_open = qRound((ui->sld_open->value()/100.0)*(1000/100.0));
    counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*(1000/100.0));
}

void Control::edit_open_change()
{
    double new_open = ui->lbl_open_show->text().toDouble();
    //qDebug()<<new_open;
    QString str = tr("");
    if(new_open<0.1 || new_open>2)
    {
        new_open = old_open;
    }
    else
    {
        old_open = new_open;
    }
    str.sprintf("%.2f", new_open);
    ui->lbl_open_show->setText(str);
    counter_open = qRound((new_open)*(1000/100.0));
    counter_close = qRound((new_open*old_ratio)*(1000/100.0));
    ui->sld_open->setValue(new_open*100.0+0.55);
    //qDebug()<<new_open;
    //qDebug()<<ui->sld_open->value();
}

void Control::sld_ratio_change(int value)
{
    QString str = tr("");
    str.sprintf("%.1f", value/10.0);
    ui->lbl_ratio_show->setText(str);
    old_ratio = value/10.0;
    str.sprintf("%.2f", 1.0/(1.0+ui->sld_ratio->value()/10.0));
    ui->lbl_ratio_present->setText(str);
    counter_open = qRound((ui->sld_open->value()/100.0)*(1000/100.0));
    counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*(1000/100.0));
}

void Control::edit_ratio_change()
{
    double new_ratio = ui->lbl_ratio_show->text().toDouble();
    //qDebug()<<new_open;
    QString str = tr("");
    if(new_ratio<0 || new_ratio>10)
    {
        new_ratio = old_open;
    }
    else
    {
        old_open = new_ratio;
    }
    str.sprintf("%.1f", new_ratio);
    ui->lbl_ratio_show->setText(str);
    str.sprintf("%.2f", 1.0/(1.0+new_ratio));
    counter_open = qRound((old_open)*(1000/100.0));
    counter_close = qRound((old_open*new_ratio)*(1000/100.0));
    ui->sld_ratio->setValue(new_ratio*10.0+0.55);
    //qDebug()<<new_ratio;
    //qDebug()<<ui->sld_ratio->value();
}

