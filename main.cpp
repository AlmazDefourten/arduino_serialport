#include "mainwindow.h"
#include <QApplication>
//vesde tak da
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
