#include <QtTest>
#include <QApplication>

#include "tst_mainwindow.h"
#include "tst_form.h"
#include "tst_setting.h"
#include "tst_timer.h"

int main(int argc, char *argv[])
{
    // setup lambda
    int status = 0;
    QApplication app(argc, argv);

    auto runTest = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    // run suite
    runTest(new MainWindowTest);
    runTest(new FormTest);
    runTest(new SettingTest);
    runTest(new TimerTest);

    return status;
}
