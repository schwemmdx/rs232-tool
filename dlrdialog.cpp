#include "dlrdialog.h"
#include "ui_dlrdialog.h"

DlrDialog::DlrDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlrDialog)
{
    ui->setupUi(this);
}

DlrDialog::~DlrDialog()
{
    delete ui;
}

void DlrDialog::on_closeBtn_clicked()
{
    this->hide();
}
