#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "widget.h"
#include "dialogsetting1.h"
#include "dialogsetting2.h"
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    Widget *widget;

private:

    void createActions();
    void createMenus();

    DialogSetting1 set;
    DialogSetting2 set2;

    QMenu* paramMenu;
    QAction* paramSettingAct;
    QAction* paramSettingAct2;
    QAction* paramSettingAct3;
    QAction* paramSettingAct4;
    QAction* exitAct;
    int index;

signals:
    void redirectData1(int nb);
    void redirectData2(QList<int>);
/*
    void redirectData3(int pitch);
    void redirectData4(int pitch);

    void redirectData5(QString scalePattern);
    void redirectData6(QString scalePattern);
*/
    void redirectData7(int nb);

    void redirectData8(bool view);
    void redirectData9(bool view);

    void redirectData10(int fret);


public slots:
    void sendData1(){emit redirectData1(set.spinBox->value());}
    void sendData2(){emit redirectData2(set.liste2);}
/*
    void sendData3(){emit redirectData3(widget->viewPitch->currentRow());}
    void sendData4(){emit redirectData4(widget->viewPitch->currentRow());}

    void sendData5(){emit redirectData5(widget->viewScale->currentItem()->text(1));}
    void sendData6(){emit redirectData6(widget->viewScale->currentItem()->text(1));}
*/
    void sendData7(){emit redirectData7(set2.spinBox->value());}

    void sendData8(){emit redirectData8(paramSettingAct3->isChecked());}
    void sendData9(){emit redirectData9(paramSettingAct4->isChecked());}

    void sendData10(){emit redirectData10(set.spinBox2->value());}


private slots:
    void dialogParam();
    void dialogParam2();


};

#endif // MAINWINDOW_H
