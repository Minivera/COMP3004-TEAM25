#ifndef ELECTRODE_H
#define ELECTRODE_H

#include <QObject>

class electrode : public QObject
{
    Q_OBJECT

public:
    electrode();
    bool getState(); //Returns current value of onSkin
    void setState(bool state); //Changes value of onSkin
    ~electrode();

private:
    bool onSkin; //Tells whether electrode is pressed to skin or not

signals:

public slots:
    void changeState(); //handles signal from electrode state button in appmodel

};

#endif // ELECTRODE_H
