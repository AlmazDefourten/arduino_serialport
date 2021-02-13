#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QString>

class MyThread : public QThread
{
Q_OBJECT
public:
void run();

};

#endif // MYTHREAD_H
