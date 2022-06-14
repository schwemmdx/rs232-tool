#include "loopdialog.h"
#include "ui_loopdialog.h"

LoopDialog::LoopDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoopDialog)
{
    ui->setupUi(this);
}

LoopDialog::~LoopDialog()
{
    delete ui;
}
