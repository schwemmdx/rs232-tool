#include "gamepadthread.h"
#include <QThread>
#include <QObject>
#include <QMessageBox>


GamepadThread::GamepadThread()
{

}



void GamepadThread::run(void)
{
    //constantly check for any state changes to the device list and the connected gamepad
    while(true)
    {
        usedGamepad.setDeviceId(config.pad.deviceId);

       if(!this->usedGamepad.isConnected())
       {
            emit connectionLost();
       }

       if(usedGamepad.buttonA())
       {
           //do shit on button press
           emit sendCmd(config.cmd_buttonA);
       }
       if(usedGamepad.buttonB())
       {
           emit sendCmd(config.cmd_buttonB);
       }
       sleep(100);

    }

}

bool GamepadThread::abortConnection()
{
    return true;
}




void GamepadThread::updateConfig(gamepad_config_t* pConfig)
{
    this->config = *pConfig;
}
