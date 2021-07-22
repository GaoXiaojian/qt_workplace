#include "mypressbutton.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>

MyPressButton::MyPressButton(QWidget *parent) : QPushButton(parent)
{

}

void MyPressButton::enterEvent(QEvent *event)
{
    QMouseEvent *ev = static_cast<QMouseEvent*>(event);
    qDebug() << "Enter event" << ev->x() << ev->y();
}

void MyPressButton::leaveEvent(QEvent *event)
{
    qDebug() << "leaveEvent";
}

void MyPressButton::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "mouseMoveEvent" << event->x() << event->y();
}

void MyPressButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent"<< event->x() << event->y();
}
