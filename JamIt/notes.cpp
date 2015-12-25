#include "notes.h"

Notes::Notes()
{
    notes = new QStringList();
    notes->append(QString("A:A#:B:C:C#:D:D#:E:F:F#:G:G#").split(':'));
}

QString Notes::at(int position)
{
    return notes->at(position);
}

QStringList Notes::listReturn()
{
    return *notes;
}

