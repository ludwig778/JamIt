#include "metronomewidget.h"

MetronomeWidget::MetronomeWidget(QWidget *parent) : QWidget(parent)
{    
    setFixedWidth(170);
    startMetronome = new QPushButton(tr("Start"));
    testButton = new QPushButton(tr("test"));
    spinBox = new QSpinBox();
    stopMetronome = new QPushButton(tr("Stop"));
    vboxLayout = new QVBoxLayout();
    hboxLayout = new QHBoxLayout();

    spinBox->setRange(50,300);
    spinBox->setValue(120);

    vboxLayout->addWidget(startMetronome);

    hboxLayout->addWidget(spinBox);
    hboxLayout->addWidget(testButton);

    vboxLayout->addLayout(hboxLayout);
    vboxLayout->addWidget(stopMetronome);

    setLayout(vboxLayout);

    isTimerOn = false;
    connect(startMetronome,SIGNAL(pressed()),this,SLOT(startQTimer()));
    connect(stopMetronome,SIGNAL(pressed()),this,SLOT(stopQTimer()));
    setTimer(173);
}

void MetronomeWidget::setTimer(int timerInterval)
{
    measureCount = 0;
    this->timerInterval = timerInterval;
    if (timer == NULL)
    {
        timer = new QTimer(this);
        timer->setSingleShot(false);
        connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
    }

    timer->setInterval(timerInterval);
    isTimerOn = false;
    elapsedTime = 0.0f;

}

void MetronomeWidget::timerTimeout()
{
    elapsedTime += (0.001f * timerInterval);
    if ( !measureCount )
    {
        qWarning() << "A timeout" << elapsedTime;
    }
    else
    {
        qWarning() << "I timeout" << elapsedTime;
    }
    measureCount++;
    if ( measureCount == 4 )
    {
        emit endOfMeasure();
        measureCount = 0;
    }
}

void MetronomeWidget::startQTimer()
{
    if (isTimerOn == false)
    {
        qWarning() << "Timer on";
        isTimerOn = true;
        timer->start();
    }
    else
    {
        qWarning() << "QTimer is already on";
    }
}

void MetronomeWidget::stopQTimer()
{
    if (isTimerOn == true)
    {
        qWarning() << "Timer off";
        timer->stop();
        isTimerOn = false;
    }
    else
    {
        qWarning() << "QTimer is already off";
    }

}

