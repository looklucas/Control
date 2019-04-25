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
    instantDoCtrl = nullptr;

    graph_t = new SimpleGraph(ui->graphFrame);
    graph_t->setFixedSize(ui->graphFrame->size());
    graph_p = new SimpleGraph(ui->graphFrame_2);
    graph_p->setFixedSize(ui->graphFrame_2->size());

    for (int i = 0; i < 16; i++)
    {
        scaledData[i] = 0;
    }

    //create timers
    timer = new QTimer(this);
    timer_control = new QTimer(this);
    timer_control_2 = new QTimer(this);
    timer_flow = new QTimer(this);

    //control the graph
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerTicked()));
    connect(ui->sld_x_scale, SIGNAL(valueChanged(int)), this, SLOT(sld_x_scale_change(int)));
    connect(ui->sld_y_scale, SIGNAL(valueChanged(int)), this, SLOT(sld_y_scale_change(int)));
    connect(ui->sld_y_center, SIGNAL(valueChanged(int)), this, SLOT(sld_y_center_change(int)));
    connect(ui->sld_y_scale_2, SIGNAL(valueChanged(int)), this, SLOT(sld_y_scale_change_2(int)));
    connect(ui->sld_y_center_2, SIGNAL(valueChanged(int)), this, SLOT(sld_y_center_change_2(int)));

    //control the valve 1
    connect(timer_control, SIGNAL(timeout()), this, SLOT(DutyControl()));
    connect(ui->sld_cycle, SIGNAL(valueChanged(int)), this, SLOT(sld_cycle_change(int)));
    connect(ui->lbl_cycle_show, SIGNAL(editingFinished()), this, SLOT(edit_cycle_change()));
    connect(ui->sld_ratio, SIGNAL(valueChanged(int)), this, SLOT(sld_ratio_change(int)));
    connect(ui->lbl_ratio_show, SIGNAL(editingFinished()), this, SLOT(edit_ratio_change()));
    connect(ui->btn_duty, SIGNAL(clicked()), this, SLOT(btn_duty_click()));
    connect(ui->btn_open, SIGNAL(clicked()), this, SLOT(btn_open_click()));
    connect(ui->btn_close, SIGNAL(clicked()), this, SLOT(btn_close_click()));

    //control the valve 2
    connect(timer_control_2, SIGNAL(timeout()), this, SLOT(DutyControl_2()));
    connect(ui->sld_cycle_2, SIGNAL(valueChanged(int)), this, SLOT(sld_cycle_change_2(int)));
    connect(ui->lbl_cycle_show_2, SIGNAL(editingFinished()), this, SLOT(edit_cycle_change_2()));
    connect(ui->sld_ratio_2, SIGNAL(valueChanged(int)), this, SLOT(sld_ratio_change_2(int)));
    connect(ui->lbl_ratio_show_2, SIGNAL(editingFinished()), this, SLOT(edit_ratio_change_2()));
    connect(ui->btn_duty_2, SIGNAL(clicked()), this, SLOT(btn_duty_click_2()));
    connect(ui->btn_open_2, SIGNAL(clicked()), this, SLOT(btn_open_click_2()));
    connect(ui->btn_close_2, SIGNAL(clicked()), this, SLOT(btn_close_click_2()));
    connect(ui->btn_auto, SIGNAL(clicked()), this, SLOT(btn_auto_click()));
    connect(ui->cmb_t, SIGNAL(currentIndexChanged(int)), this, SLOT(Auto_T_Changed(int)));

    //control the sampling
    connect(ui->btn_temp_start, SIGNAL(clicked()), this, SLOT(btn_start_click()));
    connect(ui->btn_temp_pause, SIGNAL(clicked()), this, SLOT(btn_pause_click()));
    connect(ui->btn_temp_end, SIGNAL(clicked()), this, SLOT(btn_end_click()));

    //control the communication
    connect(ui->cmb_port, SIGNAL(currentIndexChanged(int)), this, SLOT(PortChanged()));
    connect(timer_flow, SIGNAL(timeout()), this, SLOT(ReadFlow()));
}

Control::~Control()
{
    delete ui;
    if (instantAiCtrl != nullptr)
    {
        instantAiCtrl->Dispose();
    }
    if (instantDoCtrl != nullptr)
    {
        instantDoCtrl->Dispose();
    }
    if(flow_port->isOpen())
    {
        flow_port->clear();
        flow_port->close();
        flow_port->deleteLater();
        qDebug()<<"flow_port has been closed !";
    }
}

void Control::Initialize()
{
    this->setWindowTitle(tr("Run(") + configure.deviceName + tr(")——DaiQizheng"));

    ConfigureDevice();

    QString str = tr("");

    dataout[0] = 0xFF;

    //initialize the valve 1
    timer_control_interval = 10;
    ui->sld_cycle->setValue(10);
    str.sprintf("%.1f", ui->sld_cycle->value()/10.0);
    ui->lbl_cycle_show->setText(str);
    ui->sld_ratio->setValue(10);
    str.sprintf("%.1f", ui->sld_ratio->value()/10.0);
    ui->lbl_ratio_show->setText(str);
    str.sprintf("%.4f", 1.0/(1.0+ui->sld_ratio->value()/10.0));
    ui->lbl_ratio_present->setText(str);
    old_cycle = ui->sld_cycle->value()/10.0;
    old_ratio = ui->sld_ratio->value()/10.0;
    ui->btn_duty->setEnabled(true);
    ui->btn_open->setEnabled(true);
    ui->btn_close->setEnabled(true);
    mode = 1;

    //initialize the valve 2
    timer_control_interval_2 = 10;
    ui->sld_cycle_2->setValue(10);
    str.sprintf("%.1f", ui->sld_cycle_2->value()/10.0);
    ui->lbl_cycle_show_2->setText(str);
    ui->sld_ratio_2->setValue(10);
    str.sprintf("%.1f", ui->sld_ratio_2->value()/10.0);
    ui->lbl_ratio_show_2->setText(str);
    str.sprintf("%.4f", 1.0/(1.0+ui->sld_ratio_2->value()/10.0));
    ui->lbl_ratio_present_2->setText(str);
    old_cycle_2 = ui->sld_cycle_2->value()/10.0;
    old_ratio_2 = ui->sld_ratio_2->value()/10.0;
    ui->btn_duty_2->setEnabled(true);
    ui->btn_open_2->setEnabled(true);
    ui->btn_close_2->setEnabled(true);
    mode_2 = 1;
    auto_activate = false;
    ui->btn_auto->setEnabled(auto_activate);
    ui->cmb_t->setEnabled(auto_activate);
    auto_stable = false;
    first_temperature = true;
    cmp_t = ui->cmb_t->currentIndex() * (-10.0) - 10.0;
    cmp_t_win_width = 2;
    cmp_t_win_h = cmp_t + cmp_t_win_width/2.0;
    cmp_t_win_l = cmp_t - cmp_t_win_width/2.0;
    //qDebug()<<"cmb_t index = "<<ui->cmb_t->currentIndex();

    //graph set
    timer_interval = 10;
    show_count = 0;
    temperature[0] = 20;
    pressure[0] = 0;
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

    //functional button
    ui->btn_temp_start->setEnabled(true);
    ui->btn_temp_pause->setEnabled(false);
    ui->btn_temp_end->setEnabled(false);

    //digital output
    ui->lbl_do_pic->setAutoFillBackground(true);
    ui->lbl_do_pic_2->setAutoFillBackground(true);
    QPixmap pixMap_open(":/Resources/open.png");
    QPalette backPalette;
    backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
    ui->lbl_do_pic->setPalette(backPalette);
    ui->lbl_do_pic_2->setPalette(backPalette);

    //real-time value show
    ui->listWidget->clear();
    QListWidgetItem *item_t = nullptr;
    for (int i = 0; i < 1; i++)
    {
        item_t = new QListWidgetItem(tr("0.00"), ui->listWidget);
        item_t->setBackgroundColor(SimpleGraph::lineColor[0]);
        item_t->setSizeHint(QSize(70, 20));
        item_t->setTextAlignment(Qt::AlignCenter);
    }
    ui->listWidget_2->clear();
    QListWidgetItem *item_p = nullptr;
    for (int i = 0; i < 1; i++)
    {
        item_p = new QListWidgetItem(tr("0.000"), ui->listWidget_2);
        item_p->setBackgroundColor(SimpleGraph::lineColor[1]);
        item_p->setSizeHint(QSize(70, 20));
        item_p->setTextAlignment(Qt::AlignCenter);
    }
    ui->listWidget_3->clear();
    QListWidgetItem *item_f = nullptr;
    for (int i = 0; i < 1; i++)
    {
        item_f = new QListWidgetItem(tr("0.000"), ui->listWidget_3);
        item_f->setBackgroundColor(SimpleGraph::lineColor[2]);
        item_f->setSizeHint(QSize(70, 20));
        item_f->setTextAlignment(Qt::AlignCenter);
    }

    flow_port = new QSerialPort(this);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Name        : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        ui->cmb_port->addItem(info.portName());
    }
    flow_port->setPortName(ui->cmb_port->currentText());
    command1.resize(1);
    command2.resize(1);
    command1[0] = (char)0x9D;
    command2[0] = (char)0x54;

    //create txt file to save data
    QFile csvFile(OutputPath);
    QTextStream textStream(&csvFile);
    if (csvFile.open(QIODevice::Text | QIODevice::Append))
    {
        textStream<<"Real-Time Sampling Data"
                  <<"\t"<<"V1"<<"\t"<<"T(Celsius)"
                  <<"\t"<<"V2"<<"\t"<<"P(MPa)"
                  <<"\t"<<"Do_1"<<"\t"<<"Cycle(s)"<<"\t"<<"Ratio"
                  <<"\t"<<"Do_2"<<"\t"<<"Cycle(s)"<<"\t"<<"Ratio"
                  <<"\t"<<"Flow(L/min)"<<endl;
        csvFile.close();
    }
    str_v1 = tr("");
    str_t = tr("");
    str_v2 = tr("");
    str_p = tr("");
    str_cycle = tr("");
    str_ratio = tr("");
    str_cycle_2 = tr("");
    str_ratio_2 = tr("");
    str_f = "waiting...";
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

void Control::PortChanged()
{
    //qDebug()<<"port changed";

    if(flow_port->isOpen())
    {
        flow_port->close();
    }

    flow_port->setPortName(ui->cmb_port->currentText());
    //open port
    if(flow_port->open(QIODevice::ReadWrite))
    {
        //set baudrate
        flow_port->setBaudRate(57600);
        //set data bits
        flow_port->setDataBits(QSerialPort::Data8);
        //set parity
        flow_port->setParity(QSerialPort::NoParity);
        //set stop bits
        flow_port->setStopBits(QSerialPort::OneStop);
        //set flow control
        flow_port->setFlowControl(QSerialPort::NoFlowControl);
    }
    else
    {
        QMessageBox::about(nullptr, "warning", "流量测量串口没有打开！");
        return;
    }
    str_f = "waiting...";
}

void Control::ReadFlow()
{
    QByteArray read_flow;
    read_flow.clear();
    if(flow_port->isOpen())
    {
        qDebug()<<"flow_port is open ! ";
        read_flow = flow_port->readAll();
        if(!read_flow.isEmpty())
        {
            str_f=(read_flow);
            qDebug()<<"str_f = "<<str_f;
            int strStartIndex = str_f.indexOf('F');
            //qDebug()<<"start index :" <<strStartIndex;
            int strEndIndex = str_f.indexOf('A');
            //qDebug()<<"end index:" <<strEndIndex;
            str_f = str_f.mid(strStartIndex+3, strEndIndex-strStartIndex-4);
            double tmp = str_f.toDouble()/1000.0;
            str_f.sprintf("%.3f",tmp);
            read_flow.clear();
        }
        else
        {
            //try to communicaiton
            flow_port->write(command1,1);
            qDebug()<<"Send 0x9D";
            QTime reach = QTime::currentTime().addMSecs(100);
            while (QTime::currentTime() < reach)
            {
                QCoreApplication::processEvents(QEventLoop::AllEvents);
            }
            qDebug()<<"receive : "<<flow_port->readAll();

            flow_port->write(command2,1);
            qDebug()<<"Send 0x54";
            reach = QTime::currentTime().addMSecs(100);
            while (QTime::currentTime() < reach)
            {
                QCoreApplication::processEvents(QEventLoop::AllEvents);
            }
            qDebug()<<"receive : "<<flow_port->readAll();
        }
    }
}

void Control::TimerTicked()
{
    //Read ports and calculate values
    /*-----------------------------------------------------------------------------------------*/
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
    temperature_before = temperature[0];
    temperature[0] = (scaledData[0]*13.2185-65.1768);
    if(first_temperature)
    {
        /*
        for(int i = 0; i < 3 ; i++)
        {
            temperature_save[i] = temperature[0];
        }
        temperature_average = temperature[0];
        */
        temperature_before = temperature[0];
        first_temperature = false;
    }
    /*
    memcpy(temperature_before,temperature_save,3);
    temperature_before_average = temperature_average;
    for(int i = 0; i < 2 ; i++)
    {
        temperature_save[i] = temperature_save[i+1];
    }

    if(fabs(temperature[0] - temperature_save[8] ) > 20)
    {
        temperature_save[9] = temperature_save[8];
    }
    else
    {
        temperature_save[2] = temperature[0];
    }
    temperature_average = (temperature_save[2] +temperature_save[1]+temperature_save[0])/3.0;
    //qDebug()<<"temperature_before_average = "<<temperature_before_average;
    //qDebug()<<"temperature_average = "<<temperature_average;
    */
    pressure[0] = scaledData[5]/5.0*6.0-0.064013;

    //activate the auto control function when the temperature is low enough
    //activate only once
    if((!auto_activate) && (temperature[0]<-100))
    {
        auto_activate = true;
        ui->btn_auto->setEnabled(auto_activate);
        ui->cmb_t->setEnabled(auto_activate);
    }

    }/*----------------------------------------------------------------------------------------*/

    //show the time, temperature, pressure and flow value
    /*----------------------------------------------------------------------------------------*/
    {
    update_time = QDateTime::currentDateTime();
    update_time_string = update_time.toString("yyyy_MM_dd_hh_mm_ss_z");
    ui->lbl_time->setText(update_time.toString("hh")+tr(" : ")+update_time.toString("mm")+tr(" : ")+update_time.toString("ss"));

    QString str = tr("");
    QListWidgetItem *item;
    QString dataStr = tr("0.00");
    
    if(show_count == 0)
    {
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
        //item->setText(tr(""));
        //for(int i = 5; i < 6; i++)
        {
            item = ui->listWidget_2->item(0);
            str.sprintf("%.3f", pressure[0]);
            dataStr = str;
            if (str.length() > 7)
            {
                dataStr = str.left(7);
            }
            item->setText(dataStr);
        }
        //show real-time flow
        {
            item = ui->listWidget_3->item(0);
            dataStr = str_f;
            if (str_f.length() > 7)
            {
                dataStr = str_f.left(7);
            }
            item->setText(dataStr);
        }
        graph_t->Chart(temperature, 1, 1, timer_interval * 10 / 10.0 / 1000.0);
        graph_p->Chart(pressure, 1, 1, timer_interval * 10 / 10.0/ 1000.0);
    }
    show_count = (show_count + 1) % 10;
    
    }/*---------------------------------------------------------------------------------------*/

    //output the time, original voltage, pressure and Do status to txt file
    /*----------------------------------------------------------------------------------------*/
    {
    int duty_status;
    int duty_status_2;
    if(dataout[0] & 0x01)
    {
        duty_status = 1;
    }
    else
    {
        duty_status = 2;
    }
    if(dataout[0] & 0x10)
    {
        duty_status_2 = 1;
    }
    else
    {
        duty_status_2 = 2;
    }

    str_v1.sprintf("%.3f", scaledData[0]);
    str_t.sprintf("%.2f",temperature[0]);
    str_v2.sprintf("%.4f", scaledData[5]);
    str_p.sprintf("%.4f",pressure[0]);
    str_cycle.sprintf("%.1f",ui->sld_cycle->value()/10.0);
    str_ratio.sprintf("%.2f", 1.0/(1.0+ui->sld_ratio->value()/10.0));
    str_cycle_2.sprintf("%.1f",ui->sld_cycle_2->value()/10.0);
    str_ratio_2.sprintf("%.2f", 1.0/(1.0+ui->sld_ratio_2->value()/10.0));

    QFile csvFile(OutputPath);
    QTextStream textStream(&csvFile);
    if (show_count==1 && csvFile.open(QIODevice::Text | QIODevice::Append))
    {
        textStream<<update_time_string
                  <<"\t"<<str_v1<<"\t"<<str_t
                  <<"\t"<<str_v2<<"\t"<<str_p
                  <<"\t"<<duty_status<<"\t"<<str_cycle<<"\t"<<str_ratio
                  <<"\t"<<duty_status_2<<"\t"<<str_cycle_2<<"\t"<<str_ratio_2
                  <<"\t"<<str_f<<endl;
        csvFile.close();
    }
    }
    /*----------------------------------------------------------------------------------------*/
}

void Control::sld_x_scale_change(int value)
{
    graph_t->m_xCordTimeDiv = (value/10.0) * 1000 / 10;
    graph_p->m_xCordTimeDiv = (value/10.0) * 1000 / 10;

    QString str = tr("");
    str.sprintf("%.1f", ui->sld_x_scale->value()/10.0);
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
    timer->start(timer_interval);
    timer_control->start(timer_control_interval);
    timer_control_2->start(timer_control_interval_2);
    timer_flow->start(4000);//every 4s read flow
    ui->btn_temp_start->setEnabled(false);
    ui->btn_temp_pause->setEnabled(true);
    ui->btn_temp_end->setEnabled(true);
}

void Control::btn_pause_click()
{
    timer->stop();
    timer_control->stop();
    timer_control_2->stop();
    timer_flow->stop();
    ui->btn_temp_start->setEnabled(true);
    ui->btn_temp_pause->setEnabled(false);
    ui->btn_temp_end->setEnabled(true);
}

void Control::btn_end_click()
{
    timer->stop();
    timer_control->stop();
    timer_control_2->stop();
    timer_flow->stop();
    graph_t->Clear();
    graph_p->Clear();
    ui->btn_temp_start->setEnabled(true);
    ui->btn_temp_pause->setEnabled(false);
    ui->btn_temp_end->setEnabled(false);
}

void Control::btn_duty_click()
{
    mode = 2;
    counter_open = qRound(((ui->sld_cycle->value()/10.0)*1/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
    counter_close = qRound(((ui->sld_cycle->value()/10.0)*(ui->sld_ratio->value()/10.0)/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
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
        dataout[0] = dataout[0] | 0x01;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
        CheckError(errorCode);
        backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
        ui->lbl_do_pic->setPalette(backPalette);    }
    else if (mode == 3)
    {
        dataout[0] = dataout[0] & 0xFE;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
        CheckError(errorCode);
        backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
        ui->lbl_do_pic->setPalette(backPalette);
    }
    else
    {
        if(counter_open>0 && counter_close>1)
        {
            counter_open--;
            dataout[0] = dataout[0] | 0x01;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
            ui->lbl_do_pic->setPalette(backPalette);
        }
        else if (counter_open == 0 && counter_close>1)
        {
            counter_close--;
            dataout[0] = dataout[0] & 0xFE;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
            ui->lbl_do_pic->setPalette(backPalette);
        }
        else if (counter_open == 0 && counter_close == 1)
        {
            counter_open = qRound(((ui->sld_cycle->value()/10.0)*1/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
            counter_close = qRound(((ui->sld_cycle->value()/10.0)*(ui->sld_ratio->value()/10.0)/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
        }
        else
        {
            counter_open = qRound(((ui->sld_cycle->value()/10.0)*1/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
            counter_close = qRound(((ui->sld_cycle->value()/10.0)*(ui->sld_ratio->value()/10.0)/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
        }
        update_time = QDateTime::currentDateTime();
        update_time_string = update_time.toString("yyyy_MM_dd_hh_mm_ss_z");
        //qDebug()<<counter_open<<" and "<<counter_close<<"   Time: "<<update_time_string;
    }
}

void Control::sld_cycle_change(int value)
{
    QString str = tr("");
    str.sprintf("%.1f", value/10.0);
    ui->lbl_cycle_show->setText(str);
    old_cycle = value/10.0;
    counter_open = qRound(((ui->sld_cycle->value()/10.0)*1/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
    counter_close = qRound(((ui->sld_cycle->value()/10.0)*(ui->sld_ratio->value()/10.0)/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
}

void Control::edit_cycle_change()
{
    double new_cycle = ui->lbl_cycle_show->text().toDouble();
    //qDebug()<<new_open;
    QString str = tr("");
    if(new_cycle<0.1 || new_cycle>50)
    {
        new_cycle = old_cycle;
    }
    str.sprintf("%.1f", new_cycle);
    ui->lbl_cycle_show->setText(str);
    ui->sld_cycle->setValue(new_cycle*10.0+0.55);
    //qDebug()<<ui->sld_cycle->value();
    counter_open = qRound(((ui->sld_cycle->value()/10.0)*1/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
    counter_close = qRound(((ui->sld_cycle->value()/10.0)*(ui->sld_ratio->value()/10.0)/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
    old_cycle = new_cycle;
    //qDebug()<<new_open;
    //qDebug()<<ui->sld_open->value();
}

void Control::sld_ratio_change(int value)
{
    QString str = tr("");
    str.sprintf("%.1f", value/10.0);
    ui->lbl_ratio_show->setText(str);
    old_ratio = value/10.0;
    str.sprintf("%.4f", 1.0/(1.0+ui->sld_ratio->value()/10.0));
    ui->lbl_ratio_present->setText(str);
    counter_open = qRound(((ui->sld_cycle->value()/10.0)*1/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
    counter_close = qRound(((ui->sld_cycle->value()/10.0)*(ui->sld_ratio->value()/10.0)/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
}

void Control::edit_ratio_change()
{
    double new_ratio = ui->lbl_ratio_show->text().toDouble();
    //qDebug()<<new_open;
    QString str = tr("");
    if(new_ratio<0 || new_ratio>20)
    {
        new_ratio = old_ratio;
    }
    str.sprintf("%.1f", new_ratio);
    ui->lbl_ratio_show->setText(str);
    str.sprintf("%.2f", 1.0/(1.0+new_ratio));
    ui->sld_ratio->setValue(new_ratio*10.0+0.55);
    counter_open = qRound(((ui->sld_cycle->value()/10.0)*1/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
    counter_close = qRound(((ui->sld_cycle->value()/10.0)*(ui->sld_ratio->value()/10.0)/(ui->sld_ratio->value()/10.0+1))*(1000.0/timer_control_interval));
    old_ratio = new_ratio;
    //qDebug()<<new_ratio;
    //qDebug()<<ui->sld_ratio->value();
}

void Control::btn_duty_click_2()
{
    mode_2 = 2;
    counter_open_2 = qRound(((ui->sld_cycle_2->value()/10.0)*1/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
    counter_close_2 = qRound(((ui->sld_cycle_2->value()/10.0)*(ui->sld_ratio_2->value()/10.0)/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
}

void Control::btn_open_click_2()
{
    mode_2 = 1;
}

void Control::btn_close_click_2()
{
    mode_2 = 3;
}

void Control::DutyControl_2()
{
    //mode 1: keep open
    //mode 2: control
    //mode 3: keep close

    QPixmap pixMap_open(":/Resources/open.png");
    QPixmap pixMap_close(":/Resources/close.png");
    QPalette backPalette;
    if(auto_stable)
    {

        qDebug()<<"dataout[0] = "<<dataout[0];
        qDebug()<<"temperature_before_average during auto = "<<temperature_before;
        qDebug()<<"temperature_average during auto = "<<temperature[0];
        qDebug()<<"cmp_t_h = "<<cmp_t_win_h;
        qDebug()<<"cmp_t_l = "<<cmp_t_win_l;

        if( temperature[0] > cmp_t_win_h)
        {
            dataout[0] = dataout[0] | 0x10;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
            ui->lbl_do_pic_2->setPalette(backPalette);
        }
        else if (temperature[0] < cmp_t_win_l)
        {
            dataout[0] = dataout[0] & 0xEF;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
            ui->lbl_do_pic_2->setPalette(backPalette);
        }
        else
        {
            if(temperature_before > cmp_t_win_h)
            {
            dataout[0] = dataout[0] & 0xEF;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
            ui->lbl_do_pic_2->setPalette(backPalette);
            }
            else if(temperature_before < cmp_t_win_l)
            {
            dataout[0] = dataout[0] | 0x10;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
            ui->lbl_do_pic_2->setPalette(backPalette);
            }
            else
            {
                return;
            }
        }
    }
    else
    {
        if(mode_2 == 1)
        {
            dataout[0] = dataout[0] | 0x10;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
            ui->lbl_do_pic_2->setPalette(backPalette);
        }
        else if (mode_2 == 3)
        {
            dataout[0] = dataout[0] & 0xEF;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
            ui->lbl_do_pic_2->setPalette(backPalette);
        }
        else//mode_2 == 2
        {
            if(counter_open_2>0 && counter_close_2>1)
            {
                counter_open_2--;
                dataout[0] = dataout[0] | 0x10;
                ErrorCode errorCode = Success;
                errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
                CheckError(errorCode);
                backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
                ui->lbl_do_pic_2->setPalette(backPalette);
            }
            else if (counter_open_2 == 0 && counter_close_2>1)
            {
                counter_close_2--;
                dataout[0] = dataout[0] & 0xEF;
                ErrorCode errorCode = Success;
                errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
                CheckError(errorCode);
                backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
                ui->lbl_do_pic_2->setPalette(backPalette);
            }
            else if (counter_open_2 == 0 && counter_close_2 == 1)
            {
                counter_open_2 = qRound(((ui->sld_cycle_2->value()/10.0)*1/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
                counter_close_2 = qRound(((ui->sld_cycle_2->value()/10.0)*(ui->sld_ratio_2->value()/10.0)/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
            }
            else
            {
                counter_open_2 = qRound(((ui->sld_cycle_2->value()/10.0)*1/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
                counter_close_2 = qRound(((ui->sld_cycle_2->value()/10.0)*(ui->sld_ratio_2->value()/10.0)/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
            }
        }
    }
}

void Control::sld_cycle_change_2(int value)
{
    QString str = tr("");
    str.sprintf("%.1f", value/10.0);
    ui->lbl_cycle_show_2->setText(str);
    old_cycle_2 = value/10.0;
    counter_open_2 = qRound(((ui->sld_cycle_2->value()/10.0)*1/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
    counter_close_2 = qRound(((ui->sld_cycle_2->value()/10.0)*(ui->sld_ratio_2->value()/10.0)/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
}

void Control::edit_cycle_change_2()
{
    double new_cycle_2 = ui->lbl_cycle_show_2->text().toDouble();
    //qDebug()<<new_open;
    QString str = tr("");
    if(new_cycle_2<0.1 || new_cycle_2>50)
    {
        new_cycle_2 = old_cycle_2;
    }
    str.sprintf("%.1f", new_cycle_2);
    ui->lbl_cycle_show_2->setText(str);
    ui->sld_cycle_2->setValue(new_cycle_2*10.0+0.55);
    counter_open_2 = qRound(((ui->sld_cycle_2->value()/10.0)*1/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
    counter_close_2 = qRound(((ui->sld_cycle_2->value()/10.0)*(ui->sld_ratio_2->value()/10.0)/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
    old_cycle_2 = new_cycle_2;
}

void Control::sld_ratio_change_2(int value)
{
    QString str = tr("");
    str.sprintf("%.1f", value/10.0);
    ui->lbl_ratio_show_2->setText(str);
    old_ratio_2 = value/10.0;
    str.sprintf("%.4f", 1.0/(1.0+ui->sld_ratio_2->value()/10.0));
    ui->lbl_ratio_present_2->setText(str);
    counter_open_2 = qRound(((ui->sld_cycle_2->value()/10.0)*1/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
    counter_close_2 = qRound(((ui->sld_cycle_2->value()/10.0)*(ui->sld_ratio_2->value()/10.0)/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
}

void Control::edit_ratio_change_2()
{
    double new_ratio_2 = ui->lbl_ratio_show_2->text().toDouble();
    //qDebug()<<new_open;
    QString str = tr("");
    if(new_ratio_2<0 || new_ratio_2>20)
    {
        new_ratio_2 = old_ratio_2;
    }
    str.sprintf("%.1f", new_ratio_2);
    ui->lbl_ratio_show_2->setText(str);
    str.sprintf("%.2f", 1.0/(1.0+new_ratio_2));
    ui->sld_ratio_2->setValue(new_ratio_2*10.0+0.55);
    counter_open_2 = qRound(((ui->sld_cycle_2->value()/10.0)*1/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
    counter_close_2 = qRound(((ui->sld_cycle_2->value()/10.0)*(ui->sld_ratio_2->value()/10.0)/(ui->sld_ratio_2->value()/10.0+1))*(1000.0/timer_control_interval_2));
    old_ratio_2 = new_ratio_2;
}

void Control::btn_auto_click()
{
    QPixmap pixMap_open(":/Resources/open.png");
    QPixmap pixMap_close(":/Resources/close.png");
    QPalette backPalette;

    ui->btn_duty_2->setEnabled(!(ui->btn_duty_2->isEnabled()));
    ui->btn_open_2->setEnabled(!(ui->btn_open_2->isEnabled()));
    ui->btn_close_2->setEnabled(!(ui->btn_close_2->isEnabled()));
    if(ui->btn_duty_2->isEnabled())
    {
        mode_2 = mode_before_auto;
        auto_stable = false;
    }
    else
    {
        mode_before_auto = mode_2;//save mode_2 value
        auto_stable = true;
        //ini the do needed for auto
        qDebug()<<"start to auto control";

        if( temperature[0] > cmp_t_win_h)
        {
            dataout[0] = dataout[0] | 0x10;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_open));
            ui->lbl_do_pic_2->setPalette(backPalette);
        }
        else if (temperature[0] < cmp_t_win_l)
        {
            dataout[0] = dataout[0] & 0xEF;
            ErrorCode errorCode = Success;
            errorCode = instantDoCtrl->Write(0, 1, &dataout[0]);
            CheckError(errorCode);
            backPalette.setBrush(this->backgroundRole(), QBrush(pixMap_close));
            ui->lbl_do_pic_2->setPalette(backPalette);
        }
        else
        {
            return;
        }
    }
}

void Control::Auto_T_Changed(int value)
{
    cmp_t = value * (-10.0) - 10.0;
    cmp_t_win_width = 2;
    cmp_t_win_h = cmp_t + cmp_t_win_width/2.0;
    cmp_t_win_l = cmp_t - cmp_t_win_width/2.0;
    //qDebug()<<"cmb_t index = "<<value;
}

