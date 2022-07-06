#ifndef RS232SCRIPTPARSER_H
#define RS232SCRIPTPARSER_H

#include <QString>

#include <QObject>

class RS232ScriptParser : QObject
{
    Q_OBJECT
public:

    RS232ScriptParser();


signals:
    void parsedCmd(QString);
    void parsedSleep(int ms);

public slots:
    int parse(QString);
};

#endif // RS232SCRIPTPARSER_H
