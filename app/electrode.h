#ifndef ELECTRODE_H
#define ELECTRODE_H

#include <QObject>

class electrode : public QObject
{
    Q_OBJECT
public:
    static electrode* Instance();
    bool getState();
protected:
    electrode();
    bool onSkin;
private:
    static electrode* _instance;

signals:
    void stateChanged(bool contact);
public slots:
    void changeState();

};

#endif // ELECTRODE_H
