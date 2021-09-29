#ifndef LYNXCHART_H
#define LYNXCHART_H

#include <string>

#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
class QLineSeries;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

//![1]
class Chart: public QChart
{
    Q_OBJECT
public:
    Chart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
    virtual ~Chart();

public slots:
    //void handleTimeout();
    void addData(qreal t_data);
    void setYRange(int start,int stop);
private:
    QTimer m_timer;
    //QSplineSeries *m_series;
    QLineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;
    int count{0};
    int limit{60};
};
#endif // LYNXCHART_H
