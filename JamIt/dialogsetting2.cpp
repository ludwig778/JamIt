#include "dialogsetting2.h"

DialogSetting2::DialogSetting2(QWidget *parent) :
    QDialog(parent)
{
    vBoxLayout = new QVBoxLayout();
    hBoxLayout = new QHBoxLayout();
    spinBox = new QSpinBox();
    spinBox->setMinimum(1);
    spinBox->setMaximum(5);
    spinBox->setValue(2);
    okButton = new QPushButton(tr("Ok"));
    denyButton = new QPushButton(tr("Annuler"));

    OctaveNumberLabel = new QLabel("Octave number :");

    hBoxLayout->addWidget(okButton);
    hBoxLayout->addWidget(denyButton);

    vBoxLayout->addWidget(OctaveNumberLabel);
    vBoxLayout->addWidget(spinBox);
    vBoxLayout->addLayout(hBoxLayout);

    setLayout(vBoxLayout);


    connect(okButton,SIGNAL(pressed()),this,SLOT(close()));
    connect(denyButton,SIGNAL(pressed()),this,SLOT(close()));
}
