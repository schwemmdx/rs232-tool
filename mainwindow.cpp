
#include "mainwindow.h"

#include "listentry.h"
#include "osziview.h"
#include "readingthread.h"
#include "settingsdialog.h"
#include "ui_mainwindow.h"
#include "writingthread.h"
#include "loopdialog.h"
#include "gamepad_dialog.h"
#include "gamepadthread.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QStatusBar>
#include <QString>
#include <QDebug>
#include <QVector>

MainWindow::MainWindow()
{
  statusBar()->showMessage("Disconnected");


  setupUi(this);
  setCentralWidget(tabWidget);

  initActionsConnections();
  addOscillatorView();

  connect(&m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
  connect(&m_serial, &QSerialPort::readyRead, &readingThread, &ReadingThread::read);
  connect(&readingThread, &ReadingThread::recvReady, this, &MainWindow::addReadData);
  connect(&writingThread, &WritingThread::sendSucessful, this, &MainWindow::addWriteData);
  connect(&m_gamepadDialog,&Gamepad_dialog::configChanged,&gamepadThread,&GamepadThread::updateConfig);
  connect(&gamepadThread,&GamepadThread::sendCmd,&writingThread, &WritingThread::sendData);
  connect(&m_loopDialog,&LoopDialog::sendCmd,&writingThread,&WritingThread::sendData);
  connect(&m_settings,&SettingsDialog::settingsApplied,&readingThread,&ReadingThread::applySettings);
  connect(&m_gamepadDialog,&Gamepad_dialog::devListRefreshRequest,this,&MainWindow::refreshGamepadList);
  connect(tabWidget->tabBar(), &QTabBar::tabBarDoubleClicked,this, &MainWindow::on_tabWidget_tabBarDoubleClicked);
  connect(tabWidget->tabBar(), &QTabBar::tabCloseRequested,this, &MainWindow::on_tabWidget_tabCloseRequested);

}
MainWindow::~MainWindow()
{
  removeAllOscillatorViews();
}

//! [4]
void MainWindow::openSerialPort()
{
  SettingsDialog::Settings p = m_settings.getSettings();
  m_serial.setPortName(p.name);
  m_serial.setBaudRate(p.baudRate);
  m_serial.setDataBits(p.dataBits);
  m_serial.setParity(p.parity);
  m_serial.setStopBits(p.stopBits);
  m_serial.setFlowControl(p.flowControl);



  if (m_serial.open(QIODevice::ReadWrite))
  {
    actionConnect->setEnabled(false);
    actionDisconnect->setEnabled(true);
    actionConfigure->setEnabled(false);
    actionExecute_Script->setEnabled(true);
    actionLoop_Command->setEnabled(true);
    actionGamepad->setEnabled(true);
    actionKeyboard->setEnabled(true);


    txSendField->setEnabled(true);

    readingThread.applySettings(&p);
    writingThread.applySettings(&p);

    readingThread.start();
    writingThread.start();
    gamepadThread.start();

    readingThread.setPriority(QThread::HighestPriority);
    writingThread.setPriority(QThread::HighPriority);

    this->connectionStatus = QString(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                         .arg(p.name)
                                         .arg(p.stringBaudRate)
                                         .arg(p.stringDataBits)
                                         .arg(p.stringParity)
                                         .arg(p.stringStopBits)
                                         .arg(p.stringFlowControl));
    showStatusMessage(this->connectionStatus + "\t" + this->usedProtocol);
  }
  else
  {
    QMessageBox::critical(this, tr("Error"), tr("Could <b>not</b> connect to Serial Port!<p>Check Connection Settings</p>"));
    showStatusMessage(tr("Open error"));
  }
}

void MainWindow::closeSerialPort()
{
  readingThread.stop();
  writingThread.stop();
  gamepadThread.stop();

  if (m_serial.isOpen())
  {
    m_serial.close();
  }
  // m_console->setEnabled(false);
  actionConnect->setEnabled(true);
  actionDisconnect->setEnabled(false);
  actionConfigure->setEnabled(true);
  txSendField->setEnabled(false);
  actionExecute_Script->setEnabled(false);
  actionLoop_Command->setEnabled(false);
  actionGamepad->setEnabled(false);
  actionKeyboard->setEnabled(false);

  this->connectionStatus = tr("Disconnected");
  showStatusMessage(this->connectionStatus + "\t" + this->usedProtocol);
}
//! [5]

//! [6]
void MainWindow::addWriteData(QString writtenData)
{

  if(m_settings.getSettings().txType == SettingsDialog::InterpretType::TYPE_STRING)
  {
      writtenData = writtenData.remove('\n').remove('\r');
  }
  parsedWriteCommand = timeStamp.getEnty(writtenData);
  txList->insertItem(0,parsedWriteCommand);
  txSendField->clear();
}
//! [6]

//! [7]
void MainWindow::addReadData()
{
   QList<QString> rxCmdList;
  QString cmdBuf;
  rxCmdList = readingThread.getRecievedCmds();
  for(auto &cmd: rxCmdList)
    {
      if(m_settings.getSettings().rxType == SettingsDialog::InterpretType::TYPE_STRING)
        {
            cmd = cmd.remove('\n').remove('\r');
        }

    emit newCommandParsed(cmd);
    cmdBuf = cmd;
    this->lastCmd->setText(cmdBuf);
    cmdBuf = this->timeStamp.getEnty(cmdBuf);
    this->rxList->insertItem(0, cmdBuf);

    }

}

//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
  if (error == QSerialPort::ResourceError)
  {
    QMessageBox::critical(this, tr("Critical Error"), m_serial.errorString());
    closeSerialPort();
  }
}
//! [8]

void MainWindow::initActionsConnections()
{
  connect(actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
  connect(actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
  connect(actionQuit, &QAction::triggered, this, &MainWindow::close);
  connect(actionConfigure, &QAction::triggered, &m_settings, &SettingsDialog::show);
  connect(actionLoop_Command,&QAction::triggered,&this->m_loopDialog,&LoopDialog::show);
  connect(actionGamepad,&QAction::triggered,this,&MainWindow::on_actionGamepad);

}


void MainWindow::refreshGamepadList(void)
{
    padManager = QGamepadManager::instance();
    QList<int> devIds = padManager->connectedGamepads();

    QList<gamepad_t> gamePadsFound;
    gamepad_t buf;
    if(!devIds.empty())
    {
        for (auto &id: devIds)
        {
            buf.deviceId = id;
            buf.name = padManager->gamepadName(id);
            gamePadsFound.append(buf);
        }
    }
    else
    {
        buf.name = "No Device Found";
        buf.deviceId = -1;
        gamePadsFound.append(buf);
    }

    this->m_gamepadDialog.updateDeviceList(gamePadsFound);
}

void MainWindow::on_actionGamepad()
{
    refreshGamepadList();
    this->m_gamepadDialog.show();
}

void MainWindow::showStatusMessage(const QString & message)
{
  statusBar()->showMessage(message);
}



void MainWindow::on_txSendField_returnPressed()
{

  this->writingThread.sendData(QString(txSendField->text()));
  // txSendField->text()
}

void MainWindow::on_actionInfo_triggered()
{
  QMessageBox::about(this,
                     tr("About RS232 Tool"),
                     tr("The <b>RS232 Tool</b> is used to observe Data on any UART "
                        "serial data line. "
                        "For further information please contact: "
                        "Sven Prigann"));
}

void MainWindow::on_actionClear_triggered()
{
  txList->clear();
  rxList->clear();
}


void MainWindow::addOscillatorView()
{
  OsziView * oscillatorView{new OsziView{this}};
  connect(this,&MainWindow::newCommandParsed,oscillatorView,&OsziView::addValue);

  oscillatorTabs.append(oscillatorView);

  tabWidget->addTab(oscillatorView, QString("Scope %0").arg(oscillatorTabs.count()));
}

void MainWindow::removeOscillatorView(int index)
{
  if (index >= 0 && index < oscillatorTabs.size())
  {
    OsziView * oscillatorView = oscillatorTabs.at(index);
    oscillatorTabs.remove(index);
    delete oscillatorView;
  }
}

void MainWindow::removeAllOscillatorViews()
{
  for (int i = 0; i < oscillatorTabs.size(); i++)
  {
    removeOscillatorView(i);
  }
}

void MainWindow::on_actionNew_Graph_triggered()
{
  addOscillatorView();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
  if (index != 0)
  {
    removeOscillatorView(index - 1);
  }
}

void MainWindow::on_tabWidget_tabBarDoubleClicked(int index)
{
    qDebug() << " double clicked";
  if (index != 0)
  {
    try
    {
      QString newName = QInputDialog::getText(this, tr("Renaming Tab"), tr("Scope Name:"));
      if (newName != "")
      {
        this->tabWidget->setTabText(index, newName);
      }
    }
    catch (...)
    {
      //
    }
  }
}

void MainWindow::on_actionExecute_Script_triggered()
{
    QList<QString> listBuffer;
    QString buffer;
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Command Script"), "./", tr("Command Skript (*.txt)"));

    if(!fileName.isEmpty() && !fileName.isNull())
    {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);

        buffer = file.readAll();
        file.close();
        listBuffer = buffer.split('\n');
        for(auto &cmd: listBuffer)
        {
            qDebug() << cmd;
        }

    }
}

