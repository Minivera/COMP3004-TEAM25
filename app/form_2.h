#ifndef FORM_2_H
#define FORM_2_H

#include <QDialog>
#include "timer_2.h"

namespace Ui {
class Form_2;
}

class Form_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Form_2(QWidget *parent = nullptr);
    ~Form_2();

private:
    Ui::Form_2 *ui;
    Timer_2 *timer;

private slots:
    void on_Menu_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();
    void on_Enter_clicked();

};

#endif // FORM_2_H
