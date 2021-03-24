#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dlrdialog.h"
#include "listentry.h"
#include "readingthread.h"
#include "settingsdialog.h"
#include "writingthread.h"

#include <osziview.h>

#include <QMainWindow>
#include <QSerialPort>
#include <QValueAxis>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui
{
  class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow();
  ~MainWindow();

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
  void initActionsConnections();
  void showStatusMessage(const QString & message);

  OsziView * primaryOszi = nullptr;
  Ui::MainWindow * m_ui = nullptr;

  SettingsDialog m_settings{this};
  DlrDialog * dlrDlg;

  QSerialPort m_serial{};

  ReadingThread readingThread{&m_serial};
  WritingThread writingThread{&m_serial};

  ListEntry timeStamp;
  QString parsedReadCommand;
  QString parsedWriteCommand;

  // commandhistory
  QVector<uint8_t> commandHistory;

  QString usedProtocol;
  QString connectionStatus;
};

#endif  // MAINWINDOW_H
