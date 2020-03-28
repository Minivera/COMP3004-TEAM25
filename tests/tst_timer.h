#include <QtTest>

#include "timer.h"
#include "ui_timer.h"

#ifndef TST_TIMER_H
#define TST_TIMER_H

class TimerTest: public QObject
{
    Q_OBJECT

private slots:
    void on_Update_requested();
};

#endif // TST_TIMER_H
