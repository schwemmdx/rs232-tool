#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "dlrdialog.h"
#include "listentry.h"
#include "osziview.h"
#include "readingthread.h"
#include "settingsdialog.h"
#include "ui_mainwindow.h"
#include "writingthread.h"
#include "loopdialog.h"
#include "gamepad_dialog.h"
#include "gamepadthread.h"



#include <QMainWindow>
#include <QSerialPort>
#include <QVector>
#include <QGamepad>


class MainWindow
    : public QMainWindow
    , Ui::MainWindow
{
  Q_OBJECT

public:
  MainWindow();
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

  void on_actionNew_Graph_triggered();
  void on_tabWidget_tabBarDoubleClicked(int index);
  void on_tabWidget_tabCloseRequested(int index);
  void on_actionGamepad(void);

  void on_actionExecute_Script_triggered();

private:


  QVector<OsziView *> oscillatorTabs{};
  SettingsDialog m_settings{this};
  LoopDialog m_loopDialog{this};
  Gamepad_dialog m_gamepadDialog{this};

  QSerialPort m_serial{};
  GamepadThread gamepadThread{};
  ReadingThread readingThread{&m_serial};
  WritingThread writingThread{&m_serial};

  ListEntry timeStamp;
  QString parsedReadCommand;
  QString parsedWriteCommand;

  // commandhistory
  QVector<uint8_t> commandHistory;

  QString usedProtocol{};
  QString connectionStatus{};

  QGamepadManager* padManager = QGamepadManager::instance();

  void initActionsConnections();
  void refreshGamepadList(void);
  void showStatusMessage(const QString & message);

  void addOscillatorView();
  void removeOscillatorView(int);
  void removeAllOscillatorViews();
};

#endif  // MAINWINDOW_H
