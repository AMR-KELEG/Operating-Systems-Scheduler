#include "Process.h"
Process Process::GetNullProcess()
{
    return Process(0,0,0);
}

Process::Process(int p=0,int b=0,int a=0)
{
    priority=p;
    burst_time=b;
    arrival_time=a;
}

int Process::getArrival_time() const
{
    return arrival_time;
}

void Process::setArrival_time(int value)
{
    arrival_time = value;
}

int Process::getBurst_time() const
{
    return burst_time;
}

void Process::setBurst_time(int value)
{
    burst_time = value;
}

int Process::getPriority() const
{
    return priority;
}

void Process::setPriority(int value)
{
    priority = value;
}
