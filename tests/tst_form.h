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
    void on_Update_requested();
};

#endif // TST_FORM_H
