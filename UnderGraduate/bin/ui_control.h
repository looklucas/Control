/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Control
{
public:
    QWidget *centralWidget;
    QLabel *lbl_temp;
    QLabel *lbl_status;
    QPushButton *btn_temp_end;
    QSlider *sld_open;
    QLabel *lbl_open;
    QLabel *second;
    QSlider *sld_ratio;
    QPushButton *btn_duty;
    QLabel *lbl_status_pic;
    QLabel *lbl_scale;
    QLabel *lbl_y_max;
    QSlider *sld_x_scale;
    QSlider *sld_y_center;
    QFrame *graphFrame;
    QLabel *lbl_ratio_present;
    QPushButton *btn_open;
    QLabel *lbl_x_present;
    QLabel *lbl_center;
    QLabel *lbl_center_show;
    QPushButton *btn_temp_pause;
    QLabel *lbl_ratio;
    QPushButton *btn_temp_start;
    QLabel *lbl_ratio_2;
    QSlider *sld_y_scale;
    QLabel *lbl_scale_show;
    QLabel *lbl_y_min;
    QPushButton *btn_close;
    QLabel *lbl_y_mid;
    QLabel *lbl_time0;
    QLabel *lbl_time;
    QListWidget *listWidget;
    QLabel *lbl_real_t;
    QLabel *lbl_click_time;
    QLabel *lbl_di;
    QLabel *lbl_di_pic;
    QLabel *lbl_scale_2;
    QLabel *lbl_y_max_2;
    QLabel *lbl_temp_2;
    QFrame *graphFrame_2;
    QSlider *sld_y_center_2;
    QSlider *sld_y_scale_2;
    QLabel *lbl_center_2;
    QLabel *lbl_y_min_2;
    QLabel *lbl_scale_show_2;
    QLabel *lbl_center_show_2;
    QLabel *lbl_y_mid_2;
    QListWidget *listWidget_2;
    QLabel *lbl_real_p;
    QLineEdit *lbl_ratio_show;
    QLineEdit *lbl_open_show;

    void setupUi(QMainWindow *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName(QStringLiteral("Control"));
        Control->resize(980, 605);
        Control->setMinimumSize(QSize(980, 605));
        Control->setMaximumSize(QSize(980, 605));
        centralWidget = new QWidget(Control);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lbl_temp = new QLabel(centralWidget);
        lbl_temp->setObjectName(QStringLiteral("lbl_temp"));
        lbl_temp->setGeometry(QRect(360, 0, 181, 41));
        lbl_temp->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_status = new QLabel(centralWidget);
        lbl_status->setObjectName(QStringLiteral("lbl_status"));
        lbl_status->setGeometry(QRect(540, 560, 121, 21));
        lbl_status->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_temp_end = new QPushButton(centralWidget);
        btn_temp_end->setObjectName(QStringLiteral("btn_temp_end"));
        btn_temp_end->setGeometry(QRect(780, 510, 151, 30));
        btn_temp_end->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sld_open = new QSlider(centralWidget);
        sld_open->setObjectName(QStringLiteral("sld_open"));
        sld_open->setGeometry(QRect(250, 440, 301, 19));
        sld_open->setMinimum(10);
        sld_open->setMaximum(200);
        sld_open->setValue(75);
        sld_open->setOrientation(Qt::Horizontal);
        lbl_open = new QLabel(centralWidget);
        lbl_open->setObjectName(QStringLiteral("lbl_open"));
        lbl_open->setGeometry(QRect(70, 440, 111, 21));
        lbl_open->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        second = new QLabel(centralWidget);
        second->setObjectName(QStringLiteral("second"));
        second->setGeometry(QRect(630, 440, 31, 21));
        second->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sld_ratio = new QSlider(centralWidget);
        sld_ratio->setObjectName(QStringLiteral("sld_ratio"));
        sld_ratio->setGeometry(QRect(250, 470, 301, 19));
        sld_ratio->setMaximum(100);
        sld_ratio->setValue(15);
        sld_ratio->setOrientation(Qt::Horizontal);
        btn_duty = new QPushButton(centralWidget);
        btn_duty->setObjectName(QStringLiteral("btn_duty"));
        btn_duty->setGeometry(QRect(660, 440, 101, 30));
        btn_duty->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_status_pic = new QLabel(centralWidget);
        lbl_status_pic->setObjectName(QStringLiteral("lbl_status_pic"));
        lbl_status_pic->setGeometry(QRect(680, 550, 28, 28));
        lbl_status_pic->setAutoFillBackground(true);
        lbl_status_pic->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_scale = new QLabel(centralWidget);
        lbl_scale->setObjectName(QStringLiteral("lbl_scale"));
        lbl_scale->setGeometry(QRect(10, 10, 171, 21));
        lbl_scale->setLayoutDirection(Qt::LeftToRight);
        lbl_scale->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_max = new QLabel(centralWidget);
        lbl_y_max->setObjectName(QStringLiteral("lbl_y_max"));
        lbl_y_max->setGeometry(QRect(810, 40, 61, 21));
        lbl_y_max->setLayoutDirection(Qt::LeftToRight);
        lbl_y_max->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sld_x_scale = new QSlider(centralWidget);
        sld_x_scale->setObjectName(QStringLiteral("sld_x_scale"));
        sld_x_scale->setGeometry(QRect(40, 405, 751, 19));
        sld_x_scale->setMinimum(10);
        sld_x_scale->setMaximum(200);
        sld_x_scale->setValue(100);
        sld_x_scale->setOrientation(Qt::Horizontal);
        sld_y_center = new QSlider(centralWidget);
        sld_y_center->setObjectName(QStringLiteral("sld_y_center"));
        sld_y_center->setGeometry(QRect(920, 50, 20, 141));
        sld_y_center->setMaximum(200);
        sld_y_center->setValue(150);
        sld_y_center->setOrientation(Qt::Vertical);
        graphFrame = new QFrame(centralWidget);
        graphFrame->setObjectName(QStringLiteral("graphFrame"));
        graphFrame->setGeometry(QRect(50, 40, 741, 150));
        graphFrame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        graphFrame->setFrameShape(QFrame::StyledPanel);
        graphFrame->setFrameShadow(QFrame::Raised);
        lbl_ratio_present = new QLabel(centralWidget);
        lbl_ratio_present->setObjectName(QStringLiteral("lbl_ratio_present"));
        lbl_ratio_present->setGeometry(QRect(350, 500, 71, 21));
        lbl_ratio_present->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_open = new QPushButton(centralWidget);
        btn_open->setObjectName(QStringLiteral("btn_open"));
        btn_open->setGeometry(QRect(660, 475, 101, 30));
        btn_open->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_x_present = new QLabel(centralWidget);
        lbl_x_present->setObjectName(QStringLiteral("lbl_x_present"));
        lbl_x_present->setGeometry(QRect(810, 400, 61, 21));
        lbl_x_present->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_center = new QLabel(centralWidget);
        lbl_center->setObjectName(QStringLiteral("lbl_center"));
        lbl_center->setGeometry(QRect(720, 10, 141, 21));
        lbl_center->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_center_show = new QLabel(centralWidget);
        lbl_center_show->setObjectName(QStringLiteral("lbl_center_show"));
        lbl_center_show->setGeometry(QRect(870, 10, 81, 21));
        lbl_center_show->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_temp_pause = new QPushButton(centralWidget);
        btn_temp_pause->setObjectName(QStringLiteral("btn_temp_pause"));
        btn_temp_pause->setGeometry(QRect(780, 475, 151, 30));
        btn_temp_pause->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_ratio = new QLabel(centralWidget);
        lbl_ratio->setObjectName(QStringLiteral("lbl_ratio"));
        lbl_ratio->setGeometry(QRect(10, 470, 241, 21));
        lbl_ratio->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_temp_start = new QPushButton(centralWidget);
        btn_temp_start->setObjectName(QStringLiteral("btn_temp_start"));
        btn_temp_start->setGeometry(QRect(780, 440, 151, 30));
        btn_temp_start->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_ratio_2 = new QLabel(centralWidget);
        lbl_ratio_2->setObjectName(QStringLiteral("lbl_ratio_2"));
        lbl_ratio_2->setGeometry(QRect(200, 500, 141, 21));
        lbl_ratio_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sld_y_scale = new QSlider(centralWidget);
        sld_y_scale->setObjectName(QStringLiteral("sld_y_scale"));
        sld_y_scale->setGeometry(QRect(10, 40, 19, 141));
        sld_y_scale->setMinimum(2);
        sld_y_scale->setMaximum(200);
        sld_y_scale->setValue(100);
        sld_y_scale->setOrientation(Qt::Vertical);
        lbl_scale_show = new QLabel(centralWidget);
        lbl_scale_show->setObjectName(QStringLiteral("lbl_scale_show"));
        lbl_scale_show->setGeometry(QRect(180, 10, 101, 21));
        lbl_scale_show->setLayoutDirection(Qt::LeftToRight);
        lbl_scale_show->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_min = new QLabel(centralWidget);
        lbl_y_min->setObjectName(QStringLiteral("lbl_y_min"));
        lbl_y_min->setGeometry(QRect(810, 170, 61, 21));
        lbl_y_min->setLayoutDirection(Qt::LeftToRight);
        lbl_y_min->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_close = new QPushButton(centralWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setGeometry(QRect(660, 510, 101, 30));
        btn_close->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_mid = new QLabel(centralWidget);
        lbl_y_mid->setObjectName(QStringLiteral("lbl_y_mid"));
        lbl_y_mid->setGeometry(QRect(810, 100, 61, 21));
        lbl_y_mid->setLayoutDirection(Qt::LeftToRight);
        lbl_y_mid->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_time0 = new QLabel(centralWidget);
        lbl_time0->setObjectName(QStringLiteral("lbl_time0"));
        lbl_time0->setGeometry(QRect(780, 560, 41, 21));
        lbl_time0->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_time = new QLabel(centralWidget);
        lbl_time->setObjectName(QStringLiteral("lbl_time"));
        lbl_time->setGeometry(QRect(830, 560, 51, 21));
        lbl_time->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(130, 530, 210, 25));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setProperty("isWrapping", QVariant(true));
        lbl_real_t = new QLabel(centralWidget);
        lbl_real_t->setObjectName(QStringLiteral("lbl_real_t"));
        lbl_real_t->setGeometry(QRect(10, 525, 111, 31));
        lbl_real_t->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_real_t->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_click_time = new QLabel(centralWidget);
        lbl_click_time->setObjectName(QStringLiteral("lbl_click_time"));
        lbl_click_time->setGeometry(QRect(310, 550, 51, 31));
        lbl_click_time->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_click_time->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_di = new QLabel(centralWidget);
        lbl_di->setObjectName(QStringLiteral("lbl_di"));
        lbl_di->setGeometry(QRect(370, 560, 111, 21));
        lbl_di->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_di_pic = new QLabel(centralWidget);
        lbl_di_pic->setObjectName(QStringLiteral("lbl_di_pic"));
        lbl_di_pic->setGeometry(QRect(480, 550, 28, 28));
        lbl_di_pic->setAutoFillBackground(true);
        lbl_di_pic->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_scale_2 = new QLabel(centralWidget);
        lbl_scale_2->setObjectName(QStringLiteral("lbl_scale_2"));
        lbl_scale_2->setGeometry(QRect(10, 200, 151, 21));
        lbl_scale_2->setLayoutDirection(Qt::LeftToRight);
        lbl_scale_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_max_2 = new QLabel(centralWidget);
        lbl_y_max_2->setObjectName(QStringLiteral("lbl_y_max_2"));
        lbl_y_max_2->setGeometry(QRect(810, 230, 61, 21));
        lbl_y_max_2->setLayoutDirection(Qt::LeftToRight);
        lbl_y_max_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_temp_2 = new QLabel(centralWidget);
        lbl_temp_2->setObjectName(QStringLiteral("lbl_temp_2"));
        lbl_temp_2->setGeometry(QRect(380, 190, 181, 41));
        lbl_temp_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        graphFrame_2 = new QFrame(centralWidget);
        graphFrame_2->setObjectName(QStringLiteral("graphFrame_2"));
        graphFrame_2->setGeometry(QRect(50, 230, 741, 150));
        graphFrame_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        graphFrame_2->setFrameShape(QFrame::StyledPanel);
        graphFrame_2->setFrameShadow(QFrame::Raised);
        sld_y_center_2 = new QSlider(centralWidget);
        sld_y_center_2->setObjectName(QStringLiteral("sld_y_center_2"));
        sld_y_center_2->setGeometry(QRect(920, 240, 20, 141));
        sld_y_center_2->setMinimum(20);
        sld_y_center_2->setMaximum(750);
        sld_y_center_2->setPageStep(10);
        sld_y_center_2->setValue(500);
        sld_y_center_2->setOrientation(Qt::Vertical);
        sld_y_scale_2 = new QSlider(centralWidget);
        sld_y_scale_2->setObjectName(QStringLiteral("sld_y_scale_2"));
        sld_y_scale_2->setGeometry(QRect(10, 230, 19, 141));
        sld_y_scale_2->setMinimum(10);
        sld_y_scale_2->setMaximum(150);
        sld_y_scale_2->setValue(100);
        sld_y_scale_2->setOrientation(Qt::Vertical);
        lbl_center_2 = new QLabel(centralWidget);
        lbl_center_2->setObjectName(QStringLiteral("lbl_center_2"));
        lbl_center_2->setGeometry(QRect(730, 200, 141, 21));
        lbl_center_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_min_2 = new QLabel(centralWidget);
        lbl_y_min_2->setObjectName(QStringLiteral("lbl_y_min_2"));
        lbl_y_min_2->setGeometry(QRect(810, 360, 61, 21));
        lbl_y_min_2->setLayoutDirection(Qt::LeftToRight);
        lbl_y_min_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_scale_show_2 = new QLabel(centralWidget);
        lbl_scale_show_2->setObjectName(QStringLiteral("lbl_scale_show_2"));
        lbl_scale_show_2->setGeometry(QRect(150, 200, 101, 21));
        lbl_scale_show_2->setLayoutDirection(Qt::LeftToRight);
        lbl_scale_show_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_center_show_2 = new QLabel(centralWidget);
        lbl_center_show_2->setObjectName(QStringLiteral("lbl_center_show_2"));
        lbl_center_show_2->setGeometry(QRect(870, 200, 81, 21));
        lbl_center_show_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_mid_2 = new QLabel(centralWidget);
        lbl_y_mid_2->setObjectName(QStringLiteral("lbl_y_mid_2"));
        lbl_y_mid_2->setGeometry(QRect(810, 290, 61, 21));
        lbl_y_mid_2->setLayoutDirection(Qt::LeftToRight);
        lbl_y_mid_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(130, 560, 210, 25));
        listWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget_2->setFlow(QListView::LeftToRight);
        listWidget_2->setProperty("isWrapping", QVariant(true));
        lbl_real_p = new QLabel(centralWidget);
        lbl_real_p->setObjectName(QStringLiteral("lbl_real_p"));
        lbl_real_p->setGeometry(QRect(10, 555, 71, 31));
        lbl_real_p->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_real_p->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_ratio_show = new QLineEdit(centralWidget);
        lbl_ratio_show->setObjectName(QStringLiteral("lbl_ratio_show"));
        lbl_ratio_show->setGeometry(QRect(570, 470, 50, 20));
        lbl_ratio_show->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_open_show = new QLineEdit(centralWidget);
        lbl_open_show->setObjectName(QStringLiteral("lbl_open_show"));
        lbl_open_show->setGeometry(QRect(570, 440, 50, 20));
        lbl_open_show->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        Control->setCentralWidget(centralWidget);

        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QMainWindow *Control)
    {
        Control->setWindowTitle(QApplication::translate("Control", "Control", nullptr));
        lbl_temp->setText(QApplication::translate("Control", "Temperature\357\274\210\342\204\203\357\274\211", nullptr));
        lbl_status->setText(QApplication::translate("Control", "Digital Output\357\274\232", nullptr));
        btn_temp_end->setText(QApplication::translate("Control", "Stop Recording", nullptr));
        lbl_open->setText(QApplication::translate("Control", "Time of open\357\274\210s\357\274\211", nullptr));
        second->setText(QApplication::translate("Control", "s", nullptr));
        btn_duty->setText(QApplication::translate("Control", "Control", nullptr));
        lbl_status_pic->setText(QString());
        lbl_scale->setText(QApplication::translate("Control", "Temperature Range\357\274\232", nullptr));
        lbl_y_max->setText(QApplication::translate("Control", "50.0\342\204\203", nullptr));
        lbl_ratio_present->setText(QApplication::translate("Control", "0.40", nullptr));
        btn_open->setText(QApplication::translate("Control", "Keep Open", nullptr));
        lbl_x_present->setText(QApplication::translate("Control", "1s/\346\240\274", nullptr));
        lbl_center->setText(QApplication::translate("Control", "Temperature Center\357\274\232", nullptr));
        lbl_center_show->setText(QApplication::translate("Control", "0.0\342\204\203", nullptr));
        btn_temp_pause->setText(QApplication::translate("Control", "Pause Recording", nullptr));
        lbl_ratio->setText(QApplication::translate("Control", "Set Duty ratio\357\274\210close/open\357\274\211", nullptr));
        btn_temp_start->setText(QApplication::translate("Control", "Start Recording", nullptr));
        lbl_ratio_2->setText(QApplication::translate("Control", "Duty ratio at present\357\274\232", nullptr));
        lbl_scale_show->setText(QApplication::translate("Control", "100.0\342\204\203", nullptr));
        lbl_y_min->setText(QApplication::translate("Control", "-50.0\342\204\203", nullptr));
        btn_close->setText(QApplication::translate("Control", "Keep Close", nullptr));
        lbl_y_mid->setText(QApplication::translate("Control", "0.0\342\204\203", nullptr));
        lbl_time0->setText(QApplication::translate("Control", "Time\357\274\232", nullptr));
        lbl_time->setText(QApplication::translate("Control", "0s", nullptr));
        lbl_real_t->setText(QApplication::translate("Control", "Temperature", nullptr));
        lbl_click_time->setText(QString());
        lbl_di->setText(QApplication::translate("Control", "Digital Input\357\274\232", nullptr));
        lbl_di_pic->setText(QString());
        lbl_scale_2->setText(QApplication::translate("Control", "Pressure Range\357\274\232", nullptr));
        lbl_y_max_2->setText(QApplication::translate("Control", "1MPa", nullptr));
        lbl_temp_2->setText(QApplication::translate("Control", "Pressure\357\274\210MPa\357\274\211", nullptr));
        lbl_center_2->setText(QApplication::translate("Control", "Pressure Center\357\274\232", nullptr));
        lbl_y_min_2->setText(QApplication::translate("Control", "0MPa", nullptr));
        lbl_scale_show_2->setText(QApplication::translate("Control", "1Mpa", nullptr));
        lbl_center_show_2->setText(QApplication::translate("Control", "0.5MPa", nullptr));
        lbl_y_mid_2->setText(QApplication::translate("Control", "0.5MPa", nullptr));
        lbl_real_p->setText(QApplication::translate("Control", "Pressure", nullptr));
        lbl_ratio_show->setText(QApplication::translate("Control", "1.5", nullptr));
        lbl_open_show->setText(QApplication::translate("Control", "0.75", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
