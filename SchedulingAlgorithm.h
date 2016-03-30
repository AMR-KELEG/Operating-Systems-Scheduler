#ifndef SCHEDULINGALGORITHM_H
#define SCHEDULINGALGORITHM_H

#include "PProcess.h"

class SchedulingAlgorithm
{
protected:
    QList<Process> ReadyQueue;
    QList<Process> FutureQueue;
    int currentTime;
    long long totalWaitingTime;
    long long numberOfProcesses;
    virtual void addNewProcess(Process p)=0;
public:
    virtual Process getNextProcess()=0;
    virtual int executeCurrentProcess()=0;
    virtual QList<Process> getReadyQueue()=0;

    void InitializeScheduler(QList<Process> p);
    bool allProcessesDone();
    void ChangeAlgorithm(SchedulingAlgorithm * sa);
    long double getAverageWaitingTime() const;
};

#endif // SCHEDULINGALGORITHM_H

