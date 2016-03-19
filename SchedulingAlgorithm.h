#ifndef SCHEDULINGALGORITHM_H
#define SCHEDULINGALGORITHM_H
#include "Process.h"

class SchedulingAlgorithm
{
virtual void addNewProcess(Process p)=0; // make private
public:
    virtual void InitializeScheduler(std::vector<Process> p)=0;

    virtual Process getNextProcess()=0;
    virtual int executeCurrentProcess()=0;
    virtual bool allProcessesDone()=0;

    void ChangeAlgorithm(SchedulingAlgorithm * sa);
};

#endif // SCHEDULINGALGORITHM_H

