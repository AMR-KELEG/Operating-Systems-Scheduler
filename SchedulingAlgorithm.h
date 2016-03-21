#ifndef SCHEDULINGALGORITHM_H
#define SCHEDULINGALGORITHM_H
#include "Process.h"
#include <QtAlgorithms>
class SchedulingAlgorithm
{
protected:
    virtual void addNewProcess(Process p)=0;
    virtual bool compare(Process p1,Process p2)=0;
public:
    virtual void InitializeScheduler(QList<Process> p)=0;
    virtual Process getNextProcess()=0;
    virtual int executeCurrentProcess()=0;
    virtual bool allProcessesDone()=0;
    virtual QList<Process> getReadyQueue()=0;

    void ChangeAlgorithm(SchedulingAlgorithm * sa);
};

#endif // SCHEDULINGALGORITHM_H

