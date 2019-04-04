#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QTextStream>
#include "../common/simplegraph.h"
#include "configuredialog.h"
#include <QDateTime>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

const QString OutputPath1(".\\");
const QString OutputPath2("_Data.txt");
const QDateTime current_date_time =QDateTime::currentDateTime();
const QString current_date =current_date_time.toString("yyyy_MM_dd_hh_mm_ss");
const QString OutputPath = OutputPath1 + current_date + OutputPath2;


namespace Ui {
class Control;
}

class Control : public QMainWindow
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = nullptr);
    ~Control();
    void Initialize();
    void ConfigureDevice();
    void CheckError(ErrorCode errorCode);
    void SetConfigureDialog(ConfigureDialog *dialog){this->configDialog = dialog;}
    void SetConfigureParameter(ConfigureParameter value){this->configure = value;}

private:
    Ui::Control *ui;

    //connect USB-4704
    ConfigureDialog *configDialog;
    ConfigureParameter configure;

    //input data and output control signal
    InstantAiCtrl *instantAiCtrl;
    InstantDoCtrl *instantDoCtrl;
    double scaledData[16];
    quint8 dataout[1];
    
    //timer for graph, showing real-time value and write out 
    QTimer *timer;
    int timer_interval;//unit :ms
    int show_count;
    SimpleGraph *graph_t;
    SimpleGraph *graph_p;
    bool first_temperature;
    double temperature[1];// one channel for temperature
    double temperature_save[10];//save temperature at (t0,t0-0.01/0.02/0.03.../0.09)s
    double temperature_average;//the average of tempetature_save
    double temperature_before[10];//save temperature at (t0-0.01/0.02/0.03.../0.1)s
    double temperature_before_average;//the average of tempetature_before
    double pressure[1];// one channel for pressure
    double m_yCordRangeMid;
    double m_yCordRangeMid_2;

    //control valve 1
    int mode;
    QTimer *timer_control;
    int timer_control_interval;//unit: ms
    int counter_open;
    int counter_close;
    double old_ratio;
    double old_cycle;

    //control valve 2
    int mode_2;
    QTimer *timer_control_2;
    int timer_control_interval_2;//unit: ms
    int counter_open_2;
    int counter_close_2;
    double old_ratio_2;
    double old_cycle_2;
    bool auto_activate;//activate the auto control function
    bool auto_stable;//enable or disable auto control
    double cmp_t;//the temprature to be compared, selected by user
    double cmp_t_win_h;//the temprature to be compared during auto control
    double cmp_t_win_l;//the temprature to be compared during auto control
    double cmp_t_win_width;
    int mode_before_auto;//save the mode_2 before auto
    
    //current time
    QDateTime update_time;
    QString update_time_string;

    //output file
    QString str_v1;
    QString str_t;
    QString str_v2;
    QString str_p;
    QString str_cycle;
    QString str_ratio;
    QString str_cycle_2;
    QString str_ratio_2;
    QString str_f;

    //RS485 communication
    QSerialPort *flow_port;
    QTimer *timer_flow;
    QByteArray command1;
    QByteArray command2;

private slots:
    void TimerTicked();
    //control the valve 1
    void DutyControl();
    void sld_cycle_change(int value);
    void edit_cycle_change();
    void sld_ratio_change(int value);
    void edit_ratio_change();
    void btn_duty_click();
    void btn_open_click();
    void btn_close_click();
    //control the valve 2
    void DutyControl_2();
    void sld_cycle_change_2(int value);
    void edit_cycle_change_2();
    void sld_ratio_change_2(int value);
    void edit_ratio_change_2();
    void btn_duty_click_2();
    void btn_open_click_2();
    void btn_close_click_2();
    void btn_auto_click();
    void Auto_T_Changed(int value);
    //control the graph
    void sld_x_scale_change(int value);
    void sld_y_scale_change(int value);
    void sld_y_center_change(int value);
    void sld_y_scale_change_2(int value);
    void sld_y_center_change_2(int value);
    //control the sampling
    void btn_start_click();
    void btn_pause_click();
    void btn_end_click();
    //control the communication
    void PortChanged();
    void ReadFlow();
};

#endif // CONTROL_H
