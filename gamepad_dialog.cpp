#include "gamepad_dialog.h"
#include "ui_gamepad_dialog.h"
#include "gamepadthread.h"


#include <QJsonDocument>
#include <QJsonObject>

#include <QDebug>
#include <QWidget>
#include <QGamepad>
#include <QFileDialog>




Gamepad_dialog::Gamepad_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gamepad_dialog)
{
    ui->setupUi(this);

   connect(ui->applyBtn,&QPushButton::clicked,this,&Gamepad_dialog::applyClicked);
   connect(ui->abortBtn,&QPushButton::clicked,this,&Gamepad_dialog::reject);
   connect(ui->saveBtn,&QPushButton::clicked,this,&Gamepad_dialog::saveToFile);
   connect(ui->loadBtn,&QPushButton::clicked,this,&Gamepad_dialog::loadFromFile);


}

Gamepad_dialog::~Gamepad_dialog()
{
    delete ui;
}


void Gamepad_dialog::updateDeviceList(QList<gamepad_t> devicesFound)
{
    ui->devicesBox->clear();

    for(auto &device: devicesFound)
    {
        //ToDo add DeviceNames from DeviceId

         this->ui->devicesBox->addItem(device.name);
    }


}


void Gamepad_dialog::loadFromFile(void)
{

    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Configuration File"), "./", tr("Gamepad Config Files (*.json)"));
    qDebug() << fileName;
    //QString fileName = "/home/sven/github/rs232-tool/gamepad.json";
    this->ui->configFilePath->setText(fileName);

     QString val;
     QFile file;
     file.setFileName(fileName);
     file.open(QIODevice::ReadOnly | QIODevice::Text);
     val = file.readAll();
     file.close();

     QJsonDocument jDoc = QJsonDocument::fromJson(val.toUtf8());
     QJsonObject jsonObj = jDoc.object();
     QList<QString> jsonKeys = jsonObj.keys();
     qDebug() << jsonKeys;
     QJsonValue name = jsonObj.value("name");

     for (auto &key: jsonKeys)
     {
         if(key == "X")
         {
             ui->x_edit->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if(key == "Y")
         {
             ui->y_edit->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if(key == "A")
         {
             ui->a_edit->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if(key == "B")
         {
             ui->b_edit->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "L1")
         {
             ui->l1->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "L2")
         {
             ui->l2->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "R1")
         {
             ui->r1->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "R2")
         {
             ui->r2->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "START")
         {
             ui->start->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "BACK")
         {
             ui->back->setText(jsonObj.value(key)["cmd"].toString());
         }

         else if(key == "NAME")
         {
            ui->nameLabel->setText(jsonObj.value(key).toString());
         }
         else if (key == "KEY_L")
         {
             ui->k_l->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "KEY_R")
         {
             ui->k_r->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "KEY_UP")
         {
             ui->k_up->setText(jsonObj.value(key)["cmd"].toString());
         }
         else if (key == "KEY_DOWN")
         {
             ui->k_dwn->setText(jsonObj.value(key)["cmd"].toString());
         }
     }


}


void Gamepad_dialog::saveToFile(void)
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Configuration File"),
                                                    "./", tr("Gamepad Config Files (*.json)"));

    QFile saveFile(fileName);
    updateConfigFromUi();
    QJsonObject bufferObj;
    QJsonObject cmdBuffer;

    cmdBuffer.insert("cmd",config.cmd_buttonA);
    bufferObj.insert("A",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonB);
    bufferObj.insert("B",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonX);
    bufferObj.insert("X",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonY);
    bufferObj.insert("Y",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonL1);
    bufferObj.insert("L1",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonL2);
    bufferObj.insert("L2",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonR1);
    bufferObj.insert("R1",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonR2);
    bufferObj.insert("R2",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonStart);
    bufferObj.insert("START",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonBack);
    bufferObj.insert("BACK",cmdBuffer);
    bufferObj.insert("NAME",config.name);
    cmdBuffer.insert("cmd",config.cmd_buttonUp);
    bufferObj.insert("KEY_UP",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonDown);
    bufferObj.insert("KEY_DOWN",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonLeft);
    bufferObj.insert("KEY_LEFT",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonRight);
    bufferObj.insert("KEY_RIGHT",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonR3);
    bufferObj.insert("R3",cmdBuffer);
    cmdBuffer.insert("cmd",config.cmd_buttonL3);
    bufferObj.insert("L3",cmdBuffer);
    QJsonDocument doc(bufferObj);
    QByteArray bytes = doc.toJson( QJsonDocument::Indented);

       if( saveFile.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
       {
           QTextStream iStream(&saveFile);
           iStream.setCodec( "utf-8" );
           iStream << bytes;
           saveFile.close();
       }

}

void Gamepad_dialog::applyClicked(void)
{
    updateConfigFromUi();

    emit configChanged(&config);
    this->accept();
}

void Gamepad_dialog::updateConfigFromUi()
{
    config.cmd_buttonA = ui->a_edit->text();
    config.cmd_buttonB = ui->b_edit->text();
    config.cmd_buttonX = ui->x_edit->text();
    config.cmd_buttonY = ui->y_edit->text();
    config.cmd_buttonL1 = ui->l1->text();
    config.cmd_buttonL2 = ui->l2->text();
    config.cmd_buttonR1 = ui->r1->text();
    config.cmd_buttonR2 = ui->r2->text();
    config.cmd_buttonLeft = ui->k_l->text();
    config.cmd_buttonRight = ui->k_r->text();
    config.cmd_buttonUp = ui->k_up->text();
    config.cmd_buttonDown = ui->k_dwn->text();
    config.cmd_buttonStart = ui->start->text();
    config.cmd_buttonBack = ui->back->text();
    config.pad.deviceId = 0;
    config.name = ui->nameLabel->text();
    //TODO: Analog sticks

}


