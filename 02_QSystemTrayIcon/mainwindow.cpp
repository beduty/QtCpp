#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tray Program");
    trayIcon = new QSystemTrayIcon(this);

    QIcon icon("qtIcon.ico");
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Tray Program" "\n" "Tray Icon Test");

    QMenu* menu = new QMenu(this);
    QAction* viewWindow = new QAction("Open", this);
    QAction* quitAction = new QAction("Exit", this);
    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);
    trayIcon->setContextMenu(menu);
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason))
            );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *evt)
{
    qDebug("Close");
    if(this->isVisible())
        qDebug("isVisible");
    if(ui->trayCheckBox->isChecked())
        qDebug("isChecked");

    if(this->isVisible() && ui->trayCheckBox->isChecked())
    {
        qDebug("Tray Icon!!");
        evt->ignore();
        this->hide();

        QIcon icon("qtIcon.ico");
        //QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        trayIcon->showMessage("Tray tpreosd", "sdsdsdsd", icon, 2000);
    }
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    qDebug("Active");
    if(reason == QSystemTrayIcon::Trigger)
    {
        if(!this->isVisible())
        {
            qDebug("Show");
            this->show();
        }
        else
        {
            qDebug("Hide");
            this->hide();
        }
    }
}

