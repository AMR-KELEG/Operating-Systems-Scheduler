#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QMainWindow>

#include "Process.h"
#include "SchedulingAlgorithm.h"
#include "FirstComeFirstServed.h"
#include "shortestjobfirst.h"
#include "priorityscheduling.h"
#include "roundrobin.h"
#include "delaythread.h"

namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulationWindow(QList<Process> processVector =QList<Process>(),int quantum=0, std::string algo="0", bool preempetive=0, QWidget *parent = 0);
    SchedulingAlgorithm * algorithm;
    ~SimulationWindow();
    DelayThread * thread;
private:

    Ui::SimulationWindow *ui;
public slots:
    void onWakeUp();
};

#endif // SIMULATIONWINDOW_H
