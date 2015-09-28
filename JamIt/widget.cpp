#include "widget.h"
#include "guitargraphicview.h"
//#define

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    // Cr�ation des labels
    labelScale = new QLabel("Scale");
    labelPitch = new QLabel("Pitch");

    // Cr�ation des listeviews des gammes, et notes
    viewScale = new QTreeWidget();
    viewPitch = new QListWidget();
    //viewPitch->setResizeMode(QListView::Adjust);

    // Cr�ation de la widget list
    //viewSelectList = new QListWidget();
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // Cr�ation du QPushButton
    setScale = new QPushButton(tr("Actualiser"));
    //setScale->setFixedHeight(50);

    // Cr�ation des VBOX contenant les labels et les listeviews
    vBoxScale = new QVBoxLayout();
    vBoxPitch = new QVBoxLayout();

    // Cr�ation de l'HBOX contenant les VBOX listeviews + labels
    hBoxListView = new QHBoxLayout();

    // Gestion des layouts
    vBoxScale->addWidget(labelScale);
    vBoxScale->addWidget(viewScale);
    vBoxPitch->addWidget(labelPitch);
    vBoxPitch->addWidget(viewPitch);

    hBoxListView->addLayout(vBoxScale);
    hBoxListView->addLayout(vBoxPitch);
    hBoxListView->addWidget(setScale);

    // Cr�ation du VBox contenant tout le layout
    vBoxLayout = new QVBoxLayout(this);

    // GuitarGraphicLayouy Creation
    guitarView = new GuitarGraphicView();

    // PianoGraphicLayouy Creation
    pianoView = new PianoGraphicView();

    // Ajout au VBoxLayout
    vBoxLayout->addLayout(hBoxListView);
    vBoxLayout->addWidget(guitarView);
    vBoxLayout->addWidget(pianoView);
    //vBoxLayout->addWidget(viewSelectList);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    QStringList notes = QStringList()
                                << "A"<<"A#"<<"B"<<"C"
                                <<"C#"<<"D"<<"D#"<<"E"
                                <<"F"<<"F#"<<"G"<<"G#";
    viewPitch->addItems(notes);
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
