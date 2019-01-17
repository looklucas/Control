#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
#include "../common/simplegraph.h"
#include "configuredialog.h"

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
    SimpleGraph *graph;
    ConfigureDialog *configDialog;
    ConfigureParameter configure;
    InstantAiCtrl *instantAiCtrl;
    double scaledData[16];
    double m_yCordRangeMid;
    QTimer *timer;

    InstantDoCtrl *instantDoCtrl;
    int mode;
    QTimer *timer_control;
    int counter_open;
    int counter_close;

private slots:
    void TimerTicked();
    void DutyControl();
    void sld_open_change(int value);
    void sld_ratio_change(int value);
    void sld_x_scale_change(int value);
    void sld_y_scale_change(int value);
    void sld_y_center_change(int value);
    void btn_start_click();
    void btn_pause_click();
    void btn_end_click();
    void btn_duty_click();
    void btn_open_click();
    void btn_close_click();
};

#endif // CONTROL_H
