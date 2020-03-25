#ifndef TIMER_2_H
#define TIMER_2_H

#include <QDialog>

namespace Ui {
class Timer_2;
}

class Timer_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Timer_2(QWidget *parent = nullptr);
    ~Timer_2();

private slots:

    void A();

private:
    Ui::Timer_2 *ui;
    QTimer *timer200;
};

#endif // TIMER_2_H
