#include <QApplication>

#include "mainwindow.h"
#include "appmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppModel* model = new AppModel();
    MainWindow w(model);
    w.show();

    int returnCode = a.exec();

    delete model;
    return returnCode;
}
