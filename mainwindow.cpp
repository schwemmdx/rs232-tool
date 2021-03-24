/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"

#include "dlrdialog.h"
#include "listentry.h"
#include "osziview.h"
#include "readingthread.h"
#include "settingsdialog.h"
#include "ui_mainwindow.h"
#include "writingthread.h"

#include <QByteArray>
#include <QDebug>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>
#include <QMessageBox>
#include <QString>
#include <QThread>
#include <QValueAxis>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

//#include "yaml-cpp/yaml.h"
#include <string>

MainWindow::MainWindow()
    : m_ui(new Ui::MainWindow)
    , m_status(new QLabel)
    , m_serial(new QSerialPort(this))
    , readingThread(m_serial)
    , writingThread(m_serial)

{

  m_ui->setupUi(this);

  setCentralWidget(m_ui->tabWidget);

  m_settings = new SettingsDialog(this);

  this->dlrDlg = new DlrDialog();

  m_ui->actionConnect->setEnabled(true);
  m_ui->actionDisconnect->setEnabled(false);
  m_ui->actionQuit->setEnabled(true);
  m_ui->actionConfigure->setEnabled(true);
  m_ui->actionStart_DLR_Control->setEnabled(false);
  m_ui->statusBar->addWidget(m_status);

  this->primaryOszi = new OsziView(this);
  this->m_ui->graphLayout->addWidget(this->primaryOszi);

  initActionsConnections();

  connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
  connect(m_serial, &QSerialPort::readyRead, &readingThread, &ReadingThread::read);
  connect(&readingThread, &ReadingThread::recvReady, this, &MainWindow::addReadData);
  connect(&writingThread, SIGNAL(sendSucessful(QString)), this, SLOT(addWriteData(QString)));
  connect(this->dlrDlg, SIGNAL(cmdToSend(QString)), &writingThread, SLOT(sendData(QString)));

  //![3]

  //![4]
}

MainWindow::~MainWindow()
{
  // delete m_settings;
  delete m_ui;
}

//! [4]
void MainWindow::openSerialPort()
{

  SettingsDialog::Settings p = m_settings->settings();
  m_serial->setPortName(p.name);
  m_serial->setBaudRate(p.baudRate);
  m_serial->setDataBits(p.dataBits);
  m_serial->setParity(p.parity);
  m_serial->setStopBits(p.stopBits);
  m_serial->setFlowControl(p.flowControl);

  if (m_serial->open(QIODevice::ReadWrite))
  {

    m_ui->actionConnect->setEnabled(false);
    m_ui->actionDisconnect->setEnabled(true);
    m_ui->actionConfigure->setEnabled(false);
    m_ui->actionStart_DLR_Control->setEnabled(true);
    readingThread.start();
    writingThread.start();
    m_ui->txSendField->setEnabled(true);
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
    QMessageBox::critical(this, tr("Error"), tr("Could <b>not</b> connect to Serial Port!<p>Check Connection Settings"));

    showStatusMessage(tr("Open error"));
  }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{
  readingThread.stop();
  if (m_serial->isOpen())
    m_serial->close();
  // m_console->setEnabled(false);
  m_ui->actionConnect->setEnabled(true);
  m_ui->actionDisconnect->setEnabled(false);
  m_ui->actionConfigure->setEnabled(true);
  m_ui->txSendField->setEnabled(false);
  m_ui->actionStart_DLR_Control->setEnabled(false);
  this->dlrDlg->hide();
  this->connectionStatus = tr("Disconnected");
  showStatusMessage(this->connectionStatus + "\t" + this->usedProtocol);
}
//! [5]

//! [6]
void MainWindow::addWriteData(QString writtenData)
{

  this->parsedWriteCommand = writtenData;
  this->parsedWriteCommand = this->timeStamp.getEnty(this->parsedWriteCommand);
  m_ui->txList->insertItem(0, this->parsedWriteCommand);
  m_ui->txSendField->clear();
}
//! [6]

//! [7]
void MainWindow::addReadData()
{
  this->parsedReadCommand = QString::number(this->readingThread.getLastCommand());
  emit newCommandParsed(this->parsedReadCommand);
  this->m_ui->lastCmd->setText(this->parsedReadCommand);
  this->parsedReadCommand = this->timeStamp.getEnty(this->parsedReadCommand);
  this->m_ui->rxList->insertItem(0, this->parsedReadCommand);
}

//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
  if (error == QSerialPort::ResourceError)
  {
    QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
    closeSerialPort();
  }
}
//! [8]

void MainWindow::initActionsConnections()
{
  connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
  connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
  connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
  connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
}

void MainWindow::showStatusMessage(const QString & message)
{
  m_status->setText(message);
}

void MainWindow::on_txSendField_returnPressed()
{

  this->writingThread.sendData(QString::number(m_ui->txSendField->text().toInt(nullptr, 0)));
  // m_ui->txSendField->text()
}

void MainWindow::on_actionInfo_triggered()
{
  QMessageBox::about(this,
                     tr("About RS232 Tool"),
                     tr("The <b>RS232 Tool</b> is used to observe Data on any UART "
                        "serial data line. "
                        "For further information please contact:"
                        "Sven Prigann"));
}

void MainWindow::on_actionClear_triggered()
{

  m_ui->txList->clear();
  m_ui->rxList->clear();
}

void MainWindow::on_actionLoad_triggered()
{
  // opens a filedialog for loading a yaml file
  QString fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open Protocol Description File"),
                                                  "../../../",
                                                  tr("Descriptor-Files(*.yml *.yaml);;all Files(*.*)"));

  /*YAML READING*/
  /*   try {

         YAML::Node config = YAML::LoadFile(fileName.toStdString());
         QString protocol_name = QString::fromStdString(config["name"].as<std::string>());
         QString protocol_ver = QString::fromStdString(config["version"].as<std::string>());
         QString protocol_0 = QString::fromStdString(config["0x0"].as<std::string>());
         QString protocol_1 = QString::fromStdString(config["0x1"].as<std::string>());
         QString protocol_10 = QString::fromStdString(config["0xa"].as<std::string>());
         QString protocol_11 = QString::fromStdString(config["0xb"].as<std::string>());

         this->usedProtocol = QString((tr("Using <b>%1</b> - Protocol  Version:<b> %2</b>").arg(protocol_name).arg(protocol_ver)));
          showStatusMessage(this->connectionStatus+"\t"+this->usedProtocol);

     }

     catch(const YAML::ParserException& ex)
     {
         QString buf = QString::fromStdString(ex.what());
         QMessageBox::warning(this, tr("YAML ERROR!"),
                               tr("<b>Error while reading YAML file:</b><p>")+buf);

     }*/
}

void MainWindow::on_actionNew_Graph_triggered()
{

  this->m_ui->tabWidget->addTab(new OsziView(this), QString("Scope %0").arg(this->m_ui->tabWidget->count()));
}

void MainWindow::on_tabWidget_tabBarDoubleClicked(int index)
{
  if (index != 0)
  {
    try
    {
      QString newName = QInputDialog::getText(this, tr("Renaming Tab"), tr("Scope Name:"));
      if (newName != "")
      {
        this->m_ui->tabWidget->setTabText(index, newName);
      }
    }
    catch (...)
    {
      //
    }
  }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
  if (index > 1)
  {
    this->m_ui->tabWidget->removeTab(index);
  }
}

void MainWindow::on_actionStart_DLR_Control_triggered()
{

  this->dlrDlg->move(this->pos().rx() + this->width(), this->pos().ry());
  this->dlrDlg->show();
}
