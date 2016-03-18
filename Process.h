#ifndef PROCESS_H
#define PROCESS_H
class Process{
    private:
    int priority;
    int burst_time;
    int arrival_time;


    public:
    static Process GetNullProcess();

    Process(int p,int b,int a);
    int getPriority() const;
    void setPriority(int value);
    int getBurst_time() const;
    void setBurst_time(int value);
    int getArrival_time() const;
    void setArrival_time(int value);
};

#endif // PROCESS_H
