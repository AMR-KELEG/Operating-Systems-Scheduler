#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QMainWindow>
#include <vector>
#include <algorithm>
#include <stack>

#include "Process.h"
#include "SchedulingAlgorithm.h"
#include "FirstComeFirstServed.h"
#include "shortestjobfirst.h"
#include "priorityscheduling.h"
#include "roundrobin.h"

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

private:
    Ui::SimulationWindow *ui;
    QString horizontalHeaderLabels;
};

#endif // SIMULATIONWINDOW_H
