#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug("Im New~~");
    ui->setupUi(this);

    sWindow = new SubWindow();
    connect(sWindow, &SubWindow::firstWindow, this, &MainWindow::show);

    thirdWindow = new SubWindow();
    connect(thirdWindow, &SubWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    sWindow->show();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    thirdWindow->show();
    this->close();
}
