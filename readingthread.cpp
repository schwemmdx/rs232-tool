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

    serialPort->waitForReadyRead(50);
    while(serialPort->canReadLine())
    {
        rxCmd.append(serialPort->readLine());
    }

  emit recvReady();

}

QList<QString> ReadingThread::getRecievedCmds()
{
    QList<QString> retList,buf;

  if(interpretType == SettingsDialog::InterpretType::TYPE_STRING)
  {
      retList = rxCmd.split('\n');
      for(auto & item : retList)
      {
          if(!item.isEmpty())
          {
              buf.append(item);
          }

      }
      return buf;
  }
  else
  {
      retList.append(rxCmd);
  }
  return retList;
}

void ReadingThread::applySettings(SettingsDialog::Settings* pSettings)
{
    interpretType = pSettings->rxType;
}
