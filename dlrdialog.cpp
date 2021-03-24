#include "dlrdialog.h"

#include "ui_dlrdialog.h"
#include "writingthread.h"

#include <mainwindow.h>
#include <math.h>

#include <QDebug>
#include <QString>
#include <QVector>

#ifdef Q_OS_WIN
#include <chrono>
#include <thread>
#endif

DlrDialog::DlrDialog(QWidget * parent)
    : QDialog(parent)
    , ui(new Ui::DlrDialog)
{
  this->setFixedSize(QSize(382, 712));
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

void DlrDialog::changeState(QPushButton * btn, QString cmd, bool checked)
{
  if (checked)
  {
    btn->setText(tr("Off"));
    this->requestedSend = cmd;
  }
  else
  {
    btn->setText(tr("On"));
    this->requestedSend = cmd;
  }
  emit cmdToSend(this->requestedSend);
}

void DlrDialog::on_valve_0_Btn_toggled(bool checked)
{

  if (checked)
  {
    sendCmd = tr("32");
  }
  else
  {
    sendCmd = tr("33");
  }
  DlrDialog::changeState(this->ui->valve_0_Btn, sendCmd, checked);
}

void DlrDialog::on_valve_1_Btn_toggled(bool checked)
{
  if (checked)
  {
    sendCmd = tr("34");
  }
  else
  {
    sendCmd = tr("35");
  }
  DlrDialog::changeState(this->ui->valve_1_Btn, sendCmd, checked);
}

void DlrDialog::on_flushBtn_toggled(bool checked)
{
  if (checked)
  {
    sendCmd = tr("16");
  }
  else
  {
    sendCmd = tr("17");
  }
  DlrDialog::changeState(this->ui->flushBtn, sendCmd, checked);
}

void DlrDialog::on_rpmSpinner_valueChanged(int arg1)
{
  this->ui->rpmSlider->setValue(arg1);
  emit cmdToSend(QString::number(13));
  emit cmdToSend(QString::number(arg1));
}

void DlrDialog::on_pump_Btn_toggled(bool checked)
{
  if (checked)
  {
    sendCmd = tr("19");
  }
  else
  {
    sendCmd = tr("20");
  }
  DlrDialog::changeState(this->ui->pump_Btn, sendCmd, checked);
}

void DlrDialog::on_heaterSpinner_valueChanged(int arg1)
{
  this->ui->heaterSlider->setValue(arg1);
  emit cmdToSend(QString::number(14));
  emit cmdToSend(QString::number(arg1));
}

void DlrDialog::on_updateBtn_clicked()
{
  QVector<QString> timeValues;
  timeValues = calcValuesFromTime(this->ui->flushTimeSpinner->value());
  emit cmdToSend(QString::number(10));
  emit cmdToSend(timeValues[0]);
  emit cmdToSend(timeValues[1]);
  /*
     DlrDialog::delay(500);
     timeValues = calcValuesFromTime(this->ui->preStartSpinner->value());
     emit cmdToSend(QString::number(11));
     emit cmdToSend(timeValues[0]);
     emit cmdToSend(timeValues[1]);
     DlrDialog::delay(500);
     timeValues = calcValuesFromTime(this->ui->postStopSpinner->value());
     emit cmdToSend(QString::number(12));
     emit cmdToSend(timeValues[0]);
     emit cmdToSend(timeValues[1]);
  */
}

QVector<QString> DlrDialog::calcValuesFromTime(int input)
{
  /*
   *  exponent = int(np.floor(np.log10(userInput))-1)
      mult = int(userInput/int(np.power(10, exponent)))
      */
  QVector<QString> cmdVec;
  int mult, exp;
  exp = (int)floor(log10(input)) - 1;
  mult = (int)input / ((int)(pow(10, exp)));
  cmdVec.append(QString::number(mult));
  cmdVec.append(QString::number(exp));
  return cmdVec;
}

void DlrDialog::on_heaterSlider_sliderReleased()
{

  this->ui->heaterSpinner->setValue(this->ui->heaterSlider->value());
}

void DlrDialog::on_rpmSlider_sliderReleased()
{
  this->ui->rpmSpinner->setValue(this->ui->rpmSlider->value());
}

void DlrDialog::delay(int ms)
{

#ifdef Q_OS_WIN
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
#else
  struct timespec ts = {ms / 1000, (ms % 1000) * 1000 * 1000};
  nanosleep(&ts, NULL);
#endif
}

void DlrDialog::on_valve_0_Btn_clicked()
{
}
