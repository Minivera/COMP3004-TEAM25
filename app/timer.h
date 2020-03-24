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

    void A();

private:
    Ui::Timer *ui;
    QTimer *timer200;
};



#endif // TIMER_H
