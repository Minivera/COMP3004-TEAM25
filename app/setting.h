#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

    friend class SettingTest;

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

private:
    Ui::Setting *ui;

private slots:
     // Slots for the different buttons.
    void on_Back_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();
    void on_Decrease_clicked();
    void on_Increase_clicked();

};

#endif // SETTING_H
