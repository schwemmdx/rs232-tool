/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QAction *actionSave_all;
    QAction *actionSave_Rx;
    QAction *actionSave_Tx;
    QAction *actionInfo;
    QAction *actionHelp;
    QAction *actionClear_Rx;
    QAction *actionClear_Tx;
    QAction *actionNew;
    QAction *actionLoad;
    QAction *actionEdit;
    QAction *actionNew_Graph;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *listTab;
    QWidget *layoutWidget;
    QGridLayout *mainListLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QListWidget *rxList;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *lastCmd;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QListWidget *txList;
    QLineEdit *txSendField;
    QPushButton *sendBtn;
    QSpacerItem *verticalSpacer;
    QWidget *graphTab;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QLineEdit *idicationCmd;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *graphLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelpo;
    QMenu *menuProtocol;
    QMenu *menuGraph;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1013, 711);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/images/icons8-rs-232-male-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/images/icons8-usb-connected-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/images/icons8-usb-disconnected-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/images/icons8-services-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon3);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imgs/images/icons8-clear-symbol-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon5);
        actionSave_all = new QAction(MainWindow);
        actionSave_all->setObjectName(QString::fromUtf8("actionSave_all"));
        actionSave_Rx = new QAction(MainWindow);
        actionSave_Rx->setObjectName(QString::fromUtf8("actionSave_Rx"));
        actionSave_Tx = new QAction(MainWindow);
        actionSave_Tx->setObjectName(QString::fromUtf8("actionSave_Tx"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionClear_Rx = new QAction(MainWindow);
        actionClear_Rx->setObjectName(QString::fromUtf8("actionClear_Rx"));
        actionClear_Tx = new QAction(MainWindow);
        actionClear_Tx->setObjectName(QString::fromUtf8("actionClear_Tx"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionNew_Graph = new QAction(MainWindow);
        actionNew_Graph->setObjectName(QString::fromUtf8("actionNew_Graph"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setUnderline(false);
        tabWidget->setFont(font);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(false);
        listTab = new QWidget();
        listTab->setObjectName(QString::fromUtf8("listTab"));
        layoutWidget = new QWidget(listTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 971, 541));
        mainListLayout = new QGridLayout(layoutWidget);
        mainListLayout->setSpacing(6);
        mainListLayout->setContentsMargins(11, 11, 11, 11);
        mainListLayout->setObjectName(QString::fromUtf8("mainListLayout"));
        mainListLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setBold(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setKerning(false);
        groupBox->setFont(font1);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        rxList = new QListWidget(groupBox);
        rxList->setObjectName(QString::fromUtf8("rxList"));
        rxList->setDragEnabled(false);
        rxList->setAlternatingRowColors(true);
        rxList->setModelColumn(0);

        gridLayout_3->addWidget(rxList, 0, 0, 1, 5);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        lastCmd = new QLabel(groupBox);
        lastCmd->setObjectName(QString::fromUtf8("lastCmd"));

        gridLayout_3->addWidget(lastCmd, 1, 1, 1, 1);


        mainListLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txList = new QListWidget(groupBox_2);
        txList->setObjectName(QString::fromUtf8("txList"));

        gridLayout_2->addWidget(txList, 0, 0, 1, 2);

        txSendField = new QLineEdit(groupBox_2);
        txSendField->setObjectName(QString::fromUtf8("txSendField"));
        txSendField->setEnabled(false);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Source Code Pro"));
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        font2.setKerning(false);
        txSendField->setFont(font2);

        gridLayout_2->addWidget(txSendField, 1, 0, 1, 1);

        sendBtn = new QPushButton(groupBox_2);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setLayoutDirection(Qt::RightToLeft);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imgs/images/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendBtn->setIcon(icon6);
        sendBtn->setFlat(false);

        gridLayout_2->addWidget(sendBtn, 1, 1, 1, 1);


        mainListLayout->addWidget(groupBox_2, 0, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainListLayout->addItem(verticalSpacer, 0, 3, 1, 1);

        tabWidget->addTab(listTab, QString());
        graphTab = new QWidget();
        graphTab->setObjectName(QString::fromUtf8("graphTab"));
        layoutWidget1 = new QWidget(graphTab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(9, 10, 971, 561));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        idicationCmd = new QLineEdit(layoutWidget1);
        idicationCmd->setObjectName(QString::fromUtf8("idicationCmd"));

        gridLayout_4->addWidget(idicationCmd, 1, 8, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 7, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        graphLayout = new QGridLayout();
        graphLayout->setSpacing(6);
        graphLayout->setObjectName(QString::fromUtf8("graphLayout"));

        gridLayout_4->addLayout(graphLayout, 0, 1, 1, 8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 1, 6, 1, 1);

        tabWidget->addTab(graphTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Fira Sans"));
        mainToolBar->setFont(font3);
        mainToolBar->setAutoFillBackground(false);
        mainToolBar->setMovable(true);
        mainToolBar->setAllowedAreas(Qt::AllToolBarAreas);
        mainToolBar->setOrientation(Qt::Horizontal);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 22));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QString::fromUtf8("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelpo = new QMenu(menuBar);
        menuHelpo->setObjectName(QString::fromUtf8("menuHelpo"));
        menuProtocol = new QMenu(menuBar);
        menuProtocol->setObjectName(QString::fromUtf8("menuProtocol"));
        menuGraph = new QMenu(menuBar);
        menuGraph->setObjectName(QString::fromUtf8("menuGraph"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionClear);
        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuProtocol->menuAction());
        menuBar->addAction(menuGraph->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelpo->menuAction());
        menuCalls->addAction(actionConfigure);
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionClear);
        menuTools->addSeparator();
        menuTools->addAction(actionClear_Tx);
        menuTools->addAction(actionClear_Rx);
        menuTools->addSeparator();
        menuTools->addAction(actionSave_all);
        menuTools->addAction(actionSave_Rx);
        menuTools->addAction(actionSave_Tx);
        menuHelpo->addAction(actionInfo);
        menuHelpo->addAction(actionHelp);
        menuProtocol->addAction(actionNew);
        menuProtocol->addAction(actionLoad);
        menuProtocol->addAction(actionEdit);
        menuGraph->addAction(actionNew_Graph);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        rxList->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RS 232 Tool", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "About program", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAboutQt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "C&onnect", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect->setToolTip(QCoreApplication::translate("MainWindow", "Connect to serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "&Disconnect", nullptr));
#if QT_CONFIG(tooltip)
        actionDisconnect->setToolTip(QCoreApplication::translate("MainWindow", "Disconnect from serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionDisconnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "&Configure", nullptr));
#if QT_CONFIG(tooltip)
        actionConfigure->setToolTip(QCoreApplication::translate("MainWindow", "Configure serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConfigure->setShortcut(QCoreApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear->setText(QCoreApplication::translate("MainWindow", "C&lear All", nullptr));
#if QT_CONFIG(tooltip)
        actionClear->setToolTip(QCoreApplication::translate("MainWindow", "Clear data", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClear->setShortcut(QCoreApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_all->setText(QCoreApplication::translate("MainWindow", "Save all", nullptr));
        actionSave_Rx->setText(QCoreApplication::translate("MainWindow", "Save Rx", nullptr));
        actionSave_Tx->setText(QCoreApplication::translate("MainWindow", "Save Tx", nullptr));
        actionInfo->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
#if QT_CONFIG(shortcut)
        actionHelp->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear_Rx->setText(QCoreApplication::translate("MainWindow", "Clear Rx", nullptr));
        actionClear_Tx->setText(QCoreApplication::translate("MainWindow", "Clear Tx", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        actionNew_Graph->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Recieving ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Last Command :", nullptr));
        lastCmd->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Sending", nullptr));
        sendBtn->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(listTab), QCoreApplication::translate("MainWindow", "List View", nullptr));
        idicationCmd->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Escape Character", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(graphTab), QCoreApplication::translate("MainWindow", "Scope", nullptr));
        menuCalls->setTitle(QCoreApplication::translate("MainWindow", "Session", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Log", nullptr));
        menuHelpo->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuProtocol->setTitle(QCoreApplication::translate("MainWindow", "Protocol", nullptr));
        menuGraph->setTitle(QCoreApplication::translate("MainWindow", "Scope", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
