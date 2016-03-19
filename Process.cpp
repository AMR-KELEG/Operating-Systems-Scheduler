#include "Process.h"
Process Process::GetNullProcess()
{
    return Process(0,0,0);
}

Process::Process(int id,int a,int b,int p)
{
    this->id=id;
    priority=p;
    burstTime=b;
    arrivalTime=a;
}

int Process::getArrivalTime() const
{
    return arrivalTime;
}

void Process::setArrivalTime(int value)
{
    arrivalTime = value;
}

int Process::getBurstTime() const
{
    return burstTime;
}

void Process::setBurstTime(int value)
{
    burstTime = value;
}

int Process::getPriority() const
{
    return priority;
}

void Process::setPriority(int value)
{
    priority = value;
}
