#ifndef TIMER_H
#define TIMER_H

#include <QDialog>

namespace Ui {
class Timer;
}

class Timer : public QDialog
{
    Q_OBJECT

    friend class TimerTest;

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

private slots:
    //One private slots in setting
    void A();

private:
    //One private value in mainwindow
    Ui::Timer *ui;
    QTimer *timer200;
};



#endif // TIMER_H
