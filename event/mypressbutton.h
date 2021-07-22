#ifndef MYPRESSBUTTON_H
#define MYPRESSBUTTON_H

#include <QPushButton>

class MyPressButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPressButton(QWidget *parent = nullptr);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:

};

#endif // MYPRESSBUTTON_H
