#include "scaleselectorwidget.h"

ScaleSelectorWidget::ScaleSelectorWidget(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(100);
    treeWidget = new QTreeWidget();
    treeWidget->setHeaderHidden(true);
    treeWidget->setColumnCount(2);
    treeWidget->setColumnWidth(0,47);


/*    tableWidget = new QTableWidget(0,2);
    tableWidget->setShowGrid(false);
    tableWidget->sethea;*/
//    QTreeWidgetItem* t1 = new QTreeWidgetItem()


    addButton = new QPushButton(tr("Add"));
    updateButton = new QPushButton(tr("Update"));
    beforeButton = new QPushButton(tr("<<"));
    afterButton = new QPushButton(tr(">>"));
    removeButton = new QPushButton(tr("Remove"));

    globalVBox = new QVBoxLayout();
    globalHBox = new QHBoxLayout();
    globalVBox->setMargin(0);
    globalHBox->setMargin(0);

    globalVBox->addWidget(addButton);
    globalVBox->addWidget(updateButton);
    globalVBox->addWidget(beforeButton);
    globalVBox->addWidget(afterButton);
    globalVBox->addWidget(removeButton);

    globalHBox->addWidget(treeWidget);
    globalHBox->addLayout(globalVBox);

    setLayout(globalHBox);

}

void ScaleSelectorWidget::addToSelector(QString string, int pitch)
{

    QStringList notes = QStringList()
                                << "A"<<"A#"<<"B"<<"C"
                                <<"C#"<<"D"<<"D#"<<"E"
                                <<"F"<<"F#"<<"G"<<"G#";

    if(treeWidget->topLevelItemCount() == 1)
    {
        if(treeWidget->topLevelItem(0)->isHidden())
        {
            treeWidget->topLevelItem(0)->setText(0,notes.at(pitch));
            treeWidget->topLevelItem(0)->setText(1,string);
            treeWidget->topLevelItem(0)->setHidden(false);
        }
        else
        {
            QTreeWidgetItem* t1 = new QTreeWidgetItem();
            t1->setText(0,notes.at(pitch));
            t1->setText(1,string);
            t1->setTextAlignment(0, 4);
            treeWidget->addTopLevelItem(t1);
            treeWidget->setCurrentItem(t1);
        }
    }
    else
    {
        QTreeWidgetItem* t1 = new QTreeWidgetItem();
        t1->setText(0,notes.at(pitch));
        t1->setText(1,string);
        t1->setTextAlignment(0, 4);
        treeWidget->addTopLevelItem(t1);
        treeWidget->setCurrentItem(t1);
    }
}

void ScaleSelectorWidget::updateToSelector(QString string, int pitch)
{
    QStringList notes = QStringList()
                                << "A"<<"A#"<<"B"<<"C"
                                <<"C#"<<"D"<<"D#"<<"E"
                                <<"F"<<"F#"<<"G"<<"G#";

    if(treeWidget->selectedItems().length() != 0)
    {
        if(treeWidget->topLevelItemCount() == 1)
        {
            if(!treeWidget->topLevelItem(0)->isHidden())
            {
                treeWidget->currentItem()->setText(0,notes.at(pitch));
                treeWidget->currentItem()->setText(1,string);
            }
        }
        else if(treeWidget->topLevelItemCount() > 1)
        {
            treeWidget->currentItem()->setText(0,notes.at(pitch));
            treeWidget->currentItem()->setText(1,string);
        }
    }
}

void ScaleSelectorWidget::removeFromSelector()
{
    if(treeWidget->topLevelItemCount() > 1)
    {
        QTreeWidgetItem* item = treeWidget->currentItem();
        int i = treeWidget->indexOfTopLevelItem(item);
        treeWidget->takeTopLevelItem(i);
        delete item;
    }
    else if(treeWidget->topLevelItemCount() > 0)
    {
        treeWidget->currentItem()->setHidden(true);
    }
    //1treeWidget->reset();
    //treeWidget->currentItem()->

    qDebug() << treeWidget->topLevelItemCount() << treeWidget->currentIndex().row();
}

void ScaleSelectorWidget::putCurrentScaleBefore()
{
    if(treeWidget->selectedItems().length() != 0)
    {
        int itemCount = treeWidget->topLevelItemCount();
        if(itemCount > 1)
        {
            int row = treeWidget->indexOfTopLevelItem(treeWidget->currentItem());
            if(row > 0)
            {
                QTreeWidgetItem* parent = treeWidget->currentItem()->parent();
                QTreeWidgetItem* child = treeWidget->takeTopLevelItem(row-1);
                treeWidget->insertTopLevelItem(row,child);
            }
        }
    }
}

void ScaleSelectorWidget::putCurrentScaleAfter()
{
    if(treeWidget->selectedItems().length() != 0)
    {
        int itemCount = treeWidget->topLevelItemCount();
        if(itemCount > 1)
        {
            int row = treeWidget->indexOfTopLevelItem(treeWidget->currentItem());
            if(row < itemCount-1)
            {
                QTreeWidgetItem* parent = treeWidget->currentItem()->parent();
                QTreeWidgetItem* child = treeWidget->takeTopLevelItem(row+1);
                treeWidget->insertTopLevelItem(row,child);
            }
        }
    }
}

void ScaleSelectorWidget::toNextScale()
{
    if(treeWidget->topLevelItemCount() > 1)
    {
        int scaleCount = treeWidget->topLevelItemCount();
        int row = treeWidget->indexOfTopLevelItem(treeWidget->currentItem());
        //treeWidget->setCurrentItem();
        //treeWidget->setCurrentItem(treeWidget->);

        qDebug() << row << scaleCount;
    }
}
