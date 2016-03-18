#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simulationwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_radioButton_3_clicked();

    void on_radioButton_3_pressed();


    void on_pushButton_clicked();

    void on_ps_clicked();

    void on_sjf_clicked();

    void on_fcfs_clicked();

    void on_rr_clicked();

    void on_add_process_clicked();

private:
    Ui::MainWindow *ui;
    SimulationWindow *simwin;

};

#endif // MAINWINDOW_H
