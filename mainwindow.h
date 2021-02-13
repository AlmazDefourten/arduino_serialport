#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "counter.h"
#include <QThread>
#include "windows.h"
#include "exmple.h"
#include "QtSerialPort/QtSerialPort"
#include "QSqlDatabase"
#include <QMessageBox>
#include "QSqlDriver"
#include "QSqlQuery"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void rep(QString j);
signals:

private slots:
    void on_poggyButt_clicked();



private:
    Ui::MainWindow *ui;
    QThread thred_1;
    QThread thred_2;
    exmple ex_1;
    exmple ex_2;
};
#endif // MAINWINDOW_H
