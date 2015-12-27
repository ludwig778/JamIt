#ifndef WIDGET_H
#define WIDGET_H

#include "guitargraphicview.h"
#include "pianographicview.h"
#include "scaleselectorwidget.h"
#include <QWidget>
#include <QLabel>
#include <QListView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QListWidget>
#include <QPushButton>
#include <QtXml>
#include <QTextStream>
#include <QtCore>
#include <notes.h>
#include <scaledictionary.h>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    GuitarGraphicView *guitarView;
    PianoGraphicView *pianoView;
    ScaleSelectorWidget *scaleSelector;

    QList<QStringList> viewScaleList;

    QPushButton* setScale;
    QLabel *labelScale;
    QLabel *labelPitch;
    QTreeWidget *viewScale;
    QListWidget *viewPitch;
    QListWidget *viewSelectList;
    QVBoxLayout *vBoxScale;
    QVBoxLayout *vBoxPitch;
    QHBoxLayout *hBoxListView;
    QVBoxLayout *vBoxLayout;
    QList<int> tuning;
    ScaleDictionary* dict;

    QTreeWidgetItem *itm;
    QTreeWidgetItem *itm2;

private:
    Notes* notes;

signals:
    void redirectData5(QString scalePattern, int pitch);
    void redirectData7(QString string, int pitch);
    void redirectData8(QTreeWidgetItem* item,int pitch);
    void redirectData9(QString string, int pitch);

public slots:
    void testqdebud();
    void setGuitarView(bool view);
    void setPianoView(bool view);

    void sendData1(QModelIndex){emit redirectData5(dict->getScaleByName(viewScale->currentItem()->text(0)),viewPitch->currentRow());}
    void sendData2(QTreeWidgetItem* item,int)
    {
        if(item->parent())
        {
            emit redirectData5(dict->getScaleByName(viewScale->currentItem()->text(0)),viewPitch->currentRow());
        }
    }
    void sendData3(QTreeWidgetItem*,QTreeWidgetItem*)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item = scaleSelector->treeWidget->currentItem();
        emit redirectData5(dict->getScaleByName(item->text(1)),
                           notes->getIndexByNote(item->text(0)));
    }

    void sendData5()
    {
        if(viewScale->currentItem()->parent())
        {
            emit redirectData5(dict->getScaleByName(viewScale->currentItem()->text(0)),viewPitch->currentRow());
        }
    }

    void sendData7()
    {
        if(viewScale->currentItem()->parent())
        {
            emit redirectData7(viewScale->currentItem()->text(0),viewPitch->currentRow());
        }
    }
    void sendData9()
    {
        if(viewScale->currentItem()->parent())
        {
            emit redirectData9(viewScale->currentItem()->text(0),viewPitch->currentRow());
        }
    }

    //void sendData8(){emit redirectData8(viewScale->currentItem()->text(0),viewPitch->currentRow());}

};

#endif // WIDGET_H
