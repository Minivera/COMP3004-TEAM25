#include <QtTest>
#include <QPushButton>

#include "form.h"
#include "ui_form.h"

#ifndef TST_FORM_H
#define TST_FORM_H

class FormTest: public QObject
{
    Q_OBJECT

private slots:
    void on_Menu_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();
    void on_Enter_clicked();
};

#endif // TST_FORM_H
