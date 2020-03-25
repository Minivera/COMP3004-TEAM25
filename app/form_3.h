#ifndef FORM_3_H
#define FORM_3_H

#include <QDialog>
#include "timer_3.h"

namespace Ui {
class Form_3;
}

class Form_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Form_3(QWidget *parent = nullptr);
    ~Form_3();

private:
    Ui::Form_3 *ui;
    Timer_3 *timer;

private slots:
    void on_Menu_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();
    void on_Enter_clicked();

};

#endif // FORM_3_H
