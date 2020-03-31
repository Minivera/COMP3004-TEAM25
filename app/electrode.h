#ifndef ELECTRODE_H
#define ELECTRODE_H

#include <QObject>

class electrode : public QObject
{
    Q_OBJECT
public:
    static electrode* Instance(); //Creates single instance of electrode
    bool getState(); //reveals whether the electrode is pressed to the skin or not
protected:
    electrode();
    bool onSkin;
private:
    static electrode* _instance;

signals:

public slots:
    void changeState(); //toggles the onSkin variable

};

#endif // ELECTRODE_H
