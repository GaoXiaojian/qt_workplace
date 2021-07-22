#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 1、内部定时器
    id = startTimer(1000);

    // 2、自定义定时器
    QTimer* timer = new QTimer(this);
    timer->start(500);
    // 改变Button控件的内容
    connect(timer, &QTimer::timeout, this, [=](){
        static int index = 0;
        ui->pushButton_2->setText(QString::number(index++));
    });
}

Widget::~Widget()
{
    delete ui;
}

// 内部定时器事件的处理， 改变slider进度条的值
void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id)
    {
        static int num = 0;
        ui->widget->setValue(num++);
    }
}

