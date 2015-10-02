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

public slots:
    void testqdebud();
    void setGuitarView(bool view);
    void setPianoView(bool view);

};

#endif // WIDGET_H
