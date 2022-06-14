#ifndef LOOPDIALOG_H
#define LOOPDIALOG_H

#include <QDialog>

namespace Ui {
class LoopDialog;
}

class LoopDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoopDialog(QWidget *parent = nullptr);
    ~LoopDialog();

private:
    Ui::LoopDialog *ui;
};

#endif // LOOPDIALOG_H
