#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "setting.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:

    void on_Off_clicked();
    void on_Open_clicked();
    void on_Back_clicked();
    void on_Set_clicked();

private:
    Ui::MainWindow *ui;
    QPalette pal;
    //int row = 0;
    Form *form;
    Setting *set;


};

#endif // MAINWINDOW_H
