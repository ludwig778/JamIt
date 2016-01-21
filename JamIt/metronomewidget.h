#ifndef METRONOMEWIDGET_H
#define METRONOMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QTimer>

class MetronomeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MetronomeWidget(QWidget *parent = 0);
    QPushButton* startMetronome;
    QPushButton* testButton;
    QSpinBox* spinBox;
    QPushButton* stopMetronome;
    QVBoxLayout* vboxLayout;
    QHBoxLayout* hboxLayout;

private:
    bool isTimerOn;
    int timerInterval;
    QTimer* timer;
    float elapsedTime;
    int measureCount;

signals:
    void endOfMeasure();

public slots:
    void startQTimer();
    void stopQTimer();
    void setTimer(int timerInterval);
    void timerTimeout();
};

#endif // METRONOMEWIDGET_H
