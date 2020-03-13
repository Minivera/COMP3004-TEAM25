#include <QtTest>
#include <QPushButton>

#include "mainwindow.h"
#include "ui_mainwindow.h"

class MainWindowTest: public QObject
{
    Q_OBJECT

private slots:
    void on_Open_clicked();
    void on_Off_clicked();

};

void MainWindowTest::on_Open_clicked()
{
    // Arrange
    MainWindow window;

    // Act
    //window.show();

    QTest::mouseClick(window.ui->Open, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Screen->document()->isEmpty(), false);
    QCOMPARE(window.ui->Screen->document()->toPlainText(), "Use Case1\nUse Case2\nUse Case3\nUse Case4\nUse Case5\nUse Case6");
}

void MainWindowTest::on_Off_clicked()
{
    // Arrange
    // FIXME: This does not work for some reason, the button seems to not have the same app as the test
    /*int argc = 0;
    QApplication app(argc, nullptr);

    QTimer timer;
    timer.setInterval(100);

    QSignalSpy spy(&app, &QApplication::aboutToQuit);
    QSignalSpy spyTimeout(&timer, &QTimer::timeout);

    MainWindow window;

    // Act
    window.show();

    QTest::mouseClick(window.ui->Off, Qt::LeftButton);

    timer.start();
    //QTimer::singleShot(1000, &window, &MainWindow::close); // This should quit the application
    QTimer::singleShot(2000, &app, QApplication::quit);  // This makes sure we quit even if it didn't

    QApplication::exec();

    // Assert
    QCOMPARE(spy.count(), 1);
    // Should be around 10 if closing caused the quit
    QVERIFY2(spyTimeout.count() < 15, QByteArray::number(spyTimeout.count()).constData());*/
}

QTEST_MAIN(MainWindowTest)

#include "tst_mainwindow.moc"
