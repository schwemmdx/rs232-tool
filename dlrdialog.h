#ifndef DLRDIALOG_H
#define DLRDIALOG_H

#include <QDialog>

namespace Ui {
class DlrDialog;
}

class DlrDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DlrDialog(QWidget *parent = nullptr);
    ~DlrDialog();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::DlrDialog *ui;
};

#endif // DLRDIALOG_H
