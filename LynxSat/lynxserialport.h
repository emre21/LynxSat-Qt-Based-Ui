#ifndef LYNXSERIALPORT_H
#define LYNXSERIALPORT_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QString>
#include <QMutex>
#include <QDebug>
class LynxSerialPort : public QThread
{
    Q_OBJECT
public:
    LynxSerialPort();
    void setPortName(QString t_portName);
    void run() override;
    void stopReading();
    void writeLeaveData();
    void writeMotorClose();
    void writeMotorOpen();
    void writeMergeButton();
    void writeRotateMotor();
    QSerialPort* getSerialPort();
signals:
    void SerialPortReadCompleted(QString data);
private:
    QSerialPort * m_ptrSerialPort;
    QString portName;
    bool isPortNameSet;
    bool isOpen;
    bool readingState;
    bool readwrite;
};

#endif // LYNXSERIALPORT_H
