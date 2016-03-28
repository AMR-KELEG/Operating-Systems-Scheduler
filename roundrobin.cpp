#include "roundrobin.h"

RoundRobin::RoundRobin(int Q)
{
    quantum=Q;
}

void RoundRobin::addNewProcess(Process p)
{
    ReadyQueue.push_back(p);
}

Process RoundRobin::getNextProcess()
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
    return ReadyQueue.front();
}


int RoundRobin::executeCurrentProcess()
{
    if(ReadyQueue.empty())
    {
        int tempCurrentTime=currentTime;
        currentTime=FutureQueue.first().getArrivalTime();
        return FutureQueue.first().getArrivalTime()-tempCurrentTime;
    }

    Process currentProcess = ReadyQueue.front();
    ReadyQueue.pop_front();
    int executionTime=std::min(quantum ,currentProcess.getRemainingTime());
    currentProcess.setRemainingTime(currentProcess.getRemainingTime()-executionTime);
    currentTime+=executionTime;
    if(currentProcess.getRemainingTime()>0)
    {
        ReadyQueue.push_back(currentProcess);
    }
    else
    {
        totalWaitingTime+=currentTime-currentProcess.getArrivalTime()-currentProcess.getBurstTime();
    }
    return executionTime;
}

QList<Process> RoundRobin::getReadyQueue()
{
    return ReadyQueue;
}
