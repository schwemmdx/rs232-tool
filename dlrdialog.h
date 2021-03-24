#ifndef DLRDIALOG_H
#define DLRDIALOG_H

#include <QDialog>

namespace Ui
{
  class DlrDialog;
}

class DlrDialog : public QDialog
{
  Q_OBJECT

public:
  explicit DlrDialog(QWidget * parent = nullptr);
  ~DlrDialog();
  QString requestedSend;

signals:
  void cmdToSend(QString data);

private slots:
  void on_closeBtn_clicked();

  void on_valve_0_Btn_toggled(bool checked);

  void on_valve_1_Btn_toggled(bool checked);

  void on_flushBtn_toggled(bool checked);

  void on_rpmSpinner_valueChanged(int arg1);

  void on_pump_Btn_toggled(bool checked);

  void on_heaterSpinner_valueChanged(int arg1);

  void on_updateBtn_clicked();

  QVector<QString> calcValuesFromTime(int);

  void on_heaterSlider_sliderReleased();

  void on_rpmSlider_sliderReleased();

  void on_valve_0_Btn_clicked();

private:
  Ui::DlrDialog * ui;
  QString sendCmd;
  void changeState(QPushButton *, QString, bool checked);
  void delay(int ms);
};

#endif  // DLRDIALOG_H
