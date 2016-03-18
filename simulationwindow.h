#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QMainWindow>
#include "SchedulingAlgorithm.h"
namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulationWindow(QWidget *parent = 0);
    SchedulingAlgorithm * sa;
    ~SimulationWindow();

private:
    Ui::SimulationWindow *ui;
};

#endif // SIMULATIONWINDOW_H
