#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalFromButton(int buttonID);

private:
    Ui::MainWindow *ui;

private slots:
    void slotButton1();
    void slotButton2();
    void slotButton3();

    void slotMessage(int buttonID);
};
#endif // MAINWINDOW_H
