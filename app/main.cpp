#include <QApplication>

#include "mainwindow.h"
#include "appmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppModel model;
    MainWindow w(&model);
    w.show();

    return a.exec();
}
