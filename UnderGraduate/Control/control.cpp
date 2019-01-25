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
    connect(ui->sld_ratio, SIGNAL(valueChanged(int)), this, SLOT(sld_ratio_change(int)));
    connect(ui->sld_x_scale, SIGNAL(valueChanged(int)), this, SLOT(sld_x_scale_change(int)));
    //connect(ui->sld_x_center,SIGNAL(valueChanged(int)),this,SLOT(sld_x_center_change(int)));
    connect(ui->sld_y_scale, SIGNAL(valueChanged(int)), this, SLOT(sld_y_scale_change(int)));
    connect(ui->sld_y_center, SIGNAL(valueChanged(int)), this, SLOT(sld_y_center_change(int)));
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
    ui->lbl_open_show->setText(str+tr("s"));

    ui->sld_ratio->setValue(15);
    str.sprintf("%.1f", ui->sld_ratio->value()/10.0);
    ui->lbl_ratio_show->setText(str);

    str.sprintf("%.2f", 1.0/(1.0+ui->sld_ratio->value()/10.0));
    ui->lbl_ratio_present->setText(str);

    graph_t->m_xCordTimeDiv = (ui->sld_x_scale->value()/10.0) * 1000 / 10;
    graph_t->m_yCordRangeMax = 50;
    graph_t->m_yCordRangeMin = -50;
    m_yCordRangeMid = ui->sld_y_center->value()-150.0;
    graph_t->Clear();
    graph_p->m_xCordTimeDiv = (ui->sld_x_scale->value()/10.0) * 1000 / 10;
    graph_p->m_yCordRangeMax = 50;
    graph_p->m_yCordRangeMin = -50;
    m_yCordRangeMid_2 = ui->sld_y_center_2->value()-50.0;
    graph_p->Clear();


    str.sprintf("%.1f", ui->sld_y_scale->value()*1.0);
    ui->lbl_scale_show->setText(str+tr("℃"));
    str.sprintf("%.1f", ui->sld_y_center->value()*1.0-150.0);
    ui->lbl_center_show->setText(str+tr("℃"));
    str.sprintf("%.1f", graph_t->m_yCordRangeMax);
    ui->lbl_y_max->setText(str+tr("℃"));
    str.sprintf("%.1f", graph_t->m_yCordRangeMin);
    ui->lbl_y_min->setText(str+tr("℃"));
    str.sprintf("%.1f", m_yCordRangeMid);
    ui->lbl_y_mid->setText(str+tr("℃"));
    str.sprintf("%.1f", ui->sld_x_scale->value()/100.0);
    ui->lbl_x_present->setText(str+tr("s/格"));

    ui->btn_duty->setEnabled(true);
    ui->btn_open->setEnabled(true);
    ui->btn_close->setEnabled(true);
    ui->btn_temp_start->setEnabled(true);
    ui->btn_temp_pause->setEnabled(false);
    ui->btn_temp_end->setEnabled(false);

    mode = 1;

    ui->lbl_status_pic->setAutoFillBackground(true);
    QPixmap pixMap_open(":/Resources/open.png");
    QPixmap pixMap_close(":/Resources/close.png");
    QPalette backPalette;
    backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
    ui->lbl_di_pic->setPalette(backPalette);
    ui->lbl_status_pic->setPalette(backPalette);

    ui->listWidget->clear();
    //ui->listWidget_click->clear();
    QListWidgetItem *item1 = nullptr;
    for (int i = 0; i < 4; i++)
    {
        item1 = new QListWidgetItem(tr("0.00"), ui->listWidget);
        item1->setBackgroundColor(SimpleGraph::lineColor[i]);
        item1->setSizeHint(QSize(50, 20));
        item1->setTextAlignment(Qt::AlignCenter);
    }
    ui->listWidget_2->clear();
    QListWidgetItem *item2 = nullptr;
    for (int i = 0; i < 2; i++)
    {
        item2 = new QListWidgetItem(tr("0.00"), ui->listWidget_2);
        item2->setBackgroundColor(SimpleGraph::lineColor[i]);
        item2->setSizeHint(QSize(50, 20));
        item2->setTextAlignment(Qt::AlignCenter);
    }
    /*
    QListWidgetItem *item2 = nullptr;
    for (int i = 0; i < configure.channelCount; i++)
    {
        item2 = new QListWidgetItem(tr("0.00"), ui->listWidget_click);
        item2->setBackgroundColor(SimpleGraph::lineColor[i]);
        item2->setSizeHint(QSize(50, 20));
        item2->setTextAlignment(Qt::AlignCenter);
    }*/
    QFile csvFile(OutputPath);
    csvFile.remove();

    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");
    qDebug()<<current_date;
}

void Control::ConfigureDevice()
{
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

    if (instantDiCtrl == nullptr)
    {
      instantDiCtrl = InstantDiCtrl::Create();
    }
    ErrorCode errorCodeDi = instantDiCtrl->setSelectedDevice(selected);
    CheckError(errorCodeDi);
    errorCodeDi = instantDiCtrl->LoadProfile(configure.profilePath);
    CheckError(errorCodeDi);

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
    ErrorCode errorCode = Success;
    errorCode = instantAiCtrl->Read(configure.channelStart, configure.channelCount, scaledData);
    CheckError(errorCode);
    if (errorCode != Success)
    {
        return;
    }

    Time_total = Time_total+0.01;
    QString str = tr("");
    str.sprintf("%.2f", Time_total);
    ui->lbl_time->setText(str+tr("s"));

    temperature[0] = 1000.0*(scaledData[0]-scaledData[1]);
    //temperature[1] = scaledData[0];
    //temperature[2] = scaledData[2];
    graph_t->Chart(scaledData, 4, 1, 10 / 1000.0);

    //graph_t->Chart(temperature, 1, 1, 10 / 1000.0);
    //graph_t->Chart(scaledData, 4, 1, 10 / 1000.0);
    pressure[0] = scaledData[4];
    pressure[1] = scaledData[5];
    graph_p->Chart(pressure, 2, 1, 10 / 1000.0);

    //graph->Chart(temperature, 1, 1, 10 / 1000.0);

    QListWidgetItem *item;
    QString dataStr = tr("0.00");
    for(int i = 0; i < 4; i++)
    {
        item = ui->listWidget->item(i);
        str.sprintf("%.2f", scaledData[i]);
        dataStr = str;
        if (str.length() > 7)
        {
            dataStr = str.left(7);
        }
        item->setText(dataStr);
    }
    for(int i = 0; i < 2; i++)
    {
        item = ui->listWidget_2->item(i);
        str.sprintf("%.2f", pressure[i]);
        dataStr = str;
        if (str.length() > 7)
        {
            dataStr = str.left(7);
        }
        item->setText(dataStr);
    }

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



    int duty_status;
    if(mode == 1)
        duty_status = 1;
    else if(mode == 3)
        duty_status = 2;
    else
    {
        duty_status = counter_open>0?1:2;
    }
    str.sprintf("%.4f", scaledData[0]);
    qDebug()<<scaledData[0];
    qDebug()<<duty_status;
    QFile csvFile(OutputPath);
    QTextStream textStream(&csvFile);
    if (csvFile.open(QIODevice::Text | QIODevice::Append))
    {
        textStream<<str<<"\t"<<duty_status<<endl;
        csvFile.close();
    }
}


void Control::sld_open_change(int value)
{
    QString str = tr("");
    str.sprintf("%.2f", value/100.0);
    ui->lbl_open_show->setText(str+tr("s"));
    counter_open = qRound((ui->sld_open->value()/100.0)*100);
    counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*100);
}

void Control::sld_ratio_change(int value)
{
    QString str = tr("");
    str.sprintf("%.1f", value/10.0);
    ui->lbl_ratio_show->setText(str);
    str.sprintf("%.2f", 1.0/(1.0+ui->sld_ratio->value()/10.0));
    ui->lbl_ratio_present->setText(str);
    counter_open = qRound((ui->sld_open->value()/100.0)*100);
    counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*100);
}

void Control::sld_x_scale_change(int value)
{
    graph_t->m_xCordTimeDiv = (value/10.0) * 1000 / 10;
    graph_p->m_xCordTimeDiv = (value/10.0) * 1000 / 10;

    QString str = tr("");
    str.sprintf("%.1f", ui->sld_x_scale->value()/100.0);
    ui->lbl_x_present->setText(str+tr("s/格"));
}
/*
void Control::sld_x_center_change(int value)
{

}
*/
void Control::sld_y_scale_change(int value)
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

void Control::sld_y_center_change(int value)
{
    m_yCordRangeMid = value*1.0-150.0;
    graph_t->m_yCordRangeMax = m_yCordRangeMid + ui->sld_y_scale->value()/2.0;
    graph_t->m_yCordRangeMin = m_yCordRangeMid - ui->sld_y_scale->value()/2.0;

    QString str = tr("");
    str.sprintf("%.1f", value*1.0-150);
    ui->lbl_center_show->setText(str+tr("℃"));
    str.sprintf("%.1f", graph_t->m_yCordRangeMax);
    ui->lbl_y_max->setText(str+tr("℃"));
    str.sprintf("%.1f", graph_t->m_yCordRangeMin);
    ui->lbl_y_min->setText(str+tr("℃"));
    str.sprintf("%.1f", m_yCordRangeMid);
    ui->lbl_y_mid->setText(str+tr("℃"));
}

void Control::btn_start_click()
{
    timer->start(10);
    timer_control->start(10);
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
    counter_open = qRound((ui->sld_open->value()/100.0)*100);
    counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*100);
}

void Control::btn_open_click()
{
    mode = 1;
}

void Control::btn_close_click()
{
    mode = 3;
}

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
        ui->lbl_status_pic->setPalette(backPalette);

    }
    else if (mode == 3)
    {
        quint8 data_tmp[1];
        data_tmp[0] = 0x00;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &data_tmp[0]);
        CheckError(errorCode);
        backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
        ui->lbl_status_pic->setPalette(backPalette);
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
            ui->lbl_status_pic->setPalette(backPalette);
        }
        else if (counter_open == 0 && counter_close>0)
        {
            counter_close--;
            data_tmp[0] = 0x00;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &data_tmp[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
            ui->lbl_status_pic->setPalette(backPalette);
        }
        else if (counter_open == 0 && counter_close == 0)
        {
            counter_open = qRound((ui->sld_open->value()/100.0)*100);
            counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*100);
        }
        else
        {
            counter_open = qRound((ui->sld_open->value()/100.0)*100);
            counter_close = qRound((ui->sld_open->value()*ui->sld_ratio->value()/1000.0)*100);
        }
        qDebug()<<counter_open<<" and "<<counter_close;

    }
}

