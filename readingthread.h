#ifndef READINGTHREAD_H
#define READINGTHREAD_H

#include <QMutex>
#include <QThread>

#include <QtSerialPort/QSerialPort>

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
  int getLastCommand();

signals:
  void finished();
  void error(QString err);
  void recvReady();

private:
  char readData;
  QSerialPort * serialPort;
  bool threadRunning;
};

#endif  // READINGTHREAD_H
