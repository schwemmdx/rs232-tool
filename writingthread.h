#ifndef WRITINGTHREAD_H
#define WRITINGTHREAD_H

#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QString>




class WritingThread : public QThread
{
    Q_OBJECT

public:
    WritingThread(QSerialPort *);


public slots:
    void run();
    void stop();
    void start();
    void sendData(QString);
   // void configure(QSerialPort*); // there is no need for this shit ?

signals:
    void sendSucessful();
    void error(QString err);

private:
    char dataForSend;
    QSerialPort * serialPort;
    bool threadRunning;

};

#endif // WRITINGTHREAD_H
