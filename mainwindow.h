#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dlrdialog.h"
#include "listentry.h"
#include "osziview.h"
#include "readingthread.h"
#include "settingsdialog.h"
#include "ui_mainwindow.h"
#include "writingthread.h"

#include <QMainWindow>
#include <QSerialPort>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

signals:
  void newCommandParsed(QString);
private slots:
  void openSerialPort();
  void closeSerialPort();
  void addWriteData(QString);
  void addReadData();

  void handleError(QSerialPort::SerialPortError error);
  void on_txSendField_returnPressed();
  void on_actionInfo_triggered();

  void on_actionClear_triggered();

  void on_actionLoad_triggered();

  void on_actionNew_Graph_triggered();

  void on_tabWidget_tabBarDoubleClicked(int index);

  void on_tabWidget_tabCloseRequested(int index);

  void on_actionStart_DLR_Control_triggered();

private:
  Ui::MainWindow m_ui{};

  OsziView primaryOszi{this};
  SettingsDialog m_settings{this};
  DlrDialog dlrDlg{this};

  QSerialPort m_serial{};
  ReadingThread readingThread{&m_serial};
  WritingThread writingThread{&m_serial};

  ListEntry timeStamp;
  QString parsedReadCommand;
  QString parsedWriteCommand;

  // commandhistory
  QVector<uint8_t> commandHistory;

  QString usedProtocol{};
  QString connectionStatus{};

  void initActionsConnections();
  void showStatusMessage(const QString & message);
};

#endif  // MAINWINDOW_H
