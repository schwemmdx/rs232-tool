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


typedef struct
{
    gamepad_t pad;
    QString cmd_axisLeft;
    QString cmd_axisRight;
    QString cmd_buttonX;
    QString cmd_buttonY;
    QString cmd_buttonA;
    QString cmd_buttonB;
    QString cmd_buttonL1;
    QString cmd_buttonL2;
    QString cmd_buttonR1;
    QString cmd_buttonR2;
    QString cmd_buttonL3;
    QString cmd_buttonR3;
    QString cmd_buttonStart;
    QString cmd_buttonBack;
    QString cmd_buttonUp;
    QString cmd_buttonDown;
    QString cmd_buttonLeft;
    QString cmd_buttonRight;

}gamepad_config_t;

struct gamepad_state_t
{
    bool button_x{false};
    bool button_y{false};
    bool button_a{false};
    bool button_b{false};
    bool button_l1{false};
    bool button_l2{false};
    bool button_r1{false};
    bool button_r2{false};
    bool button_l3{false};
    bool button_r3{false};
    bool button_start{false};
    bool button_back{false};
    double analog_l_x{0.0};
    double analog_l_y{0.0};
    double analog_r_x{0.0};
    double analog_r_y{0.0};
};

class GamepadThread: public QThread
{
Q_OBJECT

public:
    GamepadThread();

public slots:
    bool abortConnection();
    //void setUsedDevice(int deviceId);
    void updateConfig(gamepad_config_t* newCfg);
    void stop();


signals:
    void connectionLost();
    void sendUpdatedDeviceList(QList<gamepad_t>*);
    void initFailed();

    void sendCmd(QString);


private:
    QGamepadManager* padManager = QGamepadManager::instance();
    QList<gamepad_t> deviceList;
    QGamepad *m_gamepad;
   // QGamepad usedGamepad;
    gamepad_state_t inputState;
    void run(void);
    bool threadRun{false};
    gamepad_config_t config;

    void onButtonA(bool);


};

#endif // GAMEPADTHREAD_H
