
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
QT += xml
TARGET = JamIt
DEPENDPATH += .
INCLUDEPATH += .

SOURCES += \
    main.cpp \
    dialogsetting1.cpp \
    guitargraphicview.cpp \
    mainwindow.cpp \
    pianographicview.cpp \
    widget.cpp \
    dialogsetting2.cpp \
    scaleselectorwidget.cpp \
    notes.cpp \
    scaledictionary.cpp \
    metronomewidget.cpp

HEADERS += \
    dialogsetting1.h \
    guitargraphicview.h \
    mainwindow.h \
    pianographicview.h \
    widget.h \
    dialogsetting2.h \
    scaleselectorwidget.h \
    notes.h \
    scaledictionary.h \
    metronomewidget.h

RESOURCES += \
    resources.qrc
