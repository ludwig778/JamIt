#include "scaleselectorwidget.h"

ScaleSelectorWidget::ScaleSelectorWidget(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(100);
    listWidget = new QListWidget();
    listWidget->addItem("Item " + QString::number(1));
    listWidget->addItem("Item " + QString::number(2));
    listWidget->addItem("Item " + QString::number(3));

    addButton = new QPushButton(tr("Add"));
    leftSlideButton = new QPushButton(tr("<<"));
    rightSlideButton = new QPushButton(tr(">>"));
    removeButton = new QPushButton(tr("Remove"));

    globalVBox = new QVBoxLayout();
    globalHBox = new QHBoxLayout();
    globalVBox->setMargin(0);
    globalHBox->setMargin(0);

    globalVBox->addWidget(addButton);
    globalVBox->addWidget(leftSlideButton);
    globalVBox->addWidget(rightSlideButton);
    globalVBox->addWidget(removeButton);

    globalHBox->addWidget(listWidget);
    globalHBox->addLayout(globalVBox);

    setLayout(globalHBox);

}

void ScaleSelectorWidget::addToSelector(QString string, int pitch)
{
    listWidget->addItem("Item " + string + pitch);
}

