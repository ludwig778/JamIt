
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
    xml_dom.cpp \
    dialogsetting2.cpp

HEADERS += \
    dialogsetting1.h \
    guitargraphicview.h \
    mainwindow.h \
    pianographicview.h \
    widget.h \
    xml_dom.h \
    dialogsetting2.h

RESOURCES += \
    resources.qrc
