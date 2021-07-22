#include "qmypushbutton.h"

QMyPushButton::QMyPushButton(QWidget *parent) : QPushButton(parent)
{
    connect(this, &QPushButton::clicked, this, &QMyPushButton::buttonClicked);
}

void QMyPushButton::buttonClicked()
{
    emit this->sigClicked(this->text());
}
