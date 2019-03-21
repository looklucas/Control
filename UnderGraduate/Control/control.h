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
    SimpleGraph *graph_t;
    SimpleGraph *graph_p;
    ConfigureDialog *configDialog;
    ConfigureParameter configure;
    InstantAiCtrl *instantAiCtrl;
    double scaledData[16];
    double temperature[4];
    double pressure[2];
    double m_yCordRangeMid;
    double m_yCordRangeMid_2;
    double Time_total;
    QTimer *timer;

    InstantDiCtrl *instantDiCtrl;
    quint8 datain[1];
    InstantDoCtrl *instantDoCtrl;
    quint8 dataout[1];

    int mode;
    QTimer *timer_control;
    int timer_control_interval;//unit: ms
    int counter_open;
    int counter_close;
    double old_ratio;
    double old_cycle;

    int mode_2;
    QTimer *timer_control_2;
    int timer_control_interval_2;//unit: ms
    int counter_open_2;
    int counter_close_2;
    double old_ratio_2;
    double old_cycle_2;

    QDateTime update_time;
    QString update_time_string;

    QSerialPort *flow_port;
    QTimer *timer_flow;
    QString str_f;

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
    void PortChanged(int value);
    void ReadFlow();
};

#endif // CONTROL_H
