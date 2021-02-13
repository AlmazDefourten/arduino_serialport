
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fig.h"
#include "windows.h"
#include "exmple.h"
#include "QDateTime"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background-image: url(/new/prefix1/font.png)");

    connect(&thred_1, SIGNAL(started()), &ex_1, SLOT(run()));
    connect(&ex_1, SIGNAL(finished()), &thred_1, SLOT(terminate()));
    connect(&ex_1, SIGNAL(sen(const QString)), this, SLOT(rep(const QString)));
    ex_1.moveToThread(&thred_1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int chet = 1;
void MainWindow::rep(QString jo)
{
    int ex = jo.toInt();
    int ex1 = ex/100; //temp
    int ex2 = ex % 100; //hum
    ui->temp->setText(QString::number(ex1));
    ui->hum->setText(QString::number(ex2));
    QString e = QDateTime::currentDateTime().toString("dd.MM.yyyy\nHH:mm");
    ui->time->setText(e);
    if (chet % 3 == 0)
    ui->statusbar->clearMessage();
    chet++;
}
bool knock = 1;
void MainWindow::on_poggyButt_clicked()
{
if (knock == 1) {
    thred_1.start();
    ex_1.setrunning(true);
    knock = 0;
    ui->poggyButt->setText("Off");
    ui->statusbar->showMessage("Sucesffully oned!");
    chet = 1;
}
else {
    ui->poggyButt->setText("On");
    ex_1.setrunning(false);
    knock = 1;
    ui->statusbar->showMessage("Sucesffully offed!");
    chet = 1;
}
}
