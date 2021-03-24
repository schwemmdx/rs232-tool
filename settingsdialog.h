#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "ui_settingsdialog.h"

#include <QDialog>
#include <QSerialPort>

class SettingsDialog : public QDialog
{
  Q_OBJECT

public:
  struct Settings
  {
    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
  };

  explicit SettingsDialog(QWidget * parent);

  Settings getSettings();

signals:
  void refreshRequest();

private slots:
  void showPortInfo(int idx);
  void apply();
  void checkCustomBaudRatePolicy(int idx);
  void checkCustomDevicePathPolicy(int idx);

  void on_refreshBtn_clicked();

private:
  void fillPortsParameters();
  void fillPortsInfo();
  void updateSettings();

private:
  Ui::SettingsDialog m_ui{};
  Settings m_currentSettings{};
  QIntValidator m_intValidator{0, 4000000, this};
};

#endif  // SETTINGSDIALOG_H
