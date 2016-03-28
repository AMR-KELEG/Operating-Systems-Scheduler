#ifndef DELAYTHREAD_H
#define DELAYTHREAD_H

#include <QThread>

class DelayThread : public QThread
{
    Q_OBJECT
public:
    explicit DelayThread(QObject *parent = 0);
    void run();
    bool stop;
signals:
    void wakeUp();
public slots:

};

#endif // DELAYTHREAD_H
