#include "xml_dom.h"
#include <iostream>
using namespace std;

Xml_Dom::Xml_Dom() : QWidget()
{
}

Xml_Dom::Xml_Dom(QString fileName)
{
    loadedList.clear();


    QDomDocument document;

    //Load the file
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load document";
        }
        file.close();
    }

    //Get the root element
    QDomElement root = document.firstChildElement();

    //List the book
    //ListElements(root,"Type","Name");

    //Get the chapters
    QDomNodeList books = root.elementsByTagName("Type");
    for(int i = 0; i < books.count();i++)
    {
        QDomNode booknode = books.at(i);
        //Convert to an element
        if(booknode.isElement())
        {
            QDomElement book = booknode.toElement();
            stringList.clear();
            stringList.append(book.attribute("Name"));
            loadedList.append(stringList);
            qDebug() << "Chapters in " << book.attribute("Name");
            ListElements(book,"Mode","Name");
        }
    }

    qDebug() << "Finished";
}

void Xml_Dom::ListElements(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);

    //qDebug() << "Total items" << items.count();

    for(int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);

        //Convert to element
        if(itemnode.isElement())
        {
            QDomElement itemele = itemnode.toElement();
            qDebug() << itemele.attribute(attribute);
            qDebug() << itemele.attribute("value");

            stringList.clear();
            stringList.append(itemele.attribute(attribute));
            stringList.append(itemele.attribute("value"));
            loadedList.append(stringList);
        }
    }
}
