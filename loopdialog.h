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

signals:
    void sendCmd(QString);


private:
    Ui::LoopDialog *ui;
    QList<QString> cmdLines;
    void accept();
    void parseLines();
};

#endif // LOOPDIALOG_H
