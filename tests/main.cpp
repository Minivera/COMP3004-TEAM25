#include <QtTest>
#include <QApplication>

#include "tst_mainwindow.h"
#include "tst_form.h"
#include "tst_setting.h"

int main(int argc, char *argv[])
{
    // setup lambda
    int status = 0;
    auto runTest = [&status, argc, argv](QObject* obj) {
        int appArgc = argc;
        QApplication app(appArgc, argv);

        status |= QTest::qExec(obj, argc, argv);
    };

    // run suite
    runTest(new MainWindowTest);
    runTest(new FormTest);
    runTest(new SettingTest);

    return status;
}
