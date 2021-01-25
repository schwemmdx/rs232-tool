#ifndef LISTENTRY_H
#define LISTENTRY_H

#include <QString>
#include <QDateTime>


class ListEntry : QString
{

public:
    ListEntry();
    QString getEnty(QString);

private:
   QDateTime timeStamp;
};

#endif // LISTENTRY_H
