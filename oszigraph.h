#ifndef OSZIGRAPH_H
#define OSZIGRAPH_H

#include <QString>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>


class OsziGraph: public QWidget
{
    Q_OBJECT
public:
   OsziGraph();
   //virtual ~OsziGraph();


public slots:
  //  void appendData(int); // or QPoint?
  //  void clearData();
   // void changeAppearace();

signals:
    //None ??

private:

   int seriesXIncrement;
   double AxisYmax;
   double AxisYmin;

   QT_CHARTS_NAMESPACE::QChart* chart;
   QT_CHARTS_NAMESPACE::QLineSeries* series;
   QT_CHARTS_NAMESPACE::QChartView* chartView;

   QT_CHARTS_NAMESPACE::QValueAxis *axisX;
   QT_CHARTS_NAMESPACE::QValueAxis *axisY;

};

#endif // OSZIGRAPH_H
