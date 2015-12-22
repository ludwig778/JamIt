#include "mainwindow.h"
#include "widget.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent)
{
    widget = new Widget(this);
    setCentralWidget(widget);
    setMaximumSize(800,800);

    createActions();
    createMenus();


    connect(set2.okButton,SIGNAL(pressed()),this,SLOT(sendData7()));
    connect(this, SIGNAL(redirectData7(int)),widget->pianoView,SLOT(updateOctaveCount(int)));
    connect(set.okButton,SIGNAL(pressed()),this,SLOT(sendData10()));
    connect(this, SIGNAL(redirectData10(int)),widget->guitarView,SLOT(updateFretNumber(int)));

    connect(set.okButton,SIGNAL(pressed()),this,SLOT(sendData1()));
    connect(this, SIGNAL(redirectData1(int)),widget->guitarView,SLOT(updateNbString(int)));
    connect(set.okButton,SIGNAL(pressed()),this,SLOT(sendData2()));
    connect(this, SIGNAL(redirectData2(QList<int>)),widget->guitarView,SLOT(updateTuning(QList<int>)));

    // MOVED FROM THIS TO WIDGET CONSTRUCTOR
    /*connect(widget->setScale,SIGNAL(pressed()),this,SLOT(sendData3()));
    connect(this, SIGNAL(redirectData3(int)),widget->guitarView,SLOT(updateScalePitch(int)));
    connect(widget->setScale,SIGNAL(pressed()),this,SLOT(sendData4()));
    connect(this, SIGNAL(redirectData4(int)),widget->pianoView,SLOT(updateScalePitch(int)));

    connect(widget->setScale,SIGNAL(pressed()),this,SLOT(sendData5()));
    connect(this, SIGNAL(redirectData5(QString)),widget->guitarView,SLOT(updateScale(QString)));
    connect(widget->setScale,SIGNAL(pressed()),this,SLOT(sendData6()));
    connect(this, SIGNAL(redirectData6(QString)),widget->pianoView,SLOT(updateScale(QString)));

    connect(widget->setScale,SIGNAL(pressed()),widget,SLOT(testqdebud()));

    connect(widget->viewPitch,SIGNAL(doubleClicked(QModelIndex)),widget->guitarView,SLOT(updateDoubleClickPitch(QModelIndex)));
    connect(widget->viewPitch,SIGNAL(doubleClicked(QModelIndex)),widget->pianoView,SLOT(updateDoubleClickPitch(QModelIndex)));


    connect(widget->viewScale,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),widget->guitarView,SLOT(updateDoubleClickScale(QTreeWidgetItem*,int)));
    connect(widget->viewScale,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),widget->pianoView,SLOT(updateDoubleClickScale(QTreeWidgetItem*,int)));
    */

    // Double clicked
    //connect(widget->viewScale,SIGNAL(doubleClicked(QModelIndex))
}

void MainWindow::createActions()
{
    paramSettingAct = new QAction(tr("&Guitar Settings"),this);
    connect(paramSettingAct,SIGNAL(triggered()),this,SLOT(dialogParam()));

    paramSettingAct2 = new QAction(tr("&Keyboard Setting"),this);
    connect(paramSettingAct2,SIGNAL(triggered()),this,SLOT(dialogParam2()));

    paramSettingAct3 = new QAction(tr("&Guitar View"),this);
    paramSettingAct3->setCheckable(true);
    paramSettingAct3->setChecked(true);
    //connect(paramSettingAct3,SIGNAL(triggered()),widget,SLOT(toggleGuitarView()));
    connect(paramSettingAct3,SIGNAL(triggered()),this,SLOT(sendData8()));
    connect(this, SIGNAL(redirectData8(bool)),widget,SLOT(setGuitarView(bool)));

    paramSettingAct4 = new QAction(tr("&Keyboard View"),this);
    paramSettingAct4->setCheckable(true);
    paramSettingAct4->setChecked(true);
    //connect(paramSettingAct4,SIGNAL(triggered()),widget,SLOT(toggleGuitarView()));
    connect(paramSettingAct4,SIGNAL(triggered()),this,SLOT(sendData9()));
    connect(this, SIGNAL(redirectData9(bool)),widget,SLOT(setPianoView(bool)));

    exitAct= new QAction(tr("&Exit"), this);
    connect(exitAct,SIGNAL(triggered()),this,SLOT(close()));
}

void MainWindow::createMenus()
{
    paramMenu = menuBar()->addMenu(tr("&Settings"));
    paramMenu->addAction(paramSettingAct);
    paramMenu->addAction(paramSettingAct2);
    paramMenu->addSeparator();
    paramMenu->addAction(exitAct);
    paramMenu = menuBar()->addMenu(tr("&Display"));
    paramMenu->addAction(paramSettingAct3);
    paramMenu->addAction(paramSettingAct4);
}

void MainWindow::dialogParam()
{
    set.show();
}

void MainWindow::dialogParam2()
{
    set2.show();
}
