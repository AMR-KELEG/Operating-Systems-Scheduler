#include "Process.h"
int Process::getId() const
{
    return id;
}

void Process::setId(int value)
{
    id = value;
}

Qt::GlobalColor Process::getColor() const
{
    return color;
}

void Process::setColor(const Qt::GlobalColor &value)
{
    color = value;
}

Process Process::GetNullProcess()
{
    return Process();
}

Process::Process(int id,int a,int b,int p, Qt::GlobalColor c)
{
    this->id=id;
    priority=p;
    burstTime=b;
    arrivalTime=a;
    color=c;
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
