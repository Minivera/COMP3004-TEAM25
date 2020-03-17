#include <QtTest>
#include <QApplication>

#include "tst_mainwindow.cpp"
#include "tst_form.cpp"
#include "tst_setting.cpp"

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
