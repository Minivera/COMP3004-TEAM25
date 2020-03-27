#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "form_2.h"
#include "form_3.h"
#include "setting.h"
#include <QObject>


namespace Ui {
class MainWindow;
}
class QLCDNumber;
class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class MainWindowTest;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    //Seven private slots in mainwindow

    void on_Off_clicked();
    void on_Open_clicked();
    void on_Back_clicked();
    void on_Set_clicked();
    void T();
    void on_Top_clicked();
    void on_Down_clicked();

private:
    //Six private value in mainwindow
    Ui::MainWindow *ui;
    QPalette pal;
    //int row = 0;
    Form *form;
    Form_2 *form_2;
    Form_3 *form_3;
    Setting *set;

   QTimer *Timer;


};

#endif // MAINWINDOW_H
