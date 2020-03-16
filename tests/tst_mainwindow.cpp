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
    QCOMPARE(window.ui->Screen->document()->toPlainText(), "mode 1\nmode 2\nmode 3");
}

void MainWindowTest::on_Off_clicked()
{
    // Arrange
    MainWindow window;

    // Act
    //window.show();

    QTest::mouseClick(window.ui->Open, Qt::LeftButton);
    QTest::mouseClick(window.ui->Off, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Screen->document()->isEmpty(), true);
}

QTEST_MAIN(MainWindowTest)

#include "tst_mainwindow.moc"
