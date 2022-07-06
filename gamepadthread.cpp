#include "gamepadthread.h"
#include <QThread>
#include <QObject>
#include <QMessageBox>
#include <QDebug>


GamepadThread::GamepadThread()
{
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    m_gamepad = new QGamepad(*gamepads.begin(), this);

    connect(m_gamepad, &QGamepad::axisLeftXChanged, this, [this](double value){
        qDebug() << "Left X" << value;

    });
    connect(m_gamepad, &QGamepad::axisLeftYChanged, this, [this](double value){
        qDebug() << "Left Y" << value;

    });
    connect(m_gamepad, &QGamepad::axisRightXChanged, this, [this](double value){
        qDebug() << "Right X" << value;

    });
    connect(m_gamepad, &QGamepad::axisRightYChanged, this, [this](double value){
        qDebug() << "Right Y" << value;

    });
    connect(m_gamepad, &QGamepad::buttonAChanged, this,[this](bool pressed){
        if(pressed){
            emit sendCmd(config.cmd_buttonA);
        }
    });

    connect(m_gamepad, &QGamepad::buttonBChanged, this, [this](bool pressed){
        if(pressed){
            emit sendCmd(config.cmd_buttonB);
        }
    });
    connect(m_gamepad, &QGamepad::buttonXChanged, this, [this](bool pressed){
        if(pressed){
            emit sendCmd(config.cmd_buttonX);
        }
    });
    connect(m_gamepad, &QGamepad::buttonYChanged, this, [this](bool pressed){
        if(pressed){
            emit sendCmd(config.cmd_buttonY);
        }
    });
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, [this](bool pressed){
        if(pressed){
            emit sendCmd(config.cmd_buttonL1);
        }
    });
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, [this](bool pressed){
        if(pressed){
            emit sendCmd(config.cmd_buttonR1);
        }
    });
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, [this](double value){

            emit sendCmd(config.cmd_buttonL2+ ": "+QString::number(value));


    });
    connect(m_gamepad, &QGamepad::buttonR2Changed, this, [this](double value){
        emit sendCmd(config.cmd_buttonR2+ ": "+QString::number(value));

    });
    connect(m_gamepad, &QGamepad::buttonSelectChanged, this, [this](bool pressed){
        if(pressed){
            emit sendCmd(config.cmd_buttonBack);
        }
    });
    connect(m_gamepad, &QGamepad::buttonStartChanged, this, [this](bool pressed){
        if(pressed){
            emit sendCmd(config.cmd_buttonStart);
        }
    });
    connect(m_gamepad, &QGamepad::buttonGuideChanged, this, [](bool pressed){
        qDebug() << "Button Guide" << pressed;
    });
}



void GamepadThread::run(void)
{

}

bool GamepadThread::abortConnection()
{
    return true;
}

void GamepadThread::stop()
{
    threadRun = false;
}


void GamepadThread::updateConfig(gamepad_config_t* pConfig)
{
    this->config = *pConfig;
}

void GamepadThread::onButtonA(bool pressed)
{
    if(pressed){
        emit sendCmd(config.cmd_buttonA);
    }
}
