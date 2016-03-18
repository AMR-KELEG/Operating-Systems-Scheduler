#ifndef SCHEDULINGALGORITHM_H
#define SCHEDULINGALGORITHM_H
#include "Process.h"

class SchedulingAlgorithm
{
public:
    virtual void AddNewProcess(Process p)=0;
    virtual Process FindNextProcess()=0;
    virtual bool AllProcessesDone()=0;
    void ChangeAlgorithm(SchedulingAlgorithm * sa);
};

#endif // SCHEDULINGALGORITHM_H

