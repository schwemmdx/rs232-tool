#include "loopdialog.h"
#include "ui_loopdialog.h"

#include <QDebug>
#include <QThread>

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

void LoopDialog::accept()
{
    qDebug() << "Accept Clicked";
    parseLines();
}

void LoopDialog::parseLines()
{
     cmdLines = ui->commands_edit->toPlainText().split("\n");
     unsigned int delay = ui->delay_box->value();
     unsigned int stepDelay = 0;
     for (int i=0;i<ui->iteration_box->value();i++)
     {
         for (auto &cmd: cmdLines)
         {
             if (cmd.contains(".sleep"))
             {
                 stepDelay = cmd.split(".sleep ")[1].toInt();
                 qDebug() << "Sleeping for "<< stepDelay<< "ms";
                 QThread::msleep(stepDelay);
             }
             else
             {
                 emit sendCmd(cmd);
                 qDebug() << cmd;
             }
         }

          ui->progressBar->setValue(int(double(i)/double(ui->iteration_box->value())*100));
         QThread::msleep(delay);



     }
     ui->progressBar->setValue(0);
     hide();

}
