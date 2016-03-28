#include "delaythread.h"
#include <QtCore>
DelayThread::DelayThread(QObject *parent) :
    QThread(parent)
{
}

void DelayThread::run()
{
    while(1)
    {
        this->msleep(1000);
        emit wakeUp();
    }
}
