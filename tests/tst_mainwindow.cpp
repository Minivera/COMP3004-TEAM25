#include "tst_mainwindow.h"

void MainWindowTest::on_onButton_clicked() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    // Act
    window.show();
    QTest::mouseClick(window.ui->onButton, Qt::LeftButton);

    // Assert
    QCOMPARE(model.isOn(), true);
}

void MainWindowTest::on_backButton_clicked() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    // Act
    window.show();
    QTest::mouseClick(window.ui->onButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    QCOMPARE(model.getSelectedMenu(), currentMenu::ProgramsMenu);

    QTest::mouseClick(window.ui->backButton, Qt::LeftButton);

    // Assert
    QCOMPARE(model.getSelectedMenu(), currentMenu::MainMenu);
}

void MainWindowTest::on_upButton_clicked(){
    // Arrange
    AppModel model;
    MainWindow window(&model);

    // Act
    window.show();
    QTest::mouseClick(window.ui->onButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->upButton, Qt::LeftButton);

    // Assert
    QCOMPARE(model.getSelectedItem().row(), 0);
}

void MainWindowTest::on_bottomButton_clicked() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    // Act
    window.show();
    QTest::mouseClick(window.ui->onButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);

    // Assert
    QCOMPARE(model.getSelectedItem().row(), 1);

}

void MainWindowTest::on_leftButton_clicked() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    // Act
    window.show();

    // Go to the form
    QTest::mouseClick(window.ui->onButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Update the frequency
    QTest::mouseClick(window.ui->leftButton, Qt::LeftButton);

    // Assert
    QCOMPARE(model.getFrequency(), 0);
}

void MainWindowTest::on_rightButton_clicked() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    // Act
    window.show();

    // Go to the form
    QTest::mouseClick(window.ui->onButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Update the frequency
    QTest::mouseClick(window.ui->rightButton, Qt::LeftButton);

    // Assert
    QCOMPARE(model.getFrequency(), 2);
}

void MainWindowTest::on_enterButton_clicked() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    // Act
    window.show();
    QTest::mouseClick(window.ui->onButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Assert
    QCOMPARE(model.getSelectedMenu(), currentMenu::ProgramsMenu);
}
