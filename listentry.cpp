#include "listentry.h"

#include <QDateTime>

ListEntry::ListEntry()
    : QString()
{
}

QString ListEntry::getEnty(QString cmd)
{
  timeStamp = QDateTime::currentDateTime();
  QTime time = timeStamp.time();
  return time.toString() + "\t" + cmd;
}
