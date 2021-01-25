#include "oszigraph.h"


#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>

OsziGraph::OsziGraph() : QWidget()
{

    this->series= new QT_CHARTS_NAMESPACE::QLineSeries;
    this->chart = new QT_CHARTS_NAMESPACE::QChart();
    this->chartView = new QT_CHARTS_NAMESPACE::QChartView(this->chart);
    this->chartView->setRenderHint(QPainter::Antialiasing);

    this->chart->setAnimationOptions(QT_CHARTS_NAMESPACE::QChart::SeriesAnimations);
    this->chart->setAnimationDuration(50);
    this->chart->legend()->hide();

    this->chart->setPlotAreaBackgroundVisible(true);

    this->series->setVisible(true);

    this->chart->addSeries(series);
    this->axisX = new QT_CHARTS_NAMESPACE::QValueAxis;
    this->axisY = new QT_CHARTS_NAMESPACE::QValueAxis;

    this->chartView->chart()->addAxis(this->axisY, Qt::AlignLeft);
    this->chartView->chart()->addAxis(this->axisX, Qt::AlignBottom);
    this->series->attachAxis(this->axisX);
    this->series->attachAxis(this->axisY);
    this->seriesXIncrement=-1;
    this->AxisYmax = 0;
    this->AxisYmin = 255;
    this->axisX->setTickCount(10);
    this->axisX->setLabelFormat("%d");
    this->axisY->setTickCount(0);
    this->axisY->setLabelFormat("%d");
    this->chartView::update();

}
/*
OsziGraph::~OsziGraph()
{

}
*/
