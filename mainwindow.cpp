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

void MainWindow::on_radioButton_3_clicked()
{

}

void MainWindow::on_radioButton_3_pressed()
{
    ui->p->setDisabled(0);
}

