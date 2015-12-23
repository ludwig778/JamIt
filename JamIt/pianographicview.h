#ifndef PIANOGRAPHICVIEW_H
#define PIANOGRAPHICVIEW_H

#include <QWidget>
#include <QtGui>
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QBrush>
#include <QColor>

class PianoGraphicView : public QWidget
{
    Q_OBJECT
public:
    explicit PianoGraphicView(QWidget *parent = 0);
    QList<int> keyList;
    int pitch;
    int octaveNumber;
    QList<int> gamme;

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    //void updateScalePitch(int pitch);
    void updateDoubleClickPitch(QModelIndex pitch);
    void updateDoubleClickScale(QTreeWidgetItem* scale,int row);
    void updateScale(QString scalePattern, int pitch);
    void updateOctaveCount(int octave);

};

#endif // PIANOGRAPHICVIEW_H
