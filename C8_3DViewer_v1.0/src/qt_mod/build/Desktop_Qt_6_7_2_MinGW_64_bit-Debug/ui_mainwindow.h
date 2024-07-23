/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "oglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_7;
    OGLWidget *openGLWidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_15;
    QSpinBox *x_turn_spinbox;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_16;
    QSpinBox *y_turn_spinbox;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_17;
    QSpinBox *z_turn_spinbox;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QSpinBox *x_move_spinbox;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_12;
    QSpinBox *y_move_spinbox;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_13;
    QSpinBox *z_move_spinbox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QGridLayout *gridLayout_3;
    QPushButton *render;
    QPushButton *select_obj;
    QLineEdit *file_path;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_25;
    QLabel *edges;
    QLineEdit *count_edge_info;
    QHBoxLayout *horizontalLayout_28;
    QLabel *vertices;
    QLineEdit *count_vertex_info;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_29;
    QLabel *v_color_prev;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *v_red_label;
    QSlider *v_red_slider;
    QSpinBox *v_red_spinbox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *v_green_label;
    QSlider *v_green_slider;
    QSpinBox *v_green_spinbox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *v_blue_label;
    QSlider *v_blue_slider;
    QSpinBox *v_blue_spinbox;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_31;
    QLabel *bg_color_prev;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *bg_red_label;
    QSlider *bg_red_slider;
    QSpinBox *bg_red_spinbox;
    QHBoxLayout *horizontalLayout_12;
    QLabel *bg_green_label;
    QSlider *bg_green_slider;
    QSpinBox *bg_green_spinbox;
    QHBoxLayout *horizontalLayout_13;
    QLabel *bg_blue_label;
    QSlider *bg_blue_slider;
    QSpinBox *bg_blue_spinbox;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_30;
    QLabel *e_color_prev;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *e_red_label;
    QSlider *e_red_slider;
    QSpinBox *e_red_spinbox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *e_green_label;
    QSlider *e_green_slider;
    QSpinBox *e_green_spinbox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *e_blue_label;
    QSlider *e_blue_slider;
    QSpinBox *e_blue_spinbox;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_34;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_7;
    QComboBox *line_type;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_9;
    QSpinBox *line_thickness;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_37;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_2;
    QComboBox *vertex_type;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_4;
    QSpinBox *vertex_size;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label;
    QComboBox *projection_type;
    QPushButton *screenshot_btn;
    QPushButton *gif_btn;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_20;
    QLineEdit *filename_info;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1033, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1033, 700));
        MainWindow->setMaximumSize(QSize(1033, 700));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bauhaus 93")});
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_16 = new QHBoxLayout(centralwidget);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        openGLWidget = new OGLWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(openGLWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        verticalLayout_7->addLayout(horizontalLayout_3);


        horizontalLayout_16->addLayout(verticalLayout_7);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(290, 0));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(164, 254, 202, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(209, 254, 228, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(82, 127, 101, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(109, 169, 135, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(82, 127, 101, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        QBrush brush9(QColor(240, 255, 246, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush9);
        groupBox->setPalette(palette);
        label_22 = new QLabel(groupBox);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(10, 300, 71, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bauhaus 93")});
        font1.setHintingPreference(QFont::PreferNoHinting);
        label_22->setFont(font1);
        label_23 = new QLabel(groupBox);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 390, 71, 16));
        label_23->setToolTipDuration(6);
        label_23->setLayoutDirection(Qt::LeftToRight);
        label_23->setText(QString::fromUtf8("Color edges:"));
        label_24 = new QLabel(groupBox);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 480, 111, 16));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 140, 275, 61));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");

        horizontalLayout_23->addWidget(label_14);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName("label_15");

        horizontalLayout_20->addWidget(label_15);

        x_turn_spinbox = new QSpinBox(layoutWidget);
        x_turn_spinbox->setObjectName("x_turn_spinbox");
        x_turn_spinbox->setMinimum(1);
        x_turn_spinbox->setMaximum(100);
        x_turn_spinbox->setValue(50);

        horizontalLayout_20->addWidget(x_turn_spinbox);


        horizontalLayout_23->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName("label_16");

        horizontalLayout_21->addWidget(label_16);

        y_turn_spinbox = new QSpinBox(layoutWidget);
        y_turn_spinbox->setObjectName("y_turn_spinbox");
        y_turn_spinbox->setMinimum(1);
        y_turn_spinbox->setMaximum(100);
        y_turn_spinbox->setValue(50);

        horizontalLayout_21->addWidget(y_turn_spinbox);


        horizontalLayout_23->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName("label_17");

        horizontalLayout_22->addWidget(label_17);

        z_turn_spinbox = new QSpinBox(layoutWidget);
        z_turn_spinbox->setObjectName("z_turn_spinbox");
        z_turn_spinbox->setMinimum(1);
        z_turn_spinbox->setMaximum(100);
        z_turn_spinbox->setValue(50);

        horizontalLayout_22->addWidget(z_turn_spinbox);


        horizontalLayout_23->addLayout(horizontalLayout_22);


        gridLayout_4->addLayout(horizontalLayout_23, 1, 0, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");

        horizontalLayout_19->addWidget(label_10);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        horizontalLayout_14->addWidget(label_11);

        x_move_spinbox = new QSpinBox(layoutWidget);
        x_move_spinbox->setObjectName("x_move_spinbox");
        x_move_spinbox->setMinimum(1);
        x_move_spinbox->setMaximum(100);
        x_move_spinbox->setValue(50);

        horizontalLayout_14->addWidget(x_move_spinbox);


        horizontalLayout_19->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName("label_12");

        horizontalLayout_15->addWidget(label_12);

        y_move_spinbox = new QSpinBox(layoutWidget);
        y_move_spinbox->setObjectName("y_move_spinbox");
        y_move_spinbox->setMinimum(1);
        y_move_spinbox->setMaximum(100);
        y_move_spinbox->setValue(50);

        horizontalLayout_15->addWidget(y_move_spinbox);


        horizontalLayout_19->addLayout(horizontalLayout_15);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName("label_13");

        horizontalLayout_18->addWidget(label_13);

        z_move_spinbox = new QSpinBox(layoutWidget);
        z_move_spinbox->setObjectName("z_move_spinbox");
        z_move_spinbox->setMinimum(1);
        z_move_spinbox->setMaximum(100);
        z_move_spinbox->setValue(50);

        horizontalLayout_18->addWidget(z_move_spinbox);


        horizontalLayout_19->addLayout(horizontalLayout_18);


        gridLayout_4->addLayout(horizontalLayout_19, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 261, 88));
        gridLayout_5 = new QGridLayout(layoutWidget1);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName("pushButton");
        pushButton->setAutoFillBackground(false);

        gridLayout_5->addWidget(pushButton, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        render = new QPushButton(layoutWidget1);
        render->setObjectName("render");
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush9);
        render->setPalette(palette1);
        render->setFont(font);

        gridLayout_3->addWidget(render, 1, 0, 1, 1);

        select_obj = new QPushButton(layoutWidget1);
        select_obj->setObjectName("select_obj");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush10(QColor(240, 240, 172, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush11(QColor(247, 247, 213, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(120, 120, 86, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(160, 160, 115, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush14(QColor(120, 120, 86, 127));
        brush14.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        QBrush brush15(QColor(255, 255, 240, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush15);
        select_obj->setPalette(palette2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cooper Black")});
        select_obj->setFont(font2);

        gridLayout_3->addWidget(select_obj, 1, 1, 1, 1);

        file_path = new QLineEdit(layoutWidget1);
        file_path->setObjectName("file_path");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(file_path->sizePolicy().hasHeightForWidth());
        file_path->setSizePolicy(sizePolicy3);
        file_path->setReadOnly(true);

        gridLayout_3->addWidget(file_path, 0, 0, 1, 2);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 600, 271, 61));
        gridLayout_6 = new QGridLayout(layoutWidget2);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        edges = new QLabel(layoutWidget2);
        edges->setObjectName("edges");

        horizontalLayout_25->addWidget(edges);

        count_edge_info = new QLineEdit(layoutWidget2);
        count_edge_info->setObjectName("count_edge_info");
        count_edge_info->setReadOnly(true);

        horizontalLayout_25->addWidget(count_edge_info);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName("horizontalLayout_28");

        horizontalLayout_25->addLayout(horizontalLayout_28);

        vertices = new QLabel(layoutWidget2);
        vertices->setObjectName("vertices");

        horizontalLayout_25->addWidget(vertices);

        count_vertex_info = new QLineEdit(layoutWidget2);
        count_vertex_info->setObjectName("count_vertex_info");
        count_vertex_info->setReadOnly(true);

        horizontalLayout_25->addWidget(count_vertex_info);


        gridLayout_6->addLayout(horizontalLayout_25, 0, 0, 1, 1);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 320, 261, 71));
        horizontalLayout_29 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        horizontalLayout_29->setContentsMargins(0, 0, 0, 0);
        v_color_prev = new QLabel(layoutWidget3);
        v_color_prev->setObjectName("v_color_prev");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(v_color_prev->sizePolicy().hasHeightForWidth());
        v_color_prev->setSizePolicy(sizePolicy4);
        v_color_prev->setMinimumSize(QSize(34, 0));
        v_color_prev->setMaximumSize(QSize(40, 16777215));
        v_color_prev->setFrameShape(QFrame::Box);

        horizontalLayout_29->addWidget(v_color_prev);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        v_red_label = new QLabel(layoutWidget3);
        v_red_label->setObjectName("v_red_label");

        horizontalLayout->addWidget(v_red_label);

        v_red_slider = new QSlider(layoutWidget3);
        v_red_slider->setObjectName("v_red_slider");
        v_red_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(255, 147, 139);\n"
"}"));
        v_red_slider->setMaximum(255);
        v_red_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(v_red_slider);

        v_red_spinbox = new QSpinBox(layoutWidget3);
        v_red_spinbox->setObjectName("v_red_spinbox");
        v_red_spinbox->setMaximum(255);

        horizontalLayout->addWidget(v_red_spinbox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        v_green_label = new QLabel(layoutWidget3);
        v_green_label->setObjectName("v_green_label");

        horizontalLayout_2->addWidget(v_green_label);

        v_green_slider = new QSlider(layoutWidget3);
        v_green_slider->setObjectName("v_green_slider");
        v_green_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(181, 255, 183);\n"
"}"));
        v_green_slider->setMaximum(255);
        v_green_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(v_green_slider);

        v_green_spinbox = new QSpinBox(layoutWidget3);
        v_green_spinbox->setObjectName("v_green_spinbox");
        v_green_spinbox->setMaximum(255);

        horizontalLayout_2->addWidget(v_green_spinbox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        v_blue_label = new QLabel(layoutWidget3);
        v_blue_label->setObjectName("v_blue_label");

        horizontalLayout_4->addWidget(v_blue_label);

        v_blue_slider = new QSlider(layoutWidget3);
        v_blue_slider->setObjectName("v_blue_slider");
        v_blue_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(148, 209, 255);\n"
"}"));
        v_blue_slider->setMaximum(255);
        v_blue_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(v_blue_slider);

        v_blue_spinbox = new QSpinBox(layoutWidget3);
        v_blue_spinbox->setObjectName("v_blue_spinbox");
        v_blue_spinbox->setMaximum(255);

        horizontalLayout_4->addWidget(v_blue_spinbox);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_29->addLayout(verticalLayout);

        layoutWidget4 = new QWidget(groupBox);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 500, 261, 71));
        horizontalLayout_31 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        bg_color_prev = new QLabel(layoutWidget4);
        bg_color_prev->setObjectName("bg_color_prev");
        sizePolicy4.setHeightForWidth(bg_color_prev->sizePolicy().hasHeightForWidth());
        bg_color_prev->setSizePolicy(sizePolicy4);
        bg_color_prev->setMinimumSize(QSize(34, 0));
        bg_color_prev->setMaximumSize(QSize(40, 16777215));
        bg_color_prev->setFrameShape(QFrame::Box);

        horizontalLayout_31->addWidget(bg_color_prev);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        bg_red_label = new QLabel(layoutWidget4);
        bg_red_label->setObjectName("bg_red_label");

        horizontalLayout_11->addWidget(bg_red_label);

        bg_red_slider = new QSlider(layoutWidget4);
        bg_red_slider->setObjectName("bg_red_slider");
        bg_red_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(255, 147, 139);\n"
"}"));
        bg_red_slider->setMaximum(255);
        bg_red_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(bg_red_slider);

        bg_red_spinbox = new QSpinBox(layoutWidget4);
        bg_red_spinbox->setObjectName("bg_red_spinbox");
        bg_red_spinbox->setMaximum(255);

        horizontalLayout_11->addWidget(bg_red_spinbox);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        bg_green_label = new QLabel(layoutWidget4);
        bg_green_label->setObjectName("bg_green_label");

        horizontalLayout_12->addWidget(bg_green_label);

        bg_green_slider = new QSlider(layoutWidget4);
        bg_green_slider->setObjectName("bg_green_slider");
        bg_green_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(181, 255, 183);\n"
"}"));
        bg_green_slider->setMaximum(255);
        bg_green_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(bg_green_slider);

        bg_green_spinbox = new QSpinBox(layoutWidget4);
        bg_green_spinbox->setObjectName("bg_green_spinbox");
        bg_green_spinbox->setMaximum(255);

        horizontalLayout_12->addWidget(bg_green_spinbox);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        bg_blue_label = new QLabel(layoutWidget4);
        bg_blue_label->setObjectName("bg_blue_label");

        horizontalLayout_13->addWidget(bg_blue_label);

        bg_blue_slider = new QSlider(layoutWidget4);
        bg_blue_slider->setObjectName("bg_blue_slider");
        bg_blue_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(148, 209, 255);\n"
"}"));
        bg_blue_slider->setMaximum(255);
        bg_blue_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(bg_blue_slider);

        bg_blue_spinbox = new QSpinBox(layoutWidget4);
        bg_blue_spinbox->setObjectName("bg_blue_spinbox");
        bg_blue_spinbox->setMaximum(255);

        horizontalLayout_13->addWidget(bg_blue_spinbox);


        verticalLayout_3->addLayout(horizontalLayout_13);


        horizontalLayout_31->addLayout(verticalLayout_3);

        layoutWidget5 = new QWidget(groupBox);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(10, 410, 261, 71));
        horizontalLayout_30 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        horizontalLayout_30->setContentsMargins(0, 0, 0, 0);
        e_color_prev = new QLabel(layoutWidget5);
        e_color_prev->setObjectName("e_color_prev");
        sizePolicy4.setHeightForWidth(e_color_prev->sizePolicy().hasHeightForWidth());
        e_color_prev->setSizePolicy(sizePolicy4);
        e_color_prev->setMinimumSize(QSize(34, 0));
        e_color_prev->setMaximumSize(QSize(40, 16777215));
        e_color_prev->setFrameShape(QFrame::Box);

        horizontalLayout_30->addWidget(e_color_prev);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        e_red_label = new QLabel(layoutWidget5);
        e_red_label->setObjectName("e_red_label");

        horizontalLayout_7->addWidget(e_red_label);

        e_red_slider = new QSlider(layoutWidget5);
        e_red_slider->setObjectName("e_red_slider");
        e_red_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(255, 147, 139);\n"
"}"));
        e_red_slider->setMaximum(255);
        e_red_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(e_red_slider);

        e_red_spinbox = new QSpinBox(layoutWidget5);
        e_red_spinbox->setObjectName("e_red_spinbox");
        e_red_spinbox->setMaximum(255);

        horizontalLayout_7->addWidget(e_red_spinbox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        e_green_label = new QLabel(layoutWidget5);
        e_green_label->setObjectName("e_green_label");

        horizontalLayout_8->addWidget(e_green_label);

        e_green_slider = new QSlider(layoutWidget5);
        e_green_slider->setObjectName("e_green_slider");
        e_green_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(181, 255, 183);\n"
"}"));
        e_green_slider->setMaximum(255);
        e_green_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(e_green_slider);

        e_green_spinbox = new QSpinBox(layoutWidget5);
        e_green_spinbox->setObjectName("e_green_spinbox");
        e_green_spinbox->setMaximum(255);

        horizontalLayout_8->addWidget(e_green_spinbox);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        e_blue_label = new QLabel(layoutWidget5);
        e_blue_label->setObjectName("e_blue_label");

        horizontalLayout_9->addWidget(e_blue_label);

        e_blue_slider = new QSlider(layoutWidget5);
        e_blue_slider->setObjectName("e_blue_slider");
        e_blue_slider->setStyleSheet(QString::fromUtf8(".QSlider {\n"
"	height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(148, 209, 255);\n"
"}"));
        e_blue_slider->setMaximum(255);
        e_blue_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(e_blue_slider);

        e_blue_spinbox = new QSpinBox(layoutWidget5);
        e_blue_spinbox->setObjectName("e_blue_spinbox");
        e_blue_spinbox->setMaximum(255);

        horizontalLayout_9->addWidget(e_blue_spinbox);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_30->addLayout(verticalLayout_2);

        layoutWidget6 = new QWidget(groupBox);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(10, 230, 261, 29));
        horizontalLayout_34 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_34->setObjectName("horizontalLayout_34");
        horizontalLayout_34->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        label_7 = new QLabel(layoutWidget6);
        label_7->setObjectName("label_7");

        horizontalLayout_32->addWidget(label_7);

        line_type = new QComboBox(layoutWidget6);
        line_type->addItem(QString());
        line_type->addItem(QString());
        line_type->setObjectName("line_type");

        horizontalLayout_32->addWidget(line_type);


        horizontalLayout_34->addLayout(horizontalLayout_32);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName("horizontalLayout_33");
        label_9 = new QLabel(layoutWidget6);
        label_9->setObjectName("label_9");

        horizontalLayout_33->addWidget(label_9);

        line_thickness = new QSpinBox(layoutWidget6);
        line_thickness->setObjectName("line_thickness");
        line_thickness->setMinimum(1);
        line_thickness->setMaximum(50);

        horizontalLayout_33->addWidget(line_thickness);


        horizontalLayout_34->addLayout(horizontalLayout_33);

        layoutWidget7 = new QWidget(groupBox);
        layoutWidget7->setObjectName("layoutWidget7");
        layoutWidget7->setGeometry(QRect(10, 200, 261, 29));
        horizontalLayout_37 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_37->setObjectName("horizontalLayout_37");
        horizontalLayout_37->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName("horizontalLayout_36");
        label_2 = new QLabel(layoutWidget7);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_36->addWidget(label_2);

        vertex_type = new QComboBox(layoutWidget7);
        vertex_type->addItem(QString());
        vertex_type->addItem(QString());
        vertex_type->addItem(QString());
        vertex_type->setObjectName("vertex_type");

        horizontalLayout_36->addWidget(vertex_type);


        horizontalLayout_37->addLayout(horizontalLayout_36);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName("horizontalLayout_35");
        label_4 = new QLabel(layoutWidget7);
        label_4->setObjectName("label_4");
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);

        horizontalLayout_35->addWidget(label_4);

        vertex_size = new QSpinBox(layoutWidget7);
        vertex_size->setObjectName("vertex_size");
        vertex_size->setMinimum(1);
        vertex_size->setMaximum(50);

        horizontalLayout_35->addWidget(vertex_size);


        horizontalLayout_37->addLayout(horizontalLayout_35);

        layoutWidget8 = new QWidget(groupBox);
        layoutWidget8->setObjectName("layoutWidget8");
        layoutWidget8->setGeometry(QRect(30, 270, 231, 26));
        horizontalLayout_26 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        horizontalLayout_26->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget8);
        label->setObjectName("label");
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        horizontalLayout_26->addWidget(label);

        projection_type = new QComboBox(layoutWidget8);
        projection_type->addItem(QString());
        projection_type->addItem(QString());
        projection_type->setObjectName("projection_type");

        horizontalLayout_26->addWidget(projection_type);

        screenshot_btn = new QPushButton(groupBox);
        screenshot_btn->setObjectName("screenshot_btn");
        screenshot_btn->setGeometry(QRect(160, 110, 80, 22));
        screenshot_btn->setMaximumSize(QSize(82, 16777215));
        gif_btn = new QPushButton(groupBox);
        gif_btn->setObjectName("gif_btn");
        gif_btn->setGeometry(QRect(70, 110, 30, 22));
        gif_btn->setMaximumSize(QSize(30, 16777215));
        layoutWidget9 = new QWidget(groupBox);
        layoutWidget9->setObjectName("layoutWidget9");
        layoutWidget9->setGeometry(QRect(10, 580, 269, 31));
        horizontalLayout_27 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget9);
        label_20->setObjectName("label_20");
        label_20->setMinimumSize(QSize(60, 0));
        label_20->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_27->addWidget(label_20);

        filename_info = new QLineEdit(layoutWidget9);
        filename_info->setObjectName("filename_info");
        filename_info->setMinimumSize(QSize(130, 0));
        filename_info->setMaximumSize(QSize(150, 16777215));
        filename_info->setReadOnly(true);

        horizontalLayout_27->addWidget(filename_info);


        horizontalLayout_16->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1033, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);
        QObject::connect(v_red_slider, &QSlider::valueChanged, v_red_spinbox, &QSpinBox::setValue);
        QObject::connect(v_green_slider, &QSlider::valueChanged, v_green_spinbox, &QSpinBox::setValue);
        QObject::connect(v_blue_slider, &QSlider::valueChanged, v_blue_spinbox, &QSpinBox::setValue);
        QObject::connect(v_red_spinbox, &QSpinBox::valueChanged, v_red_slider, &QSlider::setValue);
        QObject::connect(v_green_spinbox, &QSpinBox::valueChanged, v_green_slider, &QSlider::setValue);
        QObject::connect(v_blue_spinbox, &QSpinBox::valueChanged, v_blue_slider, &QSlider::setValue);
        QObject::connect(e_red_slider, &QSlider::valueChanged, e_red_spinbox, &QSpinBox::setValue);
        QObject::connect(e_green_slider, &QSlider::valueChanged, e_green_spinbox, &QSpinBox::setValue);
        QObject::connect(e_blue_slider, &QSlider::valueChanged, e_blue_spinbox, &QSpinBox::setValue);
        QObject::connect(e_blue_spinbox, &QSpinBox::valueChanged, e_blue_slider, &QSlider::setValue);
        QObject::connect(e_green_spinbox, &QSpinBox::valueChanged, e_green_slider, &QSlider::setValue);
        QObject::connect(e_red_spinbox, &QSpinBox::valueChanged, e_red_slider, &QSlider::setValue);
        QObject::connect(bg_red_slider, &QSlider::valueChanged, bg_red_spinbox, &QSpinBox::setValue);
        QObject::connect(bg_red_spinbox, &QSpinBox::valueChanged, bg_red_slider, &QSlider::setValue);
        QObject::connect(bg_green_slider, &QSlider::valueChanged, bg_green_spinbox, &QSpinBox::setValue);
        QObject::connect(bg_blue_slider, &QSlider::valueChanged, bg_blue_spinbox, &QSpinBox::setValue);
        QObject::connect(bg_green_spinbox, &QSpinBox::valueChanged, bg_green_slider, &QSlider::setValue);
        QObject::connect(bg_blue_spinbox, &QSpinBox::valueChanged, bg_blue_slider, &QSlider::setValue);
        QObject::connect(pushButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Color vertex:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Color background:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Rotation:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Offset:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        render->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        select_obj->setText(QCoreApplication::translate("MainWindow", "Select file", nullptr));
        edges->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        vertices->setText(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        v_color_prev->setText(QString());
        v_red_label->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        v_green_label->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        v_blue_label->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        bg_color_prev->setText(QString());
        bg_red_label->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        bg_green_label->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        bg_blue_label->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        e_color_prev->setText(QString());
        e_red_label->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        e_green_label->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        e_blue_label->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Edges</p></body></html>", nullptr));
        line_type->setItemText(0, QCoreApplication::translate("MainWindow", "solid", nullptr));
        line_type->setItemText(1, QCoreApplication::translate("MainWindow", "dashed", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Vertex</p></body></html>", nullptr));
        vertex_type->setItemText(0, QCoreApplication::translate("MainWindow", "<none>", nullptr));
        vertex_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\272\321\200\321\203\320\263", nullptr));
        vertex_type->setItemText(2, QCoreApplication::translate("MainWindow", "\320\272\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "type of projection", nullptr));
        projection_type->setItemText(0, QCoreApplication::translate("MainWindow", "parallel", nullptr));
        projection_type->setItemText(1, QCoreApplication::translate("MainWindow", "central", nullptr));

        screenshot_btn->setText(QCoreApplication::translate("MainWindow", "Screenshot", nullptr));
        gif_btn->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Filename:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
