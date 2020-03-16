#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;


private slots:
    void on_Menu_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();

};



#endif // FORM_H
