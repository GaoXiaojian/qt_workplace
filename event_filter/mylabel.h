#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWidget>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    virtual void enterEvent(QEvent *event) override;

    virtual void mousePressEvent(QMouseEvent *ev) override;

    virtual void mouseReleaseEvent(QMouseEvent *ev) override;

    virtual bool event(QEvent *e) override;
signals:

};

#endif // MYLABEL_H
