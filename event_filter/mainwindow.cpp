#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new MyLabel(this);
    label->move(100, 100);
    label->resize(100, 100);
    label->setText("1");
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    // 事件过滤器
    // 步骤1  为MyLabel安装事件过滤器
    label->installEventFilter(this);

}
// 步骤2 重写eventFilter
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(label == watched)
    {
        if (event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent* ev = static_cast<QMouseEvent*>(event); // 父类允许这么强转给子类，我也没想通
            qDebug() << "event is not translate to mouseReleaseEvent" << ev->x() << ev->y();
            return true; //true代表用户自己处理这个事件，不向下分发
        }
    }
    // 其他默认处理不过滤
    return QWidget::eventFilter(watched, event);
}

MainWindow::~MainWindow()
{
    delete ui;
}


