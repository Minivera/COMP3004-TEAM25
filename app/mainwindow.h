#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class MainWindowTest;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Off_clicked();
    void on_Open_clicked();


private:
    Ui::MainWindow *ui;
    QPalette pal;
    int row = 0;
};

#endif // MAINWINDOW_H
