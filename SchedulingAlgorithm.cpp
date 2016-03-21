#include "SchedulingAlgorithm.h"
void SchedulingAlgorithm::InitializeScheduler(QList<Process> p)
{
    FutureQueue =p;
    qSort(FutureQueue.begin(),FutureQueue.end(),Process::isLess);
    currentTime=0;

}

bool SchedulingAlgorithm::allProcessesDone()
{
    return ReadyQueue.empty() && FutureQueue.empty();
}

