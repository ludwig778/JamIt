#ifndef GUITARGRAPHICVIEW_H
#define GUITARGRAPHICVIEW_H

#include <QWidget>
#include <QtGui>
//#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QBrush>
#include <QColor>
#include <notes.h>

class GuitarGraphicView : public QWidget
{
    Q_OBJECT
public:
    explicit GuitarGraphicView(QWidget *parent = 0);
    QList<int> tuning;
    QList<int> fretList;
    QList<int> stringList;
    QList<int> fretPattern;
    int pitch;
    int number_fret;
    QList<int> gamme;

protected:
    qint8 nb_string;
    void paintEvent(QPaintEvent *event);

private:
    Notes* notes;

signals:

public slots:
    void updateNbString(int nb);
    void updateTuning(QList<int> tuningSended);
    //void updateScalePitch(int pitch);
    void updateDoubleClickPitch(QModelIndex pitch);
    void updateDoubleClickScale(QTreeWidgetItem* scale,int row);
    void updateScale(QString scalePattern, int pitch);
    void updateFretNumber(int fret);

};

#endif // GUITARGRAPHICVIEW_H
