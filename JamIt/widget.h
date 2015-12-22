#ifndef WIDGET_H
#define WIDGET_H

#include "guitargraphicview.h"
#include "pianographicview.h"
#include "scaleselectorwidget.h"
#include "xml_dom.h"
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
#include <QDomDocument>
#include <QtCore>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    GuitarGraphicView *guitarView;
    PianoGraphicView *pianoView;
    void loadingScale();
    ScaleSelectorWidget *scaleSelector;

    Xml_Dom* Dom;
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

    QTreeWidgetItem *itm;
    QTreeWidgetItem *itm2;

signals:
    void redirectData3(int pitch);
    void redirectData4(int pitch);

    void redirectData5(QString scalePattern);
    void redirectData6(QString scalePattern);

    void redirectData7(QString scalePattern);

public slots:
    void testqdebud();
    void setGuitarView(bool view);
    void setPianoView(bool view);

    void sendData3(){emit redirectData3(viewPitch->currentRow());}
    void sendData4(){emit redirectData4(viewPitch->currentRow());}

    void sendData5(){emit redirectData5(viewScale->currentItem()->text(1));}
    void sendData6(){emit redirectData6(viewScale->currentItem()->text(1));}

    void sendData7(){emit redirectData7(viewPitch->currentRow(),);}

};

#endif // WIDGET_H
