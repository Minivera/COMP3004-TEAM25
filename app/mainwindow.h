#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
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

    void on_Off_clicked();
    void on_Open_clicked();
    void on_Back_clicked();
    void on_Set_clicked();
    void T();

private:
    Ui::MainWindow *ui;
    QPalette pal;
    //int row = 0;
    Form *form;
    Setting *set;

   QTimer *Timer;
};

#endif // MAINWINDOW_H
