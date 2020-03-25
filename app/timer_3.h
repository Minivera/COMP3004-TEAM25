#ifndef TIMER_3_H
#define TIMER_3_H

#include <QDialog>

namespace Ui {
class Timer_3;
}

class Timer_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Timer_3(QWidget *parent = nullptr);
    ~Timer_3();
private slots:

    void A();

private:
    Ui::Timer_3 *ui;
    QTimer *timer200;
};

#endif // TIMER_3_H
