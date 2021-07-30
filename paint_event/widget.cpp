#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QImage>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Pixmapx绘图设备
    QPixmap pix(300, 300);
    // 填充颜色
    pix.fill(Qt::white);
    // 画家
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(150,150), 50, 50);
    // 保存
    pix.save("e:\\pix.png");

    // QImage 绘图设备
    QImage image(300,300, QImage::Format_RGB32);
    // 填充颜色
    image.fill(Qt::white);
    // 画家
    QPainter painter2(&image);
    painter2.setPen(QPen(Qt::red));
    painter2.drawEllipse(QPoint(150,150), 50, 50);
    // 保存
    image.save("e:\\image.png");
}

Widget::~Widget()
{
    delete ui;
}

// 重写这个绘图事件， 自动会调用，不用显式调用
void Widget::paintEvent(QPaintEvent *event)
{
#if 0
    // 指定画家类的画布为this
    QPainter painter(this);
    // 设置画笔
    QPen pen;
    pen.setColor(QColor(255,0,0));  // 设置颜色
    pen.setWidth(3); // 设置宽度
    pen.setStyle(Qt::DotLine);// 设置风格
    painter.setPen(pen);
    // 设置画刷
    QBrush brush(QColor(0,255,0));
    painter.setBrush(brush);

    // 画直线
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
    // 画圆
    painter.drawEllipse(QPoint(100,100), 50, 50);
    // 画矩形
    painter.drawRect(QRect(20,20,50,100));
    // 画文字
    painter.drawText(QRect(10, 200, 100, 50), "你好world");
#else
    /*******高级设置**************/
    // 指定画家类的画布为this
    QPainter painter(this);
    painter.drawEllipse(QPoint(100,50), 50, 50);
    // 抗锯齿，但是会耗时
    painter.setRenderHint(QPainter::Antialiasing);
    // 移动画家，x方向+100，y方向+0
    painter.translate(100,0);
    // 保存画家的状态
    painter.save();
    painter.drawEllipse(QPoint(200,50), 50, 50);
    // 再次移动画家
    painter.translate(100, 50);
    // 从保存的画家状态中 重置画家
    painter.restore();

#endif

}

