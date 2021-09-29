#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDateTime>
#include <QTableWidget>

#include <vector>
#include <string>

#include "videowidget.h"
#include "chartwidget.h"
#include "mapandrender.h"
#include "csvwriter.h"
#include "lynxserialport.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sendVideoFileClick();

    void connectButtonClick();
    void reconnectButtonClick();
    void disconnectButtonClick();
    void sendLeaveCommandButtonClick();
    void updateGui(QString data);
    void openMotorClick();
    void closeMotorClick();
    void mergeButtonClick();
    void rotateMotorClick();
private:
    Ui::MainWindow *ui;

    VideoWidget *m_ptrVideoWidget;
    ChartWidget *m_ptrChartWidget;
    MapAndRender *m_ptrMapAndRender;
    QGridLayout *m_ptrMainLayout;
    std::vector<QWidget*> testWidgets;
    LynxSerialPort* m_ptrLynxPort;
    CsvWriter* m_ptrCsvWriter;
};
#endif // MAINWINDOW_H
