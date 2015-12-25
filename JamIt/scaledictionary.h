#ifndef SCALEDICTIONARY_H
#define SCALEDICTIONARY_H

#include <QTreeWidgetItem>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include <QFile>
#include <QHash>
#include <QDebug>

class ScaleDictionary
{
public:
    ScaleDictionary();
    QJsonDocument* doc;
    QHash<QString, QString>* hash;
    //QTreeWidgetItem* firstLayerItem;
    //QTreeWidgetItem* secLayerItem;
    QList<QTreeWidgetItem *>* treeWidgetItems;

    QList<QTreeWidgetItem *> treeWidgetLayout();
    QString getScaleByName(QString scaleName);
};

#endif // SCALEDICTIONARY_H
