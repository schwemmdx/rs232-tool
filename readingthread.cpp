#include "readingthread.h"

#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

ReadingThread::ReadingThread(QSerialPort * serialPort) : QThread()
{
    this->threadRunning = false;
    this->serialPort = serialPort;
}


void ReadingThread::run()
{
     //There is no "run", just reading from device serialPort,
    //whitch is done in "read"
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
    while(this->serialPort->bytesAvailable() )
    {
        this->serialPort->read(&this->readData,1);
        emit ReadingThread::recvReady();

    }

}

int ReadingThread::getLastCommand()
{
    return (uint8_t)this->readData;
}
