#ifndef WRITINGTHREAD_H
#define WRITINGTHREAD_H

#include <QString>
#include <QThread>

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


signals:
  void sendSucessful(QString);
  void error(QString err);

private:
  char dataForSend;
  QSerialPort * serialPort;
  bool threadRunning;
};

#endif  // WRITINGTHREAD_H
