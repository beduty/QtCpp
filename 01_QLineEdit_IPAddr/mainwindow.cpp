#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QRegExpValidator"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 정규식 표현 (0,1 일때는 99 까지 가능하고, 24 일때는 9, 25일때는 5까지 가능
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";

    // 정규식 생성
    QRegExp ipRegex("^" + ipRange
                    + "\\." + ipRange
                    + "\\." + ipRange
                    + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);

    //LineEdit에 정규식을 붙일수 있다!!
    ui->lineEdit->setValidator(ipValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

