#include "lynxserialport.h"

LynxSerialPort::LynxSerialPort()
{

}

void LynxSerialPort::setPortName(QString t_portName)
{
    portName = t_portName;
    isPortNameSet = true;
}

void LynxSerialPort::run()
{

    m_ptrSerialPort = new QSerialPort();
    m_ptrSerialPort->setPortName(portName);
    m_ptrSerialPort->open(QIODevice::ReadWrite);
    m_ptrSerialPort->setBaudRate(QSerialPort::Baud9600);
    m_ptrSerialPort->setDataBits(QSerialPort::Data8);
    m_ptrSerialPort->setParity(QSerialPort::NoParity);
    m_ptrSerialPort->setStopBits(QSerialPort::OneStop);
    m_ptrSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    while(!m_ptrSerialPort->isOpen())
    {
        qDebug() << "trying open port\n";
        m_ptrSerialPort->open(QIODevice::ReadWrite);
    }

    if(m_ptrSerialPort->isOpen() && m_ptrSerialPort->isReadable())
    {
        qDebug() << "port is open and ready read\n";
    }

    while(true)
    {
        QMutex mutex;
        mutex.lock();
        if(readingState==false)
        {
            break;
        }
        QByteArray input;

        m_ptrSerialPort->waitForReadyRead(1000);
        if(m_ptrSerialPort->canReadLine())
        {
            input = m_ptrSerialPort->readLine(150);

            input.replace('\x00', "");


            qDebug() <<"input size " <<input.size();

            qDebug()<<"from child thread" <<input << '\n';
        }

        mutex.unlock();
        emit SerialPortReadCompleted(input);
       }
}


void LynxSerialPort::stopReading()
{

    QMutex mutex;
    mutex.lock();

    readingState = false;
    m_ptrSerialPort->close();
    this->terminate();
    qDebug() << "Threadten çıkılıyor\n";

    mutex.unlock();
}


void LynxSerialPort::writeLeaveData(){
    QMutex mutex;
    mutex.lock();
    m_ptrSerialPort = new QSerialPort();
    m_ptrSerialPort->setPortName(portName);
    m_ptrSerialPort->open(QIODevice::ReadWrite);
    m_ptrSerialPort->setBaudRate(QSerialPort::Baud9600);
    m_ptrSerialPort->setDataBits(QSerialPort::Data8);
    m_ptrSerialPort->setParity(QSerialPort::NoParity);
    m_ptrSerialPort->setStopBits(QSerialPort::OneStop);
    m_ptrSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    while(!m_ptrSerialPort->isOpen())
    {
        qDebug() << "trying open port\n";
        m_ptrSerialPort->open(QIODevice::ReadWrite);
    }

    if(m_ptrSerialPort->isOpen() && m_ptrSerialPort->isWritable())
    {
        qDebug() << "port is open and write\n";
    }



    QByteArray data(1,'f');

    if(m_ptrSerialPort->isWritable())
    {
        m_ptrSerialPort->write(data);
        m_ptrSerialPort->waitForBytesWritten(100);
        qDebug() << "gönderdin";
    }
    else{
        qDebug() << "GÖNDERMEDİM";
    }
    m_ptrSerialPort->close();
    mutex.unlock();

}


void LynxSerialPort::writeMotorClose(){
    QMutex mutex;
    mutex.lock();
    m_ptrSerialPort = new QSerialPort();
    m_ptrSerialPort->setPortName(portName);
    m_ptrSerialPort->open(QIODevice::ReadWrite);
    m_ptrSerialPort->setBaudRate(QSerialPort::Baud9600);
    m_ptrSerialPort->setDataBits(QSerialPort::Data8);
    m_ptrSerialPort->setParity(QSerialPort::NoParity);
    m_ptrSerialPort->setStopBits(QSerialPort::OneStop);
    m_ptrSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    while(!m_ptrSerialPort->isOpen())
    {
        qDebug() << "trying open port\n";
        m_ptrSerialPort->open(QIODevice::ReadWrite);
    }

    if(m_ptrSerialPort->isOpen() && m_ptrSerialPort->isWritable())
    {
        qDebug() << "port is open and write\n";
    }



    QByteArray data(1,'j');

    if(m_ptrSerialPort->isWritable())
    {
        m_ptrSerialPort->write(data);
        m_ptrSerialPort->waitForBytesWritten(100);
        qDebug() << "gönderdin";
    }
    else{
        qDebug() << "GÖNDERMEDİM";
    }
    m_ptrSerialPort->close();
    mutex.unlock();

}

void LynxSerialPort::writeMotorOpen(){
    QMutex mutex;
    mutex.lock();
    m_ptrSerialPort = new QSerialPort();
    m_ptrSerialPort->setPortName(portName);
    m_ptrSerialPort->open(QIODevice::ReadWrite);
    m_ptrSerialPort->setBaudRate(QSerialPort::Baud9600);
    m_ptrSerialPort->setDataBits(QSerialPort::Data8);
    m_ptrSerialPort->setParity(QSerialPort::NoParity);
    m_ptrSerialPort->setStopBits(QSerialPort::OneStop);
    m_ptrSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    while(!m_ptrSerialPort->isOpen())
    {
        qDebug() << "trying open port\n";
        m_ptrSerialPort->open(QIODevice::ReadWrite);
    }

    if(m_ptrSerialPort->isOpen() && m_ptrSerialPort->isWritable())
    {
        qDebug() << "port is open and write\n";
    }



    QByteArray data(1,'h');

    if(m_ptrSerialPort->isWritable())
    {
        m_ptrSerialPort->write(data);
        m_ptrSerialPort->waitForBytesWritten(100);
        qDebug() << "gönderdin";
    }
    else{
        qDebug() << "GÖNDERMEDİM";
    }
    m_ptrSerialPort->close();
    mutex.unlock();

}

void LynxSerialPort::writeMergeButton()
{
    QMutex mutex;
    mutex.lock();
    m_ptrSerialPort = new QSerialPort();
    m_ptrSerialPort->setPortName(portName);
    m_ptrSerialPort->open(QIODevice::ReadWrite);
    m_ptrSerialPort->setBaudRate(QSerialPort::Baud9600);
    m_ptrSerialPort->setDataBits(QSerialPort::Data8);
    m_ptrSerialPort->setParity(QSerialPort::NoParity);
    m_ptrSerialPort->setStopBits(QSerialPort::OneStop);
    m_ptrSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    while(!m_ptrSerialPort->isOpen())
    {
        qDebug() << "trying open port\n";
        m_ptrSerialPort->open(QIODevice::ReadWrite);
    }

    if(m_ptrSerialPort->isOpen() && m_ptrSerialPort->isWritable())
    {
        qDebug() << "port is open and write\n";
    }



    QByteArray data(1,'g');

    if(m_ptrSerialPort->isWritable())
    {
        m_ptrSerialPort->write(data);
        m_ptrSerialPort->waitForBytesWritten(100);
        qDebug() << "gönderdin";
    }
    else{
        qDebug() << "GÖNDERMEDİM";
    }
    m_ptrSerialPort->close();
    mutex.unlock();

}


void LynxSerialPort::writeRotateMotor(){

    QMutex mutex;
    mutex.lock();
    m_ptrSerialPort = new QSerialPort();
    m_ptrSerialPort->setPortName(portName);
    m_ptrSerialPort->open(QIODevice::ReadWrite);
    m_ptrSerialPort->setBaudRate(QSerialPort::Baud9600);
    m_ptrSerialPort->setDataBits(QSerialPort::Data8);
    m_ptrSerialPort->setParity(QSerialPort::NoParity);
    m_ptrSerialPort->setStopBits(QSerialPort::OneStop);
    m_ptrSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    while(!m_ptrSerialPort->isOpen())
    {
        qDebug() << "trying open port\n";
        m_ptrSerialPort->open(QIODevice::ReadWrite);
    }

    if(m_ptrSerialPort->isOpen() && m_ptrSerialPort->isWritable())
    {
        qDebug() << "port is open and write\n";
    }



    QByteArray data(1,'k');

    if(m_ptrSerialPort->isWritable())
    {
        m_ptrSerialPort->write(data);
        m_ptrSerialPort->waitForBytesWritten(100);
        qDebug() << "gönderdin";
    }
    else{
        qDebug() << "GÖNDERMEDİM";
    }
    m_ptrSerialPort->close();
    mutex.unlock();
}
