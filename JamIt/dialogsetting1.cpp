#include "dialogsetting1.h"

DialogSetting1::DialogSetting1(QWidget *parent) :
    QDialog(parent)
{
    vBoxLayout = new QVBoxLayout();
    hBoxLayout = new QHBoxLayout();
    hBoxLayout2 = new QHBoxLayout();
    spinBox = new QSpinBox();
    spinBox->setMinimum(4);
    spinBox->setMaximum(9);
    spinBox->setValue(6);

    spinBox2 = new QSpinBox();
    spinBox2->setMinimum(5);
    spinBox2->setMaximum(24);
    spinBox2->setValue(12);
    fretNumber = new QLabel(tr("Fret number :"));
    hBoxLayout2->addWidget(fretNumber);
    hBoxLayout2->addWidget(spinBox2);


    okButton = new QPushButton(tr("Ok"));
    denyButton = new QPushButton(tr("Annuler"));

    hBoxLayout->addWidget(okButton);
    hBoxLayout->addWidget(denyButton);

    numberStringLabel = new QLabel(tr("String number :"));

    vBoxLayout->addWidget(numberStringLabel);
    vBoxLayout->addWidget(spinBox);

    gridLayout = new QGridLayout();
    QStringList sequence_len = QStringList()
                                << "A"<<"A#"<<"B"<<"C"
                                <<"C#"<<"D"<<"D#"<<"E"
                                <<"F"<<"F#"<<"G"<<"G#";
    QList<int> liste;

    liste << 7 << 2 << 10 << 5 << 0 << 7 << 2 << 9 << 4;

    comboList.clear();
    for( int i = 0; i < 9; i++)
    {
        stringLabel = new QLabel("String #" + QString::number(i+1)+" : ");
        combo = new QComboBox();
        combo->addItems(sequence_len);
        combo->setCurrentIndex(liste.at(i));
        comboList.append(combo);
        gridLayout->addWidget(stringLabel,i,0);
        gridLayout->addWidget(combo,i,1);
    }


    vBoxLayout->addLayout(gridLayout);
    vBoxLayout->addStretch(255);
    vBoxLayout->addSpacing(10);
    vBoxLayout->addLayout(hBoxLayout2);
    vBoxLayout->addSpacing(10);
    vBoxLayout->addLayout(hBoxLayout);

    setLayout(vBoxLayout);


    connect(okButton,SIGNAL(pressed()),this,SLOT(updateTuningSetting()));
    connect(okButton,SIGNAL(pressed()),this,SLOT(close()));
    connect(denyButton,SIGNAL(pressed()),this,SLOT(close()));
    connect(this->spinBox,SIGNAL(valueChanged(QString)),this,SLOT(updateStringSetting()));
    updateStringSetting();
    setFixedHeight(370);
}

void DialogSetting1::updateStringSetting()
{
    for( int i = 0; i < 9; i++)
    {
        gridLayout->itemAtPosition(i,0)->widget()->setVisible(false);
        gridLayout->itemAtPosition(i,1)->widget()->setVisible(false);
    }
    for( int i = 0; i < spinBox->value(); i++)
    {
        gridLayout->itemAtPosition(i,0)->widget()->setVisible(true);
        gridLayout->itemAtPosition(i,1)->widget()->setVisible(true);
    }
}

void DialogSetting1::updateTuningSetting()
{
    liste2.clear();
    for( int i = 0; i < spinBox->value(); i++)
    {

        liste2 << comboList.at(i)->currentIndex();
    }
}


