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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OsziView
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *escapeCmd;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *graph_Layout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *OsziView)
    {
        if (OsziView->objectName().isEmpty())
            OsziView->setObjectName(QString::fromUtf8("OsziView"));
        OsziView->setWindowModality(Qt::WindowModal);
        OsziView->resize(955, 629);
        gridLayout = new QGridLayout(OsziView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        escapeCmd = new QLineEdit(OsziView);
        escapeCmd->setObjectName(QString::fromUtf8("escapeCmd"));

        gridLayout_2->addWidget(escapeCmd, 1, 8, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label_2 = new QLabel(OsziView);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 7, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        graph_Layout = new QGridLayout();
        graph_Layout->setObjectName(QString::fromUtf8("graph_Layout"));

        gridLayout_2->addLayout(graph_Layout, 0, 1, 1, 8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 6, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(OsziView);

        QMetaObject::connectSlotsByName(OsziView);
    } // setupUi

    void retranslateUi(QWidget *OsziView)
    {
        OsziView->setWindowTitle(QCoreApplication::translate("OsziView", "Form", nullptr));
        escapeCmd->setText(QCoreApplication::translate("OsziView", "None", nullptr));
        label_2->setText(QCoreApplication::translate("OsziView", "Escape Character", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OsziView: public Ui_OsziView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSZIVIEW_H
