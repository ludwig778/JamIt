#include "scaledictionary.h"

ScaleDictionary::ScaleDictionary()
{

    treeWidgetItems = new QList<QTreeWidgetItem *>();

    hash = new QHash<QString, QString>();
    QFile jsonFile(":/JSON/Resources/ScaleDirectory.json");
    jsonFile.open(QFile::ReadOnly);
    QJsonDocument doc1 = QJsonDocument().fromJson(jsonFile.readAll());
    QJsonObject jsonObject = doc1.object();
    //qDebug() << jsonObject.value(QString("Scale"));
    //qDebug() << jsonObject.keys();

    QTreeWidgetItem* firstLayerItem;
    QTreeWidgetItem* secLayerItem;
    foreach (const QString &key, jsonObject.keys())
    {
        firstLayerItem = new QTreeWidgetItem();
        firstLayerItem->setText(0, key);
        QJsonObject jsonObject2 = jsonObject.value(QString(key)).toObject();
        foreach (const QString &key2, jsonObject2.keys())
        {
            secLayerItem = new QTreeWidgetItem();
            hash->insert(key2,jsonObject2.value(QString(key2)).toString());
            secLayerItem->setText(0, key2);
            firstLayerItem->addChild(secLayerItem);
            //qDebug() << key2 << jsonObject2.value(QString(key2)).toString();
        }
        treeWidgetItems->append(firstLayerItem);
    }
    //qDebug() << 'ok' << jsonObject;
    //qDebug() << 'ok2' << value;
    //qDebug() << hash->find(QString("Minor melodic")).value();
    //qDebug() << treeWidgetItems->count();
/*
treeWidgetItem->addChild();
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

*/

}

QList<QTreeWidgetItem *> ScaleDictionary::treeWidgetLayout()
{
    return *treeWidgetItems;
}

QString ScaleDictionary::getScaleByName(QString scaleName)
{
    QString test = hash->find(scaleName).value();
    qDebug() << scaleName << test;
    return test;
}

