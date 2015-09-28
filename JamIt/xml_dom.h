#ifndef XML_DOM_H
#define XML_DOM_H

#include <QtGui>
#include <QtXml>
#include <QDomDocument>
#include <QWidget>
#include <QString>
#include <QList>

class Xml_Dom : public QWidget
{
public:
    Xml_Dom();
    Xml_Dom(QString fileName);
    void ListElements(QDomElement root, QString tagname, QString attribute);

    QList<QStringList> loadedList;
    QStringList stringList;
};

#endif
