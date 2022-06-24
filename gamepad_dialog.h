#ifndef GAMEPAD_DIALOG_H
#define GAMEPAD_DIALOG_H

#include <QDialog>

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

private:
    QGamepad m_hardwareDevice;

    Ui::Gamepad_dialog *ui;

};

#endif // GAMEPAD_DIALOG_H
