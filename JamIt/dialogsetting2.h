#ifndef DIALOGSETTING2_H
#define DIALOGSETTING2_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class DialogSetting2 : public QDialog
{
    Q_OBJECT
public:
    explicit DialogSetting2(QWidget *parent = 0);

    QVBoxLayout* vBoxLayout;
    QHBoxLayout* hBoxLayout;
    QLabel* OctaveNumberLabel;
    QSpinBox* spinBox;
    QPushButton* okButton;
    QPushButton* denyButton;
};

#endif // DIALOGSETTING2_H
