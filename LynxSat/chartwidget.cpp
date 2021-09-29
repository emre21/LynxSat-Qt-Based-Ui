#include "chartwidget.h"
#include "ui_chartwidget.h"

ChartWidget::ChartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartWidget)
{
    //this->setMaximumWidth(400);

    count = 0;
    ui->setupUi(this);

    this->setMinimumSize(parent->size());


    m_ptrLayout = new QGridLayout;
    m_ptrLayout->setMargin(0);
    m_ptrLayout->setSpacing(0);
    setContentsMargins(0,0,0,0);
    initCharts();


    m_ptrLayout->addWidget(height_view,0,0);
    m_ptrLayout->addWidget(speed_view,0,1);
    m_ptrLayout->addWidget(temp_view,0,2);
    m_ptrLayout->addWidget(voltage_view,1,0);
    m_ptrLayout->addWidget(press_view,1,1);

    m_ptrLayout->setRowMinimumHeight(0,250);
    m_ptrLayout->setRowMinimumHeight(1,250);
    m_ptrLayout->setRowMinimumHeight(2,250);
    m_ptrLayout->setRowMinimumHeight(3,250);
    m_ptrLayout->setRowMinimumHeight(4,250);
    ui->scrollAreaWidgetContents->setLayout(m_ptrLayout);
}


ChartWidget::~ChartWidget()
{

    delete ui;

}


void ChartWidget::initCharts()
{


    m_VoltageChart = new Chart;
    m_VoltageChart->setTitle("GERİLİM (V)");
    m_VoltageChart->legend()->hide();
    m_VoltageChart->setAnimationOptions(QChart::AllAnimations);
    m_VoltageChart->setYRange(0,15);

    m_heightChart = new Chart;
    m_heightChart->setTitle("YUKSEKLIK (m)");
    m_heightChart->legend()->hide();
    m_heightChart->setAnimationOptions(QChart::AllAnimations);
    m_heightChart->setYRange(0,1000);

    m_pressChart = new Chart;
    m_pressChart->setTitle("BASINC (mbar)");
    m_pressChart->legend()->hide();
    m_pressChart->setAnimationOptions(QChart::AllAnimations);
    m_pressChart->setYRange(900,1200);

    m_speedChart = new Chart;
    m_speedChart->setTitle("HIZ (m/sn)");
    m_speedChart->legend()->hide();
    m_speedChart->setAnimationOptions(QChart::AllAnimations);
    m_speedChart->setYRange(0,50);

    m_tempChart = new Chart;
    m_tempChart->setTitle("SICAKLIK (°C)");
    m_tempChart->legend()->hide();
    m_tempChart->setAnimationOptions(QChart::AllAnimations);
    m_tempChart->setYRange(0,100);


    height_view =new QtCharts::QChartView(m_heightChart);
    height_view->setRenderHint(QPainter::Antialiasing);
    height_view->setContentsMargins(0,0,0,0);

    speed_view =new QtCharts::QChartView(m_speedChart);
    speed_view->setRenderHint(QPainter::Antialiasing);
    speed_view->setContentsMargins(0,0,0,0);

    voltage_view =new QtCharts::QChartView(m_VoltageChart);
    voltage_view->setRenderHint(QPainter::Antialiasing);
    voltage_view->setContentsMargins(0,0,0,0);


    temp_view =new QtCharts::QChartView(m_tempChart);
    temp_view->setRenderHint(QPainter::Antialiasing);
    temp_view->setContentsMargins(0,0,0,0);

    press_view =new QtCharts::QChartView(m_pressChart);
    press_view->setRenderHint(QPainter::Antialiasing);
    press_view->setContentsMargins(0,0,0,0);
    m_pressChart->setMinimumHeight(this->height()/5);


}

void ChartWidget::updateUi(qreal height, qreal voltage, qreal temp, qreal press, qreal speed)
{
    m_VoltageChart->addData(voltage);
    m_heightChart->addData(height);
    m_tempChart->addData(temp);
    m_pressChart->addData(press);
    m_speedChart->addData(speed);




}
