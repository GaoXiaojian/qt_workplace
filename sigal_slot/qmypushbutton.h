#ifndef QMYPUSHBUTTON_H
#define QMYPUSHBUTTON_H

#include <QPushButton>

class QMyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QMyPushButton(QWidget *parent = nullptr);
    void buttonClicked();
signals:
    void sigClicked(QString msg);
};

#endif // QMYPUSHBUTTON_H
