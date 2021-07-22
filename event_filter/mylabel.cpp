#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
#include <QEvent>
#include <QLabel>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::enterEvent(QEvent *event)
{
    QMouseEvent* ev = static_cast<QMouseEvent*>(event); // 父类允许这么强转给子类，我也没想通
    qDebug() << "MyLabel::enterEvent" << ev->x() << ev->y();
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "MyLabel::mousePressEvent" << ev->x() << ev->y();
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug() << "MyLabel::mouseReleaseEvent" << ev->x() << ev->y();
}

// 事件分发器，只要重写父类中的event函数即可
bool MyLabel::event(QEvent *e)
{


    QEvent::Type type = e->type();
    // 对于鼠标按下事件做特殊处理，然后不分发给mousePressEvent处理
    if(type == QEvent::MouseButtonPress)
    {
        QMouseEvent* ev = static_cast<QMouseEvent*>(e); // 父类允许这么强转给子类，我也没想通
        qDebug() << "event is not translate to mousePressEvent" << ev->x() << ev->y();
        return true; //true代表用户自己处理这个事件，不向下分发
    }
    // 其他事件传给父类，照常分发
    return QLabel::event(e);
}




