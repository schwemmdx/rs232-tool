#include "readingthread.h"

#include <QDebug>
#include <QThread>

#include <QtSerialPort/QSerialPort>

ReadingThread::ReadingThread(QSerialPort * serialPort)
    : QThread()
{
  this->threadRunning = false;
  this->serialPort = serialPort;
}

void ReadingThread::run()
{
  // There is no "run", just reading from device serialPort,
  // whitch is done in "read"
}

void ReadingThread::start()
{
  this->threadRunning = true;
  // qDebug() << "readingThread started!";
  this->run();
}

void ReadingThread::stop()
{
  this->threadRunning = false;
  this->wait();
}

void ReadingThread::configure(QSerialPort * settings)
{
  this->serialPort = settings;
}

void ReadingThread::read()
{
    this->rxCmd.clear();

  while (this->serialPort->bytesAvailable())
  {
      this->serialPort->read(&this->rxChar, 1);
      this->rxCmd.append(this->rxChar);
  }
  emit ReadingThread::recvReady();
}

QString ReadingThread::getLastCommand()
{
  return this->rxCmd;
}
