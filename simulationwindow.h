#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulationWindow(QWidget *parent = 0);
    ~SimulationWindow();

private:
    Ui::SimulationWindow *ui;
};

#endif // SIMULATIONWINDOW_H
