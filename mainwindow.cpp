#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <utility>
#include <queue>
#include <QLabel>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    this->hide();
    simwin = new SimulationWindow();
    simwin->show();
}

void MainWindow::on_ps_clicked()
{
    ui->p_priority0->setDisabled(0);

}

void MainWindow::on_sjf_clicked()
{
    ui->p_priority0->setDisabled(1);
}

void MainWindow::on_fcfs_clicked()
{
    ui->p_priority0->setDisabled(1);
}

void MainWindow::on_rr_clicked()
{
    ui->p_priority0->setDisabled(1);
}

void MainWindow::on_add_process_clicked()
{

}
