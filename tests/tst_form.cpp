#include "tst_form.h"

#include "form.h"

void FormTest::on_Update_requested()
{
    // Arrange
    AppModel model;
    Form widget(&model);

    // Act
    widget.show();
    // Enter programs mode
    model.handleEnter();
    // Enter first program mode
    model.handleEnter();
    // Change freqency to two
    model.handleRight();

    // Assert
    QCOMPARE(widget.ui->Level->text(), "2");
}
