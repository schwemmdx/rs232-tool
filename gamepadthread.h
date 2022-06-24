#ifndef GAMEPADTHREAD_H
#define GAMEPADTHREAD_H

#include <QObject>
#include <QThread>
#include <QGamepad>

typedef struct
{
    int deviceId;
    QString name;
}gamepad_t;

class GamepadThread:QThread
{
public:
    GamepadThread();

private:
    QGamepadManager* padManager = QGamepadManager::instance();
    QList<gamepad_t> deviceList;
    void run(void);


    void updateDeviceList(void);

};

#endif // GAMEPADTHREAD_H
