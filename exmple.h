#ifndef EXMPLE_H
#define EXMPLE_H

#include <QObject>

class exmple : public QObject
{
    Q_PROPERTY(bool running READ running WRITE setrunning NOTIFY runningChanged)
    Q_OBJECT
    bool m_running;

public:
explicit exmple(QObject *parent = nullptr);
bool running() const;

public slots:
void run();
void setrunning(bool running);

signals:
    void sen(QString d);
void finished();
void runningChanged(bool running);
};

#endif // EXMPLE_H
