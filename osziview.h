#ifndef OSZIVIEW_H
#define OSZIVIEW_H

#include <QWidget>
#include <QString>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>

namespace Ui {
class OsziView;
}

class OsziView : public QWidget
{
    Q_OBJECT

public:
    explicit OsziView(QWidget *parent = nullptr);
    ~OsziView();

signals:

public slots:
   void addValue(QString);

private slots:
   void on_yValueTypeBox_currentIndexChanged(const QString &arg1);

private:
    Ui::OsziView *ui;

   QVector<uint8_t> commandHistory;
   int seriesXIncrement;
   double AxisYmax;
   double AxisYmin;

   QT_CHARTS_NAMESPACE::QChart* chart;
   QT_CHARTS_NAMESPACE::QLineSeries* series;
   QT_CHARTS_NAMESPACE::QChartView* chartView;

   QT_CHARTS_NAMESPACE::QValueAxis *axisX;
   QT_CHARTS_NAMESPACE::QValueAxis *axisY;
};



#endif // OSZIVIEW_H
