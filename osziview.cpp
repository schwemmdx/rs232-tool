#include "osziview.h"

#include "ui_osziview.h"
#include <QChartView>
#include <QDebug>

OsziView::OsziView(QWidget * parent)
    : QWidget(parent)
    , ui(new Ui::OsziView)
{
  ui->setupUi(this);
  this->series = new QT_CHARTS_NAMESPACE::QLineSeries;
  this->chart = new QT_CHARTS_NAMESPACE::QChart();
  this->chartView = new QT_CHARTS_NAMESPACE::QChartView(this->chart);
  this->chartView->setRubberBand(this->chartView->HorizontalRubberBand);
  this->chartView->setRenderHint(QPainter::Antialiasing);
  this->ui->graph_Layout->addWidget(chartView);
  this->chart->setAnimationOptions(QT_CHARTS_NAMESPACE::QChart::SeriesAnimations);
  this->chart->setAnimationDuration(100);
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

  this->axisX->setTickCount(10);
  this->axisX->setLabelFormat("%d");

  this->axisY->setTickCount(2);
  this->axisY->setMinorTickCount(1);
  // this->axisX->setGridLineColor(QColor(200,200,200));
  // this->axisX->setMinorGridLineColor(QColor(240,240,240));
  this->axisY->setLabelFormat("%f");

    // axis minimal and maximal value for autoscale by new points
  this->AxisYmax = -1;
  this->AxisYmin =1;
}

OsziView::~OsziView()
{
  delete ui;
}

void OsziView::addValue(QString parsedReadCommand)
{

  // Check for escape characters
  QString rawData;

  if ((!ui->escapeCmd->text().isEmpty() || ui->escapeCmd->text() == "None") && parsedReadCommand.startsWith(ui->escapeCmd->text()))
  {
      //remove the escape characters from command
    rawData =  parsedReadCommand.remove(ui->escapeCmd->text()).remove(" ");
    // get new min/max value on the fly
     qDebug() << rawData;
     qDebug() << rawData.toDouble();
    this->AxisYmax = qMax(AxisYmax, rawData.toDouble());
    this->AxisYmin = qMin(AxisYmin, rawData.toDouble());

    this->series->append(this->seriesXIncrement, rawData.toDouble());
    int currentLength = series->points().length();
    if(currentLength > 500)
    {
        this->axisX->setRange(currentLength-500, currentLength);
    }
    else
    {
        this->axisX->setRange(0, currentLength);
    }

    this->axisY->setRange(this->AxisYmin , this->AxisYmax );
    this->series->setPointsVisible();
    this->seriesXIncrement++;
    this->chartView->update();
  }
  else
  {
    // do something else with the data ?!
  }
}

