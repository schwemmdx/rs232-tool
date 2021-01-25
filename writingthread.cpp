#include "writingthread.h"
#include <QThread>

WritingThread::WritingThread(QSerialPort* serialPort) : QThread()
{
    this->serialPort = serialPort;
    this->threadRunning = false;

}

void WritingThread::run()
{
    //no implement needed ?
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
    if( this->serialPort->putChar(stringCmd.toUInt()))
    {
        emit WritingThread::sendSucessful();
    }
    else
    {
        emit WritingThread::error(tr("Hardware Error:\nSending could not be completed!"));
    }
}
