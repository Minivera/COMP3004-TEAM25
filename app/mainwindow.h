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
    friend class UC1Test;
    friend class UC2Test;
    friend class UC3Test;
    friend class UC4Test;
    friend class UC5Test;

public:
    explicit MainWindow(AppModel* model, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slot for the power button.
    void on_onButton_clicked();

    // Slots for the back and menu buttons.
    void on_backButton_clicked();
    void on_menuButton_clicked();

    // Slots for the direction buttons.
    void on_upButton_clicked();
    void on_bottomButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();

    // Slot for the enter button
    void on_enterButton_clicked();

    // Slot to connect to the model udpate message
    void updateRequested();

    // Slot to respond to the electrode button
    void on_electrodeButton_clicked();

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
