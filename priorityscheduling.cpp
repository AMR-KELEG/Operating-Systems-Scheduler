#include "priorityscheduling.h"

PriorityScheduling::PriorityScheduling(bool isPreemptive)
{
    this->isPreemptive=isPreemptive;
}

void PriorityScheduling::addNewProcess(Process p)
{
    ReadyQueue.push_back(p);
}

Process PriorityScheduling::getNextProcess()
{
    while(!FutureQueue.empty() && FutureQueue.first().getArrivalTime()<=currentTime)
    {
        ReadyQueue.push_back(FutureQueue.first());
        FutureQueue.pop_front();
    }

    if(ReadyQueue.empty())
    {
        //Return NULL PROCESS
        return Process();
    }

    qSort(ReadyQueue.begin(),ReadyQueue.end(),PriorityScheduling::compare);
    return ReadyQueue.front();
}

int PriorityScheduling::executeCurrentProcess()
{
    if(ReadyQueue.empty())
    {
        int tempCurrentTime=currentTime;
        currentTime=FutureQueue.first().getArrivalTime();
        return FutureQueue.first().getArrivalTime()-tempCurrentTime;
    }
    if(isPreemptive)
    {
        currentTime++;
        ReadyQueue.first().setRemainingTime(ReadyQueue.first().getRemainingTime()-1);
        if(ReadyQueue.first().getRemainingTime()==0)
        {
            totalWaitingTime+=currentTime-ReadyQueue.front().getArrivalTime()-ReadyQueue.front().getBurstTime();
            ReadyQueue.pop_front();
        }
        return 1;
    }
    else
    {
        int currentProcessTime=ReadyQueue.front().getRemainingTime();
        currentTime+=currentProcessTime;
        totalWaitingTime+=currentTime-ReadyQueue.front().getArrivalTime()-ReadyQueue.front().getBurstTime();
        ReadyQueue.pop_front();
        return currentProcessTime;
    }
}

QList<Process> PriorityScheduling::getReadyQueue()
{
    return ReadyQueue;
}

bool PriorityScheduling::compare(Process p1, Process p2)
{
    return p1.getPriority()<p2.getPriority();
}


