#include "scaleselectorwidget.h"

ScaleSelectorWidget::ScaleSelectorWidget(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(180);
    listWidget = new QListWidget();
    listWidget->addItem("Item " + QString::number(1));

    addButton = new QPushButton(tr("Add"));
    leftSlideButton = new QPushButton(tr("<<"));
    rightSlideButton = new QPushButton(tr(">>"));
    removeButton = new QPushButton(tr("Remove"));

    globalVBox = new QVBoxLayout();
    globalHBox = new QHBoxLayout();

    globalVBox->addWidget(addButton);
    globalVBox->addWidget(leftSlideButton);
    globalVBox->addWidget(rightSlideButton);
    globalVBox->addWidget(removeButton);

    setLayout(globalVBox);

}

