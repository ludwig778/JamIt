#ifndef SCALESELECTORWIDGET_H
#define SCALESELECTORWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ScaleSelectorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScaleSelectorWidget(QWidget *parent = 0);
    QListWidget *listWidget;
    QPushButton *addButton;
    QPushButton *leftSlideButton;
    QPushButton *rightSlideButton;
    QPushButton *removeButton;
    QVBoxLayout* globalVBox;
    QHBoxLayout* globalHBox;
};

#endif // SCALESELECTORWIDGET_H