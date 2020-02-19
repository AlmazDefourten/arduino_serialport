#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QSerialPort serial;

void MainWindow::on_pushButton_clicked()
{
    serial.open(QIODevice::ReadWrite);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setPortName("COM4");
    if (serial.isOpen() && serial.isWritable())
                {

                    QByteArray ba("b");

                    serial.write(ba);
                        serial.waitForBytesWritten();
 serial.flush();

                    qDebug() << "data has been send" << endl;
                    serial.close();
                }
    else
       qDebug() << "ee";
}
