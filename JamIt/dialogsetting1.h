#ifndef DIALOGSETTING1_H
#define DIALOGSETTING1_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStringList>
#include <QComboBox>
#include <QList>
#include <notes.h>

class DialogSetting1 : public QDialog
{
    Q_OBJECT
public:
    explicit DialogSetting1(QWidget *parent = 0);

    QVBoxLayout* vBoxLayout;
    QHBoxLayout* hBoxLayout;
    QHBoxLayout* hBoxLayout2;
    QGridLayout* gridLayout;
    QLabel* stringLabel;
    QLabel* numberStringLabel;
    QLabel* stringNumberLabel;
    QLabel* fretNumber;
    QSpinBox* spinBox;
    QSpinBox* spinBox2;
    QPushButton* okButton;
    QPushButton* denyButton;
    QComboBox* combo;
    QList<int> liste2;
    QList<QComboBox *> comboList;

private:
    Notes* notes;

signals:

public slots:
    void updateStringSetting();
    void updateTuningSetting();

};

#endif // DIALOGSETTING1_H
