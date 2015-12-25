#include "widget.h"
#include "guitargraphicview.h"
//#define

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    // Création des labels
    labelScale = new QLabel("Scale");
    labelPitch = new QLabel("Pitch");

    // Création des listeviews des gammes, et notes
    viewScale = new QTreeWidget();
    viewPitch = new QListWidget();
    //viewPitch->setResizeMode(QListView::Adjust);

    // Création de la widget list
    //viewSelectList = new QListWidget();
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // Création du QPushButton
    setScale = new QPushButton(tr("Actualiser"));
    //setScale->setFixedHeight(50);

    // Création des VBOX contenant les labels et les listeviews
    vBoxScale = new QVBoxLayout();
    vBoxPitch = new QVBoxLayout();

    // Création de l'HBOX contenant les VBOX listeviews + labels
    hBoxListView = new QHBoxLayout();

    // Gestion des layouts
    vBoxScale->addWidget(labelScale);
    vBoxScale->addWidget(viewScale);
    vBoxPitch->addWidget(labelPitch);
    vBoxPitch->addWidget(viewPitch);

    hBoxListView->addLayout(vBoxScale);
    hBoxListView->addLayout(vBoxPitch);
    hBoxListView->addWidget(setScale);

    // Création du VBox contenant tout le layout
    vBoxLayout = new QVBoxLayout(this);

    // GuitarGraphicLayouy Creation
    guitarView = new GuitarGraphicView();

    // PianoGraphicLayouy Creation
    pianoView = new PianoGraphicView();

    // ScaleSelector Creation
    scaleSelector = new ScaleSelectorWidget();

    // Ajout au VBoxLayout
    vBoxLayout->addLayout(hBoxListView);
    vBoxLayout->addWidget(guitarView);
    vBoxLayout->addWidget(pianoView);
    vBoxLayout->addWidget(scaleSelector);
    //vBoxLayout->addWidget(viewSelectList);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    notes = new Notes();

    viewPitch->addItems(notes->listReturn());
    //viewPitch->FixedSize(50,150);
    viewPitch->setCurrentRow(0);

    Dom = new Xml_Dom(":/XML/Resources/ScaleDirectory.xml");
    viewScaleList.clear();
    viewScaleList.append(Dom->loadedList);
/*
    viewSelectList->setViewMode(QListView::IconMode);
    //viewSelectList->setIconSize(QSize(96, 84));
    //viewSelectList->setMovement(QListView::Static);
    viewSelectList->setMaximumWidth(800);
    viewSelectList->setSpacing(12);
    viewSelectList->setDragDropMode(QAbstractItemView::InternalMove);

    viewSelectList->addItem("TEST1TEST1TEST1\ntest");
    viewSelectList->addItem("TEST2TEST2TEST2");
    viewSelectList->addItem("TEST3TEST3TEST3");
*/
    loadingScale();

    viewScale->setColumnCount(1);
    viewScale->headerItem()->setHidden(true);
    //viewScale->setFixedSize(250,150);


    // SELECTORSCALEWIDGET SIGNALS
    connect(scaleSelector->addButton,SIGNAL(pressed()),this,SLOT(sendData7()));
    connect(this, SIGNAL(redirectData7(QString,int)),scaleSelector,SLOT(addToSelector(QString,int)));
    //connect(scaleSelector->updateButton,SIGNAL(pressed()),,);
    //connect(scaleSelector->leftSlideButton,SIGNAL(pressed()),,);
    //connect(scaleSelector->rightSlideButton,SIGNAL(pressed()),,);
    //connect(scaleSelector->removeButton,SIGNAL(pressed()),,);

    //connect(scaleSelector->listWidget,SLOT

    // FROM MAINWINDOW TO WIDGET
    connect(setScale,SIGNAL(pressed()),this,SLOT(testqdebud()));

    connect(setScale,SIGNAL(pressed()),this,SLOT(sendData5()));
    connect(this, SIGNAL(redirectData5(QString,int)),guitarView,SLOT(updateScale(QString,int)));
    connect(this, SIGNAL(redirectData5(QString,int)),pianoView,SLOT(updateScale(QString,int)));

    connect(viewPitch,SIGNAL(doubleClicked(QModelIndex)),guitarView,SLOT(updateDoubleClickPitch(QModelIndex)));
    connect(viewPitch,SIGNAL(doubleClicked(QModelIndex)),pianoView,SLOT(updateDoubleClickPitch(QModelIndex)));
    connect(viewScale,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),guitarView,SLOT(updateDoubleClickScale(QTreeWidgetItem*,int)));
    connect(viewScale,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),pianoView,SLOT(updateDoubleClickScale(QTreeWidgetItem*,int)));
}

void Widget::loadingScale()
{
    for(int i = 0; i < viewScaleList.length(); i++)
    {
        if(viewScaleList.at(i).length() == 1)
        {
            itm = new QTreeWidgetItem();
            itm->setText(0,viewScaleList.at(i).at(0));
            itm->setText(1,"");
        }
        if(viewScaleList.at(i).length() > 1)
        {
            itm2 = new QTreeWidgetItem();
            itm2->setText(0,viewScaleList.at(i).at(0));
            itm2->setText(1,viewScaleList.at(i).at(1));
            viewScale->addTopLevelItem(itm);
            itm->addChild(itm2);
        }
    }
}

void Widget::testqdebud()
{
    qDebug() << viewScale->currentItem()->text(0);
    qDebug() << viewScale->currentItem()->text(1);
}

void Widget::setGuitarView(bool view)
{
    guitarView->setVisible(view);
}

void Widget::setPianoView(bool view)
{
    pianoView->setVisible(view);
}
