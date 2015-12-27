#ifndef SCALESELECTORWIDGET_H
#define SCALESELECTORWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QTreeWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ScaleSelectorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScaleSelectorWidget(QWidget *parent = 0);
    QTreeWidget *treeWidget;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *leftSlideButton;
    QPushButton *rightSlideButton;
    QPushButton *removeButton;
    QVBoxLayout* globalVBox;
    QHBoxLayout* globalHBox;
public slots:
    void addToSelector(QString string, int pitch);
    void updateToSelector(QString string, int pitch);
    void removeFromSelector();
};

#endif // SCALESELECTORWIDGET_H
