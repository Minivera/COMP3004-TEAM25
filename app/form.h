#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include "timer.h"
#include "appmodel.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

    friend class FormTest;

public:
    explicit Form(AppModel* model, QWidget *parent = nullptr);
    ~Form();

private slots:
    // Slot to connect to the model udpate message
    void updateRequested();

private:
    Ui::Form *ui;

    AppModel* model;

    void update();
};



#endif // FORM_H
