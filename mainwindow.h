#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QString>
#include "simulationwindow.h"
#include "Process.h"
#include <vector>

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

    void on_pushButton_clicked();

    void on_ps_clicked();

    void on_sjf_clicked();

    void on_fcfs_clicked();

    void on_rr_clicked();

    void on_add_process_clicked();

    void del_row();

private:
    Ui::MainWindow *ui;
    SimulationWindow *simwin;
    QGridLayout *process_grid;
    QWidget *viewport ;
    int num_of_process;
    QList<Process> processQueue;
    int quanta;
    std::string algorithm;
    void remove(QGridLayout *layout, int row, int column, bool deleteWidgets);
    void deleteChildWidgets(QLayoutItem *item);
    void removeRow(QGridLayout *layout, int row, bool deleteWidgets);


};

#endif // MAINWINDOW_H
