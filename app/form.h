#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include "timer.h"


namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

    friend class FormTest;

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
//two private value
    Ui::Form *ui;
    Timer *timer;


private slots:
//four private slot in form to connect four button
    void on_Menu_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();
    void on_Enter_clicked();

};



#endif // FORM_H
