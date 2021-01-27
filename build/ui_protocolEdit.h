/********************************************************************************
** Form generated from reading UI file 'protocolEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOCOLEDIT_H
#define UI_PROTOCOLEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(634, 319);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/images/icons8-adjust-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 611, 301));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 6, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 3, 1, 1);

        listWidget = new QListWidget(widget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 8, 1);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(false);
        checkBox->setTristate(false);

        gridLayout->addWidget(checkBox, 6, 5, 1, 1);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 5, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 5, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 3, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Edit Protocol Description", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Command", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Meaning", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Dialog", "1", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Dialog", "2", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Dialog", "3", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("Dialog", "4", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("Dialog", "5", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("Dialog", "6", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("Dialog", "7", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("Dialog", "8", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("Dialog", "9", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("Dialog", "A", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("Dialog", "B", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("Dialog", "C", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("Dialog", "D", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("Dialog", "E", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = listWidget->item(15);
        ___qlistwidgetitem15->setText(QCoreApplication::translate("Dialog", "F", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = listWidget->item(16);
        ___qlistwidgetitem16->setText(QCoreApplication::translate("Dialog", "10", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = listWidget->item(17);
        ___qlistwidgetitem17->setText(QCoreApplication::translate("Dialog", "11", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = listWidget->item(18);
        ___qlistwidgetitem18->setText(QCoreApplication::translate("Dialog", "12", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = listWidget->item(19);
        ___qlistwidgetitem19->setText(QCoreApplication::translate("Dialog", "13", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = listWidget->item(20);
        ___qlistwidgetitem20->setText(QCoreApplication::translate("Dialog", "14", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = listWidget->item(21);
        ___qlistwidgetitem21->setText(QCoreApplication::translate("Dialog", "15", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = listWidget->item(22);
        ___qlistwidgetitem22->setText(QCoreApplication::translate("Dialog", "16", nullptr));
        QListWidgetItem *___qlistwidgetitem23 = listWidget->item(23);
        ___qlistwidgetitem23->setText(QCoreApplication::translate("Dialog", "17", nullptr));
        QListWidgetItem *___qlistwidgetitem24 = listWidget->item(24);
        ___qlistwidgetitem24->setText(QCoreApplication::translate("Dialog", "18", nullptr));
        QListWidgetItem *___qlistwidgetitem25 = listWidget->item(25);
        ___qlistwidgetitem25->setText(QCoreApplication::translate("Dialog", "19", nullptr));
        QListWidgetItem *___qlistwidgetitem26 = listWidget->item(26);
        ___qlistwidgetitem26->setText(QCoreApplication::translate("Dialog", "1A", nullptr));
        QListWidgetItem *___qlistwidgetitem27 = listWidget->item(27);
        ___qlistwidgetitem27->setText(QCoreApplication::translate("Dialog", "1B", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        checkBox->setText(QCoreApplication::translate("Dialog", "Subcommands", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOCOLEDIT_H
