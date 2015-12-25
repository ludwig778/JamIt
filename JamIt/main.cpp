#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include <QtCore>
//#include <xml_dom.h>
#include <QDebug>
#include <scaledictionary.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
