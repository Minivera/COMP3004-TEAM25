QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCLUDEPATH += \
    ../app

HEADERS += \
    ../app/mainwindow.h \
    ../app/form.h \
    ../app/setting.h

SOURCES +=  \
    ../app/mainwindow.cpp \
    ../app/form.cpp \
    ../app/setting.cpp \
    tst_mainwindow.cpp

FORMS += \
    ../app/mainwindow.ui \
    ../app/form.ui \
    ../app/setting.ui
