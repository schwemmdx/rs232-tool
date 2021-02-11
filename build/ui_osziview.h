/********************************************************************************
** Form generated from reading UI file 'osziview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSZIVIEW_H
#define UI_OSZIVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OsziView
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *escapeCmd;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *graph_Layout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox;
    QComboBox *yValueTypeBox;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *OsziView)
    {
        if (OsziView->objectName().isEmpty())
            OsziView->setObjectName(QString::fromUtf8("OsziView"));
        OsziView->setWindowModality(Qt::WindowModal);
        OsziView->resize(955, 629);
        gridLayout = new QGridLayout(OsziView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(OsziView);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 2, 2, 1, 1);

        escapeCmd = new QLineEdit(OsziView);
        escapeCmd->setObjectName(QString::fromUtf8("escapeCmd"));

        gridLayout_2->addWidget(escapeCmd, 2, 16, 1, 1);

        toolButton = new QToolButton(OsziView);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        gridLayout_2->addWidget(toolButton, 2, 17, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 14, 1, 1);

        graph_Layout = new QGridLayout();
        graph_Layout->setObjectName(QString::fromUtf8("graph_Layout"));

        gridLayout_2->addLayout(graph_Layout, 0, 1, 1, 17);

        label_2 = new QLabel(OsziView);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 15, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 13, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 8, 1, 1);

        comboBox = new QComboBox(OsziView);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 2, 7, 1, 1);

        yValueTypeBox = new QComboBox(OsziView);
        yValueTypeBox->addItem(QString());
        yValueTypeBox->addItem(QString());
        yValueTypeBox->setObjectName(QString::fromUtf8("yValueTypeBox"));

        gridLayout_2->addWidget(yValueTypeBox, 2, 3, 1, 1);

        label_3 = new QLabel(OsziView);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 9, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);


        retranslateUi(OsziView);

        QMetaObject::connectSlotsByName(OsziView);
    } // setupUi

    void retranslateUi(QWidget *OsziView)
    {
        OsziView->setWindowTitle(QCoreApplication::translate("OsziView", "Form", nullptr));
        label->setText(QCoreApplication::translate("OsziView", "Y-Axis Format ", nullptr));
        escapeCmd->setText(QCoreApplication::translate("OsziView", "None", nullptr));
        toolButton->setText(QCoreApplication::translate("OsziView", "...", nullptr));
        label_2->setText(QCoreApplication::translate("OsziView", "Escape Character ", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("OsziView", "Item #", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("OsziView", "Timestamp", nullptr));

        yValueTypeBox->setItemText(0, QCoreApplication::translate("OsziView", "Decimal", nullptr));
        yValueTypeBox->setItemText(1, QCoreApplication::translate("OsziView", "Hex", nullptr));

        label_3->setText(QCoreApplication::translate("OsziView", " X-Axis Format ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OsziView: public Ui_OsziView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSZIVIEW_H
