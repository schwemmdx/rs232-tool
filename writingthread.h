#ifndef WRITINGTHREAD_H
#define WRITINGTHREAD_H

#include <QString>
#include <QThread>
#include "settingsdialog.h"

#include <QtSerialPort/QSerialPort>

class WritingThread : public QThread
{
  Q_OBJECT

public:
  WritingThread(QSerialPort *);

public slots:
  void run();
  void stop();
  void start();
  void sendData(QString data);
  void applySettings(SettingsDialog::Settings*);


signals:
  void sendSucessful(QString);
  void error(QString err);

private:
  char dataForSend;
  QString endSeq{"\n"};
  QSerialPort * serialPort;
  bool threadRunning;
  SettingsDialog::InterpretType txType{SettingsDialog::InterpretType::TYPE_STRING};
};

#endif  // WRITINGTHREAD_H
