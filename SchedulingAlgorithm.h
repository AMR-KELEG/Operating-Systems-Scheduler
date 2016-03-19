#ifndef SCHEDULINGALGORITHM_H
#define SCHEDULINGALGORITHM_H
#include "Process.h"

class SchedulingAlgorithm
{
public:
    // void InitializeScheduler(vector<Process> p)=0;
    virtual void AddNewProcess(Process p)=0; // make private

    virtual Process FindNextProcess()=0; //Get
    // virtual int executeCurrentProcess()=0;
    virtual bool AllProcessesDone()=0;

    void ChangeAlgorithm(SchedulingAlgorithm * sa);
};

#endif // SCHEDULINGALGORITHM_H

