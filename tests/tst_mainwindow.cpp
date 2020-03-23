#include "tst_mainwindow.h"

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
