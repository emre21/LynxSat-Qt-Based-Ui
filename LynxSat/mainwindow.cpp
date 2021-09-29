#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include <mutex>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->sendLeaveCommandButton,SIGNAL(click),this,SLOT(sendLeaveCommandButtonClick));
    connect(this->ui->mergeButton,SIGNAL(click),this,SLOT(mergeButtonClick()));
    m_ptrLynxPort = new LynxSerialPort();
     std::string fileName = "TMUY_2021_55066_TLM.csv";
    m_ptrCsvWriter = new CsvWriter(fileName);
    m_ptrCsvWriter->openFile();
    std::string headers = "TAKIM NO,PAKET NO,GONDERME SAATI,BASINC,YUKSEKLIK,INIS HIZI,SICAKLIK,PIL GERILIMI,LATITUDE,LONGITUDE,ALTITUDE,STATU,PITCH,ROLL,YAW,DONUS SAYISI,VIDEO AKTARIM\n";
    m_ptrCsvWriter->writeData(headers);


    auto serialPortList = QSerialPortInfo::availablePorts();

    for(auto& p: serialPortList)
    {
         QString addItem = p.description() +" * "+p.portName();
         ui->serialPortComboBox->addItem(addItem);
    }

    connect(m_ptrLynxPort,SIGNAL(SerialPortReadCompleted(QString)),this,SLOT(updateGui(QString)));

    connect(this->ui->openMotorButton,SIGNAL(click),this,SLOT(motorOpenClick));
    connect(this->ui->closeMotorButton,SIGNAL(click),this,SLOT(motorCloseClick));
}



MainWindow::~MainWindow()
{
    m_ptrCsvWriter->close();

    delete ui;
}

void MainWindow::sendVideoFileClick()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("CHOOSE A VIDEO FILE"), "", tr(""));
}


void MainWindow::connectButtonClick()
{

    qDebug() << "Connect Button Click \n";

    QString portName = ui->serialPortComboBox->currentText().split(" * ").at(1);
    m_ptrLynxPort->setPortName(portName);
    m_ptrLynxPort->start(QThread::NormalPriority);

}



void MainWindow::reconnectButtonClick()
{
    qDebug() << "Reconnect Button Click \n";
    m_ptrLynxPort->stopReading();
    QString portName = ui->serialPortComboBox->currentText().split(" * ").at(1);
    m_ptrLynxPort->setPortName(portName);
    m_ptrLynxPort->start(QThread::NormalPriority);

}


void MainWindow::disconnectButtonClick()
{
    qDebug() << "disconnect Button Click \n";
    m_ptrLynxPort->stopReading();
}


void MainWindow::sendLeaveCommandButtonClick()
{

    m_ptrLynxPort->stopReading();
    m_ptrLynxPort->writeLeaveData();
    delete m_ptrLynxPort;
    QString portName = ui->serialPortComboBox->currentText().split(" * ").at(1);
    m_ptrLynxPort = new LynxSerialPort();
    connect(m_ptrLynxPort,SIGNAL(SerialPortReadCompleted(QString)),this,SLOT(updateGui(QString)));
    m_ptrLynxPort->setPortName(portName);
    m_ptrLynxPort->start(QThread::NormalPriority);

}


void MainWindow::openMotorClick()
{
    m_ptrLynxPort->stopReading();
    m_ptrLynxPort->writeMotorOpen();
    delete m_ptrLynxPort;
    QString portName = ui->serialPortComboBox->currentText().split(" * ").at(1);
    m_ptrLynxPort = new LynxSerialPort();
    connect(m_ptrLynxPort,SIGNAL(SerialPortReadCompleted(QString)),this,SLOT(updateGui(QString)));
    m_ptrLynxPort->setPortName(portName);
    m_ptrLynxPort->start(QThread::NormalPriority);

}
void MainWindow::closeMotorClick()
{
    m_ptrLynxPort->stopReading();
    m_ptrLynxPort->writeMotorClose();
    delete m_ptrLynxPort;
    QString portName = ui->serialPortComboBox->currentText().split(" * ").at(1);
    m_ptrLynxPort = new LynxSerialPort();
    connect(m_ptrLynxPort,SIGNAL(SerialPortReadCompleted(QString)),this,SLOT(updateGui(QString)));
    m_ptrLynxPort->setPortName(portName);
    m_ptrLynxPort->start(QThread::NormalPriority);

}

void MainWindow::mergeButtonClick()
{
    m_ptrLynxPort->stopReading();
    m_ptrLynxPort->writeMergeButton();
    delete m_ptrLynxPort;
    QString portName = ui->serialPortComboBox->currentText().split(" * ").at(1);
    m_ptrLynxPort = new LynxSerialPort();
    connect(m_ptrLynxPort,SIGNAL(SerialPortReadCompleted(QString)),this,SLOT(updateGui(QString)));
    m_ptrLynxPort->setPortName(portName);
    m_ptrLynxPort->start(QThread::NormalPriority);
}

void MainWindow::rotateMotorClick()
{
    m_ptrLynxPort->stopReading();
    m_ptrLynxPort->writeRotateMotor();
    delete m_ptrLynxPort;
    QString portName = ui->serialPortComboBox->currentText().split(" * ").at(1);
    m_ptrLynxPort = new LynxSerialPort();
    connect(m_ptrLynxPort,SIGNAL(SerialPortReadCompleted(QString)),this,SLOT(updateGui(QString)));
    m_ptrLynxPort->setPortName(portName);
    m_ptrLynxPort->start(QThread::NormalPriority);
}

void MainWindow::updateGui(QString data)
{
    auto list = data.split(',');

    int row= ui->tableWidget->rowCount();
    qDebug() << "list size " << list.size();



    if(list.size() == 17)
    {

        std::string text = data.toLocal8Bit().constData();
        m_ptrCsvWriter->writeData(text);
        ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
        // VİDEO AKTARIM Bİ TIK İLERi GİTTİ
        for(int i = 0; i < list.size() ; i++)
        {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                     i,
                                     new QTableWidgetItem(list.at(i)));

        }
        ui->tableWidget->selectRow(row);

        ui->mapAndRenderWidget->update_ui(list[12].toDouble(),list[13].toDouble()
                ,list[14].toDouble(),list[8].toDouble(),list[9].toDouble());

        ui->lynxChartWidget->updateUi(list[4].toDouble(),list[7].toDouble(),list[6].toDouble(),list[3].toDouble(),list[5].toDouble());
    }

    if(list.size() == 1)
    {
        qDebug()<<"List 1 data : "<<list[0];
    }

}
