#ifndef GAMEPADCONFIG_H
#define GAMEPADCONFIG_H

#include "gamepad_dialog.h"
#include <QObject>

class GamepadConfig : public QObject
{
    Q_OBJECT
public:
    explicit GamepadConfig(QObject *parent = nullptr);
    void loadFromFile(QString path);




signals:





};

#endif // GAMEPADCONFIG_H
