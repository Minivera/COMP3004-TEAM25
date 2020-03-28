#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include "appmodel.h"
#include "form.h"
#include "timer.h"
#include "setting.h"

namespace Ui {
    class MainWindow;
}
class QLCDNumber;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class MainWindowTest;

public:
    explicit MainWindow(AppModel* model, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // On and back buttons
    void on_onButton_clicked();
    void on_backButton_clicked();

    // Slot to connect to the model udpate message
    void on_Update_requested();

    // Slots for the direction buttons.
    void on_upButton_clicked();
    void on_bottomButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();

    // Slot for the enter button
    void on_enterButton_clicked();

private:
    Ui::MainWindow *ui;
    QPalette pal;

    // The model containing all the data for the application.
    AppModel* model;

    Form *form;
    Timer *timer;
    Setting *set;

    void update();
};

#endif // MAINWINDOW_H
