#include "exmple.h"
#include "mainwindow.h"
#include "windows.h"
#include "QSqlError"
exmple::exmple(QObject *parent) : QObject(parent)
{

}

bool exmple::running() const
{
    return m_running;
}

void exmple::run()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "temp");
    db.setHostName("localhost");
    db.setDatabaseName("table_temp");
    db.setUserName("root");
    db.setPassword("123654dd");
    bool ok = db.open();
    if (!ok) {
        qDebug("Не удалось подключить сервер");
        return;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO new_table (id, temper) VALUES (?, ?);");

    db.close();
    QSerialPort serialPort;

    serialPort.setPortName("COM9");
    serialPort.setBaudRate(QSerialPort::Baud9600);
    if (!serialPort.open(QIODevice::ReadWrite)) {
            qDebug("Не удалось подключится к порту");
            return;
        }
    char g = 2;
    while (m_running) {
        serialPort.open(QIODevice::ReadWrite);
        QByteArray data;  // специальный тип QT для хранения последовательности байтов
        serialPort.write(&g);
        serialPort.waitForBytesWritten();

     while (serialPort.waitForReadyRead(2000)) {
         // вместо холостого чтения накапливаем результат в переменную data
         data.append(serialPort.readAll());
     }
     query.addBindValue("99");
     query.addBindValue("26");
     query.exec();
     if (!query.exec()) {
         qDebug() << query.lastError().text();
     }
     qDebug("Succes!");
     emit sen(data);
     qDebug(data);
     serialPort.close();
     Sleep(2000);

    }
    emit finished();
}

void exmple::setrunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(m_running);
}
