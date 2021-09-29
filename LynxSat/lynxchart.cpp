
#include "lynxchart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(0),
    m_y(0)
{// 5 1
 //   QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
 //   m_timer.setInterval(1000);

    //m_series = new QSplineSeries(this);
    m_series = new QLineSeries(this);
    QPen green(Qt::red);
    green.setWidth(3);
    m_series->setPen(green);
    m_series->append(m_x, m_y);

    addSeries(m_series);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(5);
    m_axisX->setRange(0, 60);
    //m_axisY->setRange(-5, 10);

//    m_timer.start();
}

Chart::~Chart()
{

}
/*
void Chart::handleTimeout()
{
    qreal x = plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += y;
    m_y = QRandomGenerator::global()->bounded(5) - 2.5;
    m_series->append(m_x, m_y);
    scroll(x, 0);
    if (m_x == 100)
        m_timer.stop();
}

*/


void Chart::setYRange(int start,int stop)
{
    m_axisY->setRange(start,stop);
}
void Chart::addData(qreal t_data)
{
    qreal x = plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += 1;
    count = count + 1;
    m_series->append(m_x, t_data);
    if(count > limit-5)
    {
        m_axisX->setRange(0,limit+30);
        limit = limit +30;
    }

    //scroll(x-20, t_data);

}
