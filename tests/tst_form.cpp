#include <QtTest>
#include <QPushButton>

#include "form.h"
#include "ui_form.h"

class FormTest: public QObject
{
    Q_OBJECT

private slots:
    void on_Menu_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();
};

void FormTest::on_Menu_clicked()
{
    // Arrange
    Form window;

    // Act
    window.show();
    QTest::mouseClick(window.ui->Menu, Qt::LeftButton);

    // Assert
    QCOMPARE(window.isHidden(), true);
}

void FormTest::on_Reduce_clicked()
{
    // Arrange
    Form window;

    // Act
    window.show();
    QTest::mouseClick(window.ui->Reduce, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Level->text().toInt(), -1);
}

void FormTest::on_Add_clicked()
{
    // Arrange
    Form window;

    // Act
    window.show();
    QTest::mouseClick(window.ui->Add, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Level->text().toInt(), 1);
}

#include "tst_form.moc"
