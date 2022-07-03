#ifndef GAMEPAD_DIALOG_H
#define GAMEPAD_DIALOG_H

#include <QDialog>
#include "gamepadthread.h"
#include <QtGamepad/QGamepad>




namespace Ui {
class Gamepad_dialog;
}

class Gamepad_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Gamepad_dialog(QWidget *parent = nullptr);
    ~Gamepad_dialog();
    void updateDeviceList(QList<gamepad_t>);

public slots:
    void loadFromFile(void);
    void saveToFile(void);
    void applyClicked(void);

signals:
    void configChanged(gamepad_config_t*);


private:
    Ui::Gamepad_dialog *ui;
    int deviceId = -1;
    gamepad_config_t config;
    void updateUiFromConfig(void);
    void updateConfigFromUi(void);

};

#endif // GAMEPAD_DIALOG_H
