#include "gamepad_dialog.h"
#include "ui_gamepad_dialog.h"

#include <QDebug>

Gamepad_dialog::Gamepad_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gamepad_dialog)
{
    ui->setupUi(this);
    QGamepadManager* manager = QGamepadManager::instance();

    ui->device_id->setText(manager->gamepadName(673));

}

Gamepad_dialog::~Gamepad_dialog()
{
    delete ui;
}
