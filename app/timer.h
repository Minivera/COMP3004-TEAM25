#ifndef TIMER_H
#define TIMER_H

#include <QWidget>

#include "appmodel.h"

namespace Ui {
class Timer;
}

class Timer : public QWidget
{
    Q_OBJECT

    friend class TimerTest;
    friend class UC4Test;

public:
    explicit Timer(AppModel* model, QWidget *parent = nullptr);
    ~Timer();

private slots:
    // Slot to connect to the model udpate message
    void updateRequested();

private:
    Ui::Timer *ui;
    //transfer model data
    AppModel* model;

    void update();
};



#endif // TIMER_H
