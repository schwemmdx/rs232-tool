#ifndef READINGTHREAD_H
#define READINGTHREAD_H

#include <QMutex>
#include <QThread>

#include <QtSerialPort/QSerialPort>

#include "settingsdialog.h"

class ReadingThread : public QThread
{
  Q_OBJECT
public:
  ReadingThread(QSerialPort * serialDevice);

public slots:
  void run();
  void stop();
  void start();
  void configure(QSerialPort *);
  void read();

  void applySettings(SettingsDialog::Settings*);
  QList<QString> getRecievedCmds(void);

signals:
  void finished();
  void error(QString err);
  void recvReady();

private:
  char rxChar;
  SettingsDialog::InterpretType interpretType{SettingsDialog::InterpretType::TYPE_STRING};
  QSerialPort * serialPort;
  QString rxCmd;
  bool threadRunning;
};

#endif  // READINGTHREAD_H
