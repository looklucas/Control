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
#include <QtWidgets/QComboBox>
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
    QLabel *lbl_do;
    QPushButton *btn_temp_end;
    QSlider *sld_cycle;
    QLabel *lbl_cycle;
    QLabel *second;
    QSlider *sld_ratio;
    QPushButton *btn_duty;
    QLabel *lbl_do_pic;
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
    QLabel *lbl_ratio_1_1;
    QPushButton *btn_temp_start;
    QLabel *lbl_ratio_1_2;
    QSlider *sld_y_scale;
    QLabel *lbl_scale_show;
    QLabel *lbl_y_min;
    QPushButton *btn_close;
    QLabel *lbl_y_mid;
    QLabel *lbl_time_label;
    QLabel *lbl_time;
    QListWidget *listWidget;
    QLabel *lbl_scale_2;
    QLabel *lbl_y_max_2;
    QLabel *lbl_temp_2;
    QFrame *graphFrame_2;
    QPushButton *pushButton;
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
    QLineEdit *lbl_cycle_show;
    QLabel *lbl_real_f;
    QListWidget *listWidget_3;
    QLabel *lbl_port;
    QComboBox *cmb_port;
    QLineEdit *lbl_cycle_show_2;
    QLabel *lbl_ratio_present_2;
    QSlider *sld_ratio_2;
    QSlider *sld_cycle_2;
    QLabel *lbl_cycle_2;
    QLabel *lbl_ratio_2_2;
    QLineEdit *lbl_ratio_show_2;
    QLabel *lbl_ratio_2_1;
    QLabel *second_2;
    QLabel *lbl_do_pic_2;
    QLabel *lbl_do_2;
    QPushButton *btn_open_2;
    QPushButton *btn_close_2;
    QPushButton *btn_duty_2;
    QLabel *lbl_real_t;
    QComboBox *cmb_t;
    QPushButton *btn_auto;
    QLabel *lbl_t_select;

    void setupUi(QMainWindow *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName(QStringLiteral("Control"));
        Control->resize(1000, 720);
        Control->setMinimumSize(QSize(1000, 720));
        Control->setMaximumSize(QSize(1000, 720));
        centralWidget = new QWidget(Control);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lbl_temp = new QLabel(centralWidget);
        lbl_temp->setObjectName(QStringLiteral("lbl_temp"));
        lbl_temp->setGeometry(QRect(360, 0, 181, 41));
        lbl_temp->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_do = new QLabel(centralWidget);
        lbl_do->setObjectName(QStringLiteral("lbl_do"));
        lbl_do->setGeometry(QRect(280, 675, 141, 21));
        lbl_do->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_temp_end = new QPushButton(centralWidget);
        btn_temp_end->setObjectName(QStringLiteral("btn_temp_end"));
        btn_temp_end->setGeometry(QRect(660, 640, 150, 30));
        btn_temp_end->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sld_cycle = new QSlider(centralWidget);
        sld_cycle->setObjectName(QStringLiteral("sld_cycle"));
        sld_cycle->setGeometry(QRect(250, 440, 301, 19));
        sld_cycle->setMinimum(1);
        sld_cycle->setMaximum(500);
        sld_cycle->setValue(10);
        sld_cycle->setOrientation(Qt::Horizontal);
        lbl_cycle = new QLabel(centralWidget);
        lbl_cycle->setObjectName(QStringLiteral("lbl_cycle"));
        lbl_cycle->setGeometry(QRect(70, 440, 161, 21));
        lbl_cycle->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        second = new QLabel(centralWidget);
        second->setObjectName(QStringLiteral("second"));
        second->setGeometry(QRect(630, 440, 31, 21));
        second->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sld_ratio = new QSlider(centralWidget);
        sld_ratio->setObjectName(QStringLiteral("sld_ratio"));
        sld_ratio->setGeometry(QRect(250, 470, 301, 19));
        sld_ratio->setMaximum(200);
        sld_ratio->setValue(10);
        sld_ratio->setOrientation(Qt::Horizontal);
        btn_duty = new QPushButton(centralWidget);
        btn_duty->setObjectName(QStringLiteral("btn_duty"));
        btn_duty->setGeometry(QRect(660, 440, 150, 30));
        btn_duty->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_do_pic = new QLabel(centralWidget);
        lbl_do_pic->setObjectName(QStringLiteral("lbl_do_pic"));
        lbl_do_pic->setGeometry(QRect(430, 670, 28, 28));
        lbl_do_pic->setAutoFillBackground(true);
        lbl_do_pic->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_scale = new QLabel(centralWidget);
        lbl_scale->setObjectName(QStringLiteral("lbl_scale"));
        lbl_scale->setGeometry(QRect(10, 10, 171, 21));
        lbl_scale->setLayoutDirection(Qt::LeftToRight);
        lbl_scale->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_max = new QLabel(centralWidget);
        lbl_y_max->setObjectName(QStringLiteral("lbl_y_max"));
        lbl_y_max->setGeometry(QRect(810, 40, 101, 21));
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
        lbl_ratio_present->setGeometry(QRect(460, 560, 71, 21));
        lbl_ratio_present->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_open = new QPushButton(centralWidget);
        btn_open->setObjectName(QStringLiteral("btn_open"));
        btn_open->setGeometry(QRect(660, 480, 150, 30));
        btn_open->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_x_present = new QLabel(centralWidget);
        lbl_x_present->setObjectName(QStringLiteral("lbl_x_present"));
        lbl_x_present->setGeometry(QRect(810, 400, 101, 21));
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
        btn_temp_pause->setGeometry(QRect(660, 600, 150, 30));
        btn_temp_pause->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_ratio_1_1 = new QLabel(centralWidget);
        lbl_ratio_1_1->setObjectName(QStringLiteral("lbl_ratio_1_1"));
        lbl_ratio_1_1->setGeometry(QRect(10, 470, 241, 21));
        lbl_ratio_1_1->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_temp_start = new QPushButton(centralWidget);
        btn_temp_start->setObjectName(QStringLiteral("btn_temp_start"));
        btn_temp_start->setGeometry(QRect(660, 560, 150, 30));
        btn_temp_start->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_ratio_1_2 = new QLabel(centralWidget);
        lbl_ratio_1_2->setObjectName(QStringLiteral("lbl_ratio_1_2"));
        lbl_ratio_1_2->setGeometry(QRect(280, 560, 181, 21));
        lbl_ratio_1_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
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
        lbl_y_min->setGeometry(QRect(810, 170, 101, 21));
        lbl_y_min->setLayoutDirection(Qt::LeftToRight);
        lbl_y_min->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_close = new QPushButton(centralWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setGeometry(QRect(660, 520, 150, 30));
        btn_close->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_mid = new QLabel(centralWidget);
        lbl_y_mid->setObjectName(QStringLiteral("lbl_y_mid"));
        lbl_y_mid->setGeometry(QRect(810, 100, 91, 21));
        lbl_y_mid->setLayoutDirection(Qt::LeftToRight);
        lbl_y_mid->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_time_label = new QLabel(centralWidget);
        lbl_time_label->setObjectName(QStringLiteral("lbl_time_label"));
        lbl_time_label->setGeometry(QRect(280, 630, 121, 21));
        lbl_time_label->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_time = new QLabel(centralWidget);
        lbl_time->setObjectName(QStringLiteral("lbl_time"));
        lbl_time->setGeometry(QRect(410, 630, 121, 21));
        lbl_time->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(150, 565, 75, 25));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setProperty("isWrapping", QVariant(true));
        lbl_scale_2 = new QLabel(centralWidget);
        lbl_scale_2->setObjectName(QStringLiteral("lbl_scale_2"));
        lbl_scale_2->setGeometry(QRect(10, 200, 151, 21));
        lbl_scale_2->setLayoutDirection(Qt::LeftToRight);
        lbl_scale_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_max_2 = new QLabel(centralWidget);
        lbl_y_max_2->setObjectName(QStringLiteral("lbl_y_max_2"));
        lbl_y_max_2->setGeometry(QRect(810, 230, 81, 21));
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
        pushButton = new QPushButton(graphFrame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 80, 93, 28));
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
        lbl_y_min_2->setGeometry(QRect(810, 360, 91, 21));
        lbl_y_min_2->setLayoutDirection(Qt::LeftToRight);
        lbl_y_min_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_scale_show_2 = new QLabel(centralWidget);
        lbl_scale_show_2->setObjectName(QStringLiteral("lbl_scale_show_2"));
        lbl_scale_show_2->setGeometry(QRect(150, 200, 101, 21));
        lbl_scale_show_2->setLayoutDirection(Qt::LeftToRight);
        lbl_scale_show_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_center_show_2 = new QLabel(centralWidget);
        lbl_center_show_2->setObjectName(QStringLiteral("lbl_center_show_2"));
        lbl_center_show_2->setGeometry(QRect(870, 200, 91, 21));
        lbl_center_show_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_y_mid_2 = new QLabel(centralWidget);
        lbl_y_mid_2->setObjectName(QStringLiteral("lbl_y_mid_2"));
        lbl_y_mid_2->setGeometry(QRect(810, 290, 91, 21));
        lbl_y_mid_2->setLayoutDirection(Qt::LeftToRight);
        lbl_y_mid_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(150, 600, 75, 25));
        listWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget_2->setFlow(QListView::LeftToRight);
        listWidget_2->setProperty("isWrapping", QVariant(true));
        lbl_real_p = new QLabel(centralWidget);
        lbl_real_p->setObjectName(QStringLiteral("lbl_real_p"));
        lbl_real_p->setGeometry(QRect(10, 595, 141, 31));
        lbl_real_p->setMinimumSize(QSize(141, 31));
        lbl_real_p->setMaximumSize(QSize(141, 31));
        lbl_real_p->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_real_p->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_ratio_show = new QLineEdit(centralWidget);
        lbl_ratio_show->setObjectName(QStringLiteral("lbl_ratio_show"));
        lbl_ratio_show->setGeometry(QRect(570, 470, 50, 20));
        lbl_ratio_show->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_cycle_show = new QLineEdit(centralWidget);
        lbl_cycle_show->setObjectName(QStringLiteral("lbl_cycle_show"));
        lbl_cycle_show->setGeometry(QRect(570, 440, 50, 20));
        lbl_cycle_show->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_cycle_show->setMaxLength(32767);
        lbl_real_f = new QLabel(centralWidget);
        lbl_real_f->setObjectName(QStringLiteral("lbl_real_f"));
        lbl_real_f->setGeometry(QRect(10, 630, 141, 31));
        lbl_real_f->setMinimumSize(QSize(141, 31));
        lbl_real_f->setMaximumSize(QSize(141, 31));
        lbl_real_f->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_real_f->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        listWidget_3 = new QListWidget(centralWidget);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setGeometry(QRect(150, 635, 75, 25));
        listWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_3->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget_3->setFlow(QListView::LeftToRight);
        listWidget_3->setProperty("isWrapping", QVariant(true));
        lbl_port = new QLabel(centralWidget);
        lbl_port->setObjectName(QStringLiteral("lbl_port"));
        lbl_port->setGeometry(QRect(10, 665, 141, 31));
        lbl_port->setMinimumSize(QSize(141, 31));
        lbl_port->setMaximumSize(QSize(141, 31));
        lbl_port->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_port->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cmb_port = new QComboBox(centralWidget);
        cmb_port->setObjectName(QStringLiteral("cmb_port"));
        cmb_port->setGeometry(QRect(150, 670, 75, 25));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmb_port->sizePolicy().hasHeightForWidth());
        cmb_port->setSizePolicy(sizePolicy);
        cmb_port->setMaximumSize(QSize(100, 50));
        cmb_port->setStyleSheet(QStringLiteral(""));
        cmb_port->setMaxCount(10);
        lbl_cycle_show_2 = new QLineEdit(centralWidget);
        lbl_cycle_show_2->setObjectName(QStringLiteral("lbl_cycle_show_2"));
        lbl_cycle_show_2->setGeometry(QRect(570, 500, 50, 20));
        lbl_cycle_show_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_cycle_show_2->setMaxLength(32767);
        lbl_ratio_present_2 = new QLabel(centralWidget);
        lbl_ratio_present_2->setObjectName(QStringLiteral("lbl_ratio_present_2"));
        lbl_ratio_present_2->setGeometry(QRect(460, 590, 71, 21));
        lbl_ratio_present_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sld_ratio_2 = new QSlider(centralWidget);
        sld_ratio_2->setObjectName(QStringLiteral("sld_ratio_2"));
        sld_ratio_2->setGeometry(QRect(250, 530, 301, 19));
        sld_ratio_2->setMaximum(200);
        sld_ratio_2->setValue(10);
        sld_ratio_2->setOrientation(Qt::Horizontal);
        sld_cycle_2 = new QSlider(centralWidget);
        sld_cycle_2->setObjectName(QStringLiteral("sld_cycle_2"));
        sld_cycle_2->setGeometry(QRect(250, 500, 301, 19));
        sld_cycle_2->setMinimum(1);
        sld_cycle_2->setMaximum(500);
        sld_cycle_2->setValue(10);
        sld_cycle_2->setOrientation(Qt::Horizontal);
        lbl_cycle_2 = new QLabel(centralWidget);
        lbl_cycle_2->setObjectName(QStringLiteral("lbl_cycle_2"));
        lbl_cycle_2->setGeometry(QRect(70, 500, 161, 21));
        lbl_cycle_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_ratio_2_2 = new QLabel(centralWidget);
        lbl_ratio_2_2->setObjectName(QStringLiteral("lbl_ratio_2_2"));
        lbl_ratio_2_2->setGeometry(QRect(280, 590, 181, 21));
        lbl_ratio_2_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_ratio_show_2 = new QLineEdit(centralWidget);
        lbl_ratio_show_2->setObjectName(QStringLiteral("lbl_ratio_show_2"));
        lbl_ratio_show_2->setGeometry(QRect(570, 530, 50, 20));
        lbl_ratio_show_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_ratio_2_1 = new QLabel(centralWidget);
        lbl_ratio_2_1->setObjectName(QStringLiteral("lbl_ratio_2_1"));
        lbl_ratio_2_1->setGeometry(QRect(10, 530, 241, 21));
        lbl_ratio_2_1->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        second_2 = new QLabel(centralWidget);
        second_2->setObjectName(QStringLiteral("second_2"));
        second_2->setGeometry(QRect(630, 500, 31, 21));
        second_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_do_pic_2 = new QLabel(centralWidget);
        lbl_do_pic_2->setObjectName(QStringLiteral("lbl_do_pic_2"));
        lbl_do_pic_2->setGeometry(QRect(630, 670, 28, 28));
        lbl_do_pic_2->setAutoFillBackground(true);
        lbl_do_pic_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_do_2 = new QLabel(centralWidget);
        lbl_do_2->setObjectName(QStringLiteral("lbl_do_2"));
        lbl_do_2->setGeometry(QRect(480, 675, 141, 21));
        lbl_do_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_open_2 = new QPushButton(centralWidget);
        btn_open_2->setObjectName(QStringLiteral("btn_open_2"));
        btn_open_2->setGeometry(QRect(830, 480, 150, 30));
        btn_open_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_close_2 = new QPushButton(centralWidget);
        btn_close_2->setObjectName(QStringLiteral("btn_close_2"));
        btn_close_2->setGeometry(QRect(830, 520, 150, 30));
        btn_close_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_duty_2 = new QPushButton(centralWidget);
        btn_duty_2->setObjectName(QStringLiteral("btn_duty_2"));
        btn_duty_2->setGeometry(QRect(830, 440, 150, 30));
        btn_duty_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_real_t = new QLabel(centralWidget);
        lbl_real_t->setObjectName(QStringLiteral("lbl_real_t"));
        lbl_real_t->setGeometry(QRect(10, 560, 141, 31));
        lbl_real_t->setMinimumSize(QSize(141, 31));
        lbl_real_t->setMaximumSize(QSize(141, 31));
        lbl_real_t->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_real_t->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cmb_t = new QComboBox(centralWidget);
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->addItem(QString());
        cmb_t->setObjectName(QStringLiteral("cmb_t"));
        cmb_t->setGeometry(QRect(830, 640, 150, 30));
        sizePolicy.setHeightForWidth(cmb_t->sizePolicy().hasHeightForWidth());
        cmb_t->setSizePolicy(sizePolicy);
        cmb_t->setMaximumSize(QSize(150, 50));
        cmb_t->setFocusPolicy(Qt::WheelFocus);
        cmb_t->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        cmb_t->setMaxCount(20);
        btn_auto = new QPushButton(centralWidget);
        btn_auto->setObjectName(QStringLiteral("btn_auto"));
        btn_auto->setGeometry(QRect(830, 560, 150, 30));
        btn_auto->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl_t_select = new QLabel(centralWidget);
        lbl_t_select->setObjectName(QStringLiteral("lbl_t_select"));
        lbl_t_select->setGeometry(QRect(830, 605, 161, 21));
        lbl_t_select->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        Control->setCentralWidget(centralWidget);

        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QMainWindow *Control)
    {
        Control->setWindowTitle(QApplication::translate("Control", "Control", nullptr));
        lbl_temp->setText(QApplication::translate("Control", "Temperature\357\274\210\342\204\203\357\274\211", nullptr));
        lbl_do->setText(QApplication::translate("Control", "Digital Output 1\357\274\232", nullptr));
        btn_temp_end->setText(QApplication::translate("Control", "Stop Recording", nullptr));
        lbl_cycle->setText(QApplication::translate("Control", "Time of Cycle\357\274\210s\357\274\211", nullptr));
        second->setText(QApplication::translate("Control", "s", nullptr));
        btn_duty->setText(QApplication::translate("Control", "Control valve 1", nullptr));
        lbl_do_pic->setText(QString());
        lbl_scale->setText(QApplication::translate("Control", "Temperature Range\357\274\232", nullptr));
        lbl_y_max->setText(QApplication::translate("Control", "50.0\342\204\203", nullptr));
        lbl_ratio_present->setText(QApplication::translate("Control", "0.40", nullptr));
        btn_open->setText(QApplication::translate("Control", "Open valve 1", nullptr));
        lbl_x_present->setText(QApplication::translate("Control", "10.0s/\346\240\274", nullptr));
        lbl_center->setText(QApplication::translate("Control", "Temperature Center\357\274\232", nullptr));
        lbl_center_show->setText(QApplication::translate("Control", "0.0\342\204\203", nullptr));
        btn_temp_pause->setText(QApplication::translate("Control", "Pause Recording", nullptr));
        lbl_ratio_1_1->setText(QApplication::translate("Control", "Set Duty ratio\357\274\210close/open\357\274\211", nullptr));
        btn_temp_start->setText(QApplication::translate("Control", "Start Recording", nullptr));
        lbl_ratio_1_2->setText(QApplication::translate("Control", "Duty ratio at present\357\274\232", nullptr));
        lbl_scale_show->setText(QApplication::translate("Control", "100.0\342\204\203", nullptr));
        lbl_y_min->setText(QApplication::translate("Control", "-50.0\342\204\203", nullptr));
        btn_close->setText(QApplication::translate("Control", "Close valve 1", nullptr));
        lbl_y_mid->setText(QApplication::translate("Control", "0.0\342\204\203", nullptr));
        lbl_time_label->setText(QApplication::translate("Control", "Current Time\357\274\232", nullptr));
        lbl_time->setText(QString());
        lbl_scale_2->setText(QApplication::translate("Control", "Pressure Range\357\274\232", nullptr));
        lbl_y_max_2->setText(QApplication::translate("Control", "1MPa", nullptr));
        lbl_temp_2->setText(QApplication::translate("Control", "Pressure\357\274\210MPa\357\274\211", nullptr));
        pushButton->setText(QApplication::translate("Control", "PushButton", nullptr));
        lbl_center_2->setText(QApplication::translate("Control", "Pressure Center\357\274\232", nullptr));
        lbl_y_min_2->setText(QApplication::translate("Control", "0MPa", nullptr));
        lbl_scale_show_2->setText(QApplication::translate("Control", "1Mpa", nullptr));
        lbl_center_show_2->setText(QApplication::translate("Control", "0.5MPa", nullptr));
        lbl_y_mid_2->setText(QApplication::translate("Control", "0.5MPa", nullptr));
        lbl_real_p->setText(QApplication::translate("Control", "Pressure(MPa)", nullptr));
        lbl_ratio_show->setText(QApplication::translate("Control", "1.0", nullptr));
        lbl_cycle_show->setText(QApplication::translate("Control", "1.0", nullptr));
        lbl_real_f->setText(QApplication::translate("Control", "Flow(L/min)", nullptr));
        lbl_port->setText(QApplication::translate("Control", "Port for Flow", nullptr));
        lbl_cycle_show_2->setText(QApplication::translate("Control", "1.0", nullptr));
        lbl_ratio_present_2->setText(QApplication::translate("Control", "0.40", nullptr));
        lbl_cycle_2->setText(QApplication::translate("Control", "Time of Cycle\357\274\210s\357\274\211", nullptr));
        lbl_ratio_2_2->setText(QApplication::translate("Control", "Duty ratio at present\357\274\232", nullptr));
        lbl_ratio_show_2->setText(QApplication::translate("Control", "1.0", nullptr));
        lbl_ratio_2_1->setText(QApplication::translate("Control", "Set Duty ratio\357\274\210close/open\357\274\211", nullptr));
        second_2->setText(QApplication::translate("Control", "s", nullptr));
        lbl_do_pic_2->setText(QString());
        lbl_do_2->setText(QApplication::translate("Control", "Digital Output 2\357\274\232", nullptr));
        btn_open_2->setText(QApplication::translate("Control", "Open valve 2", nullptr));
        btn_close_2->setText(QApplication::translate("Control", "Close valve 2", nullptr));
        btn_duty_2->setText(QApplication::translate("Control", "Control valve 2", nullptr));
        lbl_real_t->setText(QApplication::translate("Control", "Temperature(\342\204\203)", nullptr));
        cmb_t->setItemText(0, QApplication::translate("Control", "-10\342\204\203", nullptr));
        cmb_t->setItemText(1, QApplication::translate("Control", "-20\342\204\203", nullptr));
        cmb_t->setItemText(2, QApplication::translate("Control", "-30\342\204\203", nullptr));
        cmb_t->setItemText(3, QApplication::translate("Control", "-40\342\204\203", nullptr));
        cmb_t->setItemText(4, QApplication::translate("Control", "-50\342\204\203", nullptr));
        cmb_t->setItemText(5, QApplication::translate("Control", "-60\342\204\203", nullptr));
        cmb_t->setItemText(6, QApplication::translate("Control", "-70\342\204\203", nullptr));
        cmb_t->setItemText(7, QApplication::translate("Control", "-80\342\204\203", nullptr));
        cmb_t->setItemText(8, QApplication::translate("Control", "-90\342\204\203", nullptr));
        cmb_t->setItemText(9, QApplication::translate("Control", "-100\342\204\203", nullptr));
        cmb_t->setItemText(10, QApplication::translate("Control", "-110\342\204\203", nullptr));
        cmb_t->setItemText(11, QApplication::translate("Control", "-120\342\204\203", nullptr));
        cmb_t->setItemText(12, QApplication::translate("Control", "-130\342\204\203", nullptr));

        btn_auto->setText(QApplication::translate("Control", "Auto Control", nullptr));
        lbl_t_select->setText(QApplication::translate("Control", "Temperature select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
