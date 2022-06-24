#include "gamepadthread.h"

GamepadThread::GamepadThread()
{

}

void GamepadThread::updateDeviceList(void)
{
    QList<int> devIds = padManager->connectedGamepads();

    deviceList.clear();
    gamepad_t bufferObj;

    for(auto &id : devIds)
    {
        bufferObj.deviceId = id;
        bufferObj.name = padManager->gamepadName(bufferObj.deviceId);
        deviceList.append(bufferObj);
    }
}

void GamepadThread::run(void)
{
    //constantly check for any state changes to the device list and the connected gamepad
}
