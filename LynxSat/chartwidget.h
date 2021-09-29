#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QChartView>
#include <QtCharts/QChart>
#include <QLineSeries>
#include <QGridLayout>
#include "lynxchart.h"
#include <QVBoxLayout>
#include <vector>
#include <QScrollArea>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class ChartWidget;
}


class ChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChartWidget(QWidget *parent = nullptr);
    ~ChartWidget();
    void updateUi(qreal height,qreal voltage,qreal temp,qreal press,qreal speed);
private:
    Ui::ChartWidget *ui;
    QGridLayout *m_ptrLayout;


    Chart* m_heightChart;
    Chart* m_VoltageChart;
    Chart* m_tempChart;
    Chart* m_pressChart;
    Chart* m_speedChart;


    QtCharts::QChartView *height_view;
    QtCharts::QChartView *speed_view;
    QtCharts::QChartView *press_view;
    QtCharts::QChartView *voltage_view;
    QtCharts::QChartView *temp_view;


    void initCharts();
    //void initLine();
    int count;
};

#endif // CHARTWIDGET_H
