/********************************************************************************
** Form generated from reading UI file 'dlrdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLRDIALOG_H
#define UI_DLRDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlrDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QPushButton *valve_0_Btn;
    QLabel *label_5;
    QPushButton *valve_1_Btn;
    QLabel *label_6;
    QPushButton *flushBtn;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout;
    QSlider *rpmSlider;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *rpmSpinner;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QPushButton *pump_Btn;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *closeBtn;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *updateBtn;
    QSpinBox *preStartSpinner;
    QSpinBox *flushTimeSpinner;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_3;
    QSpinBox *postStopSpinner;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_5;
    QSlider *heaterSlider;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *heaterSpinner;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *saveBtn;
    QPushButton *loadBtn;

    void setupUi(QDialog *DlrDialog)
    {
        if (DlrDialog->objectName().isEmpty())
            DlrDialog->setObjectName(QString::fromUtf8("DlrDialog"));
        DlrDialog->setWindowModality(Qt::NonModal);
        DlrDialog->resize(380, 712);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/images/dlr_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DlrDialog->setWindowIcon(icon);
        DlrDialog->setWindowOpacity(1.000000000000000);
        DlrDialog->setSizeGripEnabled(false);
        layoutWidget = new QWidget(DlrDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 361, 691));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_9 = new QGridLayout(groupBox_2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 2, 1);

        valve_0_Btn = new QPushButton(groupBox_2);
        valve_0_Btn->setObjectName(QString::fromUtf8("valve_0_Btn"));
        valve_0_Btn->setCheckable(true);
        valve_0_Btn->setAutoDefault(false);

        gridLayout_2->addWidget(valve_0_Btn, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        valve_1_Btn = new QPushButton(groupBox_2);
        valve_1_Btn->setObjectName(QString::fromUtf8("valve_1_Btn"));
        valve_1_Btn->setCheckable(true);
        valve_1_Btn->setAutoDefault(false);

        gridLayout_2->addWidget(valve_1_Btn, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        flushBtn = new QPushButton(groupBox_2);
        flushBtn->setObjectName(QString::fromUtf8("flushBtn"));
        flushBtn->setCheckable(true);
        flushBtn->setAutoDefault(false);

        gridLayout_2->addWidget(flushBtn, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 4);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rpmSlider = new QSlider(groupBox);
        rpmSlider->setObjectName(QString::fromUtf8("rpmSlider"));
        rpmSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rpmSlider, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        rpmSpinner = new QSpinBox(groupBox);
        rpmSpinner->setObjectName(QString::fromUtf8("rpmSpinner"));
        rpmSpinner->setEnabled(true);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        rpmSpinner->setFont(font);
        rpmSpinner->setFrame(true);
        rpmSpinner->setReadOnly(false);
        rpmSpinner->setAccelerated(true);
        rpmSpinner->setProperty("showGroupSeparator", QVariant(false));
        rpmSpinner->setMaximum(100);
        rpmSpinner->setValue(0);

        gridLayout->addWidget(rpmSpinner, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        pump_Btn = new QPushButton(groupBox);
        pump_Btn->setObjectName(QString::fromUtf8("pump_Btn"));
        pump_Btn->setCheckable(true);
        pump_Btn->setAutoDefault(false);

        gridLayout->addWidget(pump_Btn, 4, 3, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 2, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 4);

        closeBtn = new QPushButton(layoutWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setAutoDefault(false);

        gridLayout_4->addWidget(closeBtn, 5, 0, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 4, 1, 1, 1);

        updateBtn = new QPushButton(groupBox_3);
        updateBtn->setObjectName(QString::fromUtf8("updateBtn"));
        updateBtn->setAutoDefault(false);

        gridLayout_3->addWidget(updateBtn, 4, 2, 1, 3);

        preStartSpinner = new QSpinBox(groupBox_3);
        preStartSpinner->setObjectName(QString::fromUtf8("preStartSpinner"));
        preStartSpinner->setAccelerated(true);
        preStartSpinner->setMaximum(65534);
        preStartSpinner->setSingleStep(1);

        gridLayout_3->addWidget(preStartSpinner, 1, 2, 1, 1);

        flushTimeSpinner = new QSpinBox(groupBox_3);
        flushTimeSpinner->setObjectName(QString::fromUtf8("flushTimeSpinner"));
        flushTimeSpinner->setAccelerated(true);
        flushTimeSpinner->setMinimum(10);
        flushTimeSpinner->setMaximum(65634);

        gridLayout_3->addWidget(flushTimeSpinner, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 2, 4, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 4, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 0, 4, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        postStopSpinner = new QSpinBox(groupBox_3);
        postStopSpinner->setObjectName(QString::fromUtf8("postStopSpinner"));
        postStopSpinner->setAccelerated(true);
        postStopSpinner->setMaximum(65534);

        gridLayout_3->addWidget(postStopSpinner, 2, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 3, 0, 1, 4);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        heaterSlider = new QSlider(groupBox_4);
        heaterSlider->setObjectName(QString::fromUtf8("heaterSlider"));
        heaterSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(heaterSlider, 0, 2, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        heaterSpinner = new QSpinBox(groupBox_4);
        heaterSpinner->setObjectName(QString::fromUtf8("heaterSpinner"));
        heaterSpinner->setEnabled(true);
        heaterSpinner->setFont(font);
        heaterSpinner->setFrame(true);
        heaterSpinner->setReadOnly(false);
        heaterSpinner->setAccelerated(true);
        heaterSpinner->setProperty("showGroupSeparator", QVariant(false));
        heaterSpinner->setMaximum(100);
        heaterSpinner->setValue(0);

        gridLayout_5->addWidget(heaterSpinner, 0, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 1, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 2, 0, 1, 4);

        saveBtn = new QPushButton(layoutWidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setAutoDefault(false);

        gridLayout_4->addWidget(saveBtn, 5, 3, 1, 1);

        loadBtn = new QPushButton(layoutWidget);
        loadBtn->setObjectName(QString::fromUtf8("loadBtn"));
        loadBtn->setAutoDefault(false);

        gridLayout_4->addWidget(loadBtn, 5, 2, 1, 1);


        retranslateUi(DlrDialog);

        QMetaObject::connectSlotsByName(DlrDialog);
    } // setupUi

    void retranslateUi(QDialog *DlrDialog)
    {
        DlrDialog->setWindowTitle(QCoreApplication::translate("DlrDialog", "DLR Plugin ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DlrDialog", "Valve control", nullptr));
        label_4->setText(QCoreApplication::translate("DlrDialog", "Valve 0", nullptr));
        valve_0_Btn->setText(QCoreApplication::translate("DlrDialog", "On", nullptr));
        label_5->setText(QCoreApplication::translate("DlrDialog", "Valve 1", nullptr));
        valve_1_Btn->setText(QCoreApplication::translate("DlrDialog", "On", nullptr));
        label_6->setText(QCoreApplication::translate("DlrDialog", "Flush Valve", nullptr));
        flushBtn->setText(QCoreApplication::translate("DlrDialog", "On", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlrDialog", "Vacuumpump", nullptr));
        rpmSpinner->setPrefix(QString());
        label_2->setText(QCoreApplication::translate("DlrDialog", "RPM", nullptr));
        pump_Btn->setText(QCoreApplication::translate("DlrDialog", "On", nullptr));
        closeBtn->setText(QCoreApplication::translate("DlrDialog", "Close", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DlrDialog", "Application Values", nullptr));
        label->setText(QCoreApplication::translate("DlrDialog", "Pump pre-start", nullptr));
        updateBtn->setText(QCoreApplication::translate("DlrDialog", "Update Values", nullptr));
        label_7->setText(QCoreApplication::translate("DlrDialog", "Flush Time", nullptr));
        label_9->setText(QCoreApplication::translate("DlrDialog", "ms", nullptr));
        label_8->setText(QCoreApplication::translate("DlrDialog", "ms", nullptr));
        label_10->setText(QCoreApplication::translate("DlrDialog", "ms", nullptr));
        label_3->setText(QCoreApplication::translate("DlrDialog", "Pump post-stop", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("DlrDialog", "Heater", nullptr));
        label_11->setText(QCoreApplication::translate("DlrDialog", "Power", nullptr));
        heaterSpinner->setPrefix(QString());
        saveBtn->setText(QCoreApplication::translate("DlrDialog", "Save", nullptr));
        loadBtn->setText(QCoreApplication::translate("DlrDialog", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlrDialog: public Ui_DlrDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLRDIALOG_H
