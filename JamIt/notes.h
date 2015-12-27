#ifndef NOTES_H
#define NOTES_H

#include <QString>
#include <QStringList>
#include <QDebug>

class Notes
{
public:
    Notes();
    QString at(int position);
    QStringList listReturn();
    int getIndexByNote(QString note);

private:
    QStringList* notes;
};

#endif // NOTES_H
