#ifndef SCALESELECTORWIDGET_H
#define SCALESELECTORWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QTreeWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

class ScaleSelectorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScaleSelectorWidget(QWidget *parent = 0);
    QTreeWidget *treeWidget;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *beforeButton;
    QPushButton *afterButton;
    QPushButton *removeButton;
    QVBoxLayout* globalVBox;
    QHBoxLayout* globalHBox;
public slots:
    void addToSelector(QString string, int pitch);
    void updateToSelector(QString string, int pitch);
    void removeFromSelector();
    void putCurrentScaleBefore();
    void putCurrentScaleAfter();
    void toNextScale();
};

#endif // SCALESELECTORWIDGET_H
