#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QDialog>

namespace Ui {
class AnotherWindow;
}

class AnotherWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AnotherWindow(QWidget *parent = nullptr);
    ~AnotherWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AnotherWindow *ui;
};

#endif // ANOTHERWINDOW_H
