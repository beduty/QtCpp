#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QDialog>

namespace Ui {
class SubWindow;
}

class SubWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SubWindow(QWidget *parent = nullptr);
    ~SubWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SubWindow *ui;
};

#endif // SUBWINDOW_H
