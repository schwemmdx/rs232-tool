#include "osziview.h"

#include "mainwindow.h"
#include "ui_osziview.h"

#include <QDebug>

OsziView::OsziView(QWidget * parent)
    : QWidget(parent)
    , ui(new Ui::OsziView)
{
  ui->setupUi(this);
  this->series = new QT_CHARTS_NAMESPACE::QLineSeries;
  this->chart = new QT_CHARTS_NAMESPACE::QChart();
  this->chartView = new QT_CHARTS_NAMESPACE::QChartView(this->chart);
  this->chartView->setRenderHint(QPainter::Antialiasing);
  this->ui->graph_Layout->addWidget(chartView);
  this->chart->setAnimationOptions(QT_CHARTS_NAMESPACE::QChart::SeriesAnimations);
  this->chart->setAnimationDuration(50);
  this->chart->legend()->hide();

  this->chart->setAcceptHoverEvents(true);
  this->chart->setPlotAreaBackgroundVisible(true);

  this->series->setVisible(true);

  this->chart->addSeries(series);
  this->axisX = new QT_CHARTS_NAMESPACE::QValueAxis;
  this->axisY = new QT_CHARTS_NAMESPACE::QValueAxis;

  this->chartView->chart()->addAxis(this->axisY, Qt::AlignLeft);
  this->chartView->chart()->addAxis(this->axisX, Qt::AlignBottom);
  this->series->attachAxis(this->axisX);
  this->series->attachAxis(this->axisY);
  this->seriesXIncrement = -1;
  this->AxisYmax = 0x0;
  this->AxisYmin = 0xff;
  this->axisX->setTickCount(16);
  this->axisX->setLabelFormat("%d");
  this->axisY->setTickCount(16);
  this->axisY->setMinorTickCount(2);
  // this->axisX->setGridLineColor(QColor(200,200,200));
  // this->axisX->setMinorGridLineColor(QColor(240,240,240));
  this->axisY->setLabelFormat("%x");
  connect(parent, SIGNAL(newCommandParsed(QString)), this, SLOT(addValue(QString)));
}

OsziView::~OsziView()
{
  delete ui;
}

void OsziView::addValue(QString parsedReadCommand)
{
  // Check for escape character
  this->commandHistory.append(parsedReadCommand.toUInt());
  if (this->commandHistory.size() > 1 && this->commandHistory[this->commandHistory.size() - 2] == this->ui->escapeCmd->text().toUInt())
  {

    this->AxisYmax = qMax(AxisYmax, parsedReadCommand.toDouble());
    this->AxisYmin = qMin(AxisYmin, parsedReadCommand.toDouble());
    this->series->append(this->seriesXIncrement, parsedReadCommand.toUInt());
    this->axisY->setRange(this->AxisYmin - 1, this->AxisYmax + 1);
    this->axisX->setRange(0, this->series->points().length());
    this->seriesXIncrement++;
  }
  else if (this->ui->escapeCmd->text().isEmpty() || this->ui->escapeCmd->text() == QString("None"))
  {
    this->AxisYmax = qMax(AxisYmax, parsedReadCommand.toDouble());
    this->AxisYmin = qMin(AxisYmin, parsedReadCommand.toDouble());
    this->series->append(this->seriesXIncrement, parsedReadCommand.toUInt());
    this->axisY->setRange(this->AxisYmin - 1, this->AxisYmax + 1);
    this->axisX->setRange(0, this->series->points().length());
    this->seriesXIncrement++;
  }
}

void OsziView::on_yValueTypeBox_currentIndexChanged(const QString & arg1)
{
  switch (ui->yValueTypeBox->currentIndex())
  {
  case 0:
    this->axisY->setLabelFormat("%d");
    break;
  case 1:
    this->axisY->setLabelFormat("%x");
    break;
  }
  this->chartView->update();
}
