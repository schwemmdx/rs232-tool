#include "writingthread.h"

#include <QThread>
#include <QDebug>

WritingThread::WritingThread(QSerialPort * serialPort)
    : QThread()
{
  this->serialPort = serialPort;
  this->threadRunning = false;
}

void WritingThread::run()
{
  // no implement needed ?
}
void WritingThread::stop()
{
  this->threadRunning = false;
  this->wait();
}
void WritingThread::start()
{
  this->threadRunning = true;
}

void WritingThread::sendData(QString stringCmd)
{
    bool suceeded = true;
    for(auto &ch : stringCmd)
    {
        qDebug() << "latin: " << ch.toLatin1()<< " raw: " << ch<<"\n";
        if(!this->serialPort->putChar(ch.toLatin1()))
        {
            suceeded = false;
        }
    }

  if (suceeded)
  {
    emit WritingThread::sendSucessful(stringCmd);
  }
  else
  {
    emit WritingThread::error(tr("Hardware Error:\nSending could not be completed!"));
  }
}
