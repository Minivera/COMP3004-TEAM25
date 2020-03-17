#include <QtTest>
#include <QPushButton>

#include "mainwindow.h"
#include "form.h"
#include "setting.h"
#include "ui_mainwindow.h"

class MainWindowTest: public QObject
{
    Q_OBJECT

private slots:
    void on_Open_clicked();
    void on_Off_clicked();
    void on_Back_clicked();
    void on_Set_clicked();
};

void MainWindowTest::on_Open_clicked()
{
    // Arrange
    MainWindow window;

    // Act
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
    QTest::mouseClick(window.ui->Open, Qt::LeftButton);
    QTest::mouseClick(window.ui->Off, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Screen->document()->isEmpty(), true);
}

void MainWindowTest::on_Back_clicked()
{
    // Arrange
    //int argc = 0;
    //QApplication app(argc, nullptr);
    MainWindow window;

    // Act
    QTest::mouseClick(window.ui->Back, Qt::LeftButton);

    auto form = window.findChildren<Form*>();

    // Assert
    QCOMPARE(form.isEmpty(), false);
    QCOMPARE(form.at(0)->objectName(), "Form");
}

void MainWindowTest::on_Set_clicked()
{
    // Arrange
    MainWindow window;

    // Act
    QTest::mouseClick(window.ui->Set, Qt::LeftButton);

    auto setting = window.findChildren<Setting*>();

    // Assert
    QCOMPARE(setting.isEmpty(), false);
    QCOMPARE(setting.at(0)->objectName(), "Setting");
}

QTEST_MAIN(MainWindowTest)

#include "tst_mainwindow.moc"
