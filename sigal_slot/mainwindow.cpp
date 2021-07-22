#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "qmypushbutton.h"
#include "teacher.h"
#include "student.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1、默认GUI控件中的信号和槽 使用
    QPushButton* btn1 = new QPushButton("OK", this);
    btn1->move(20, 20);
    // 信号和槽 绑定  按键按下时，关闭窗口
    connect(btn1, &QPushButton::clicked, this, &MainWindow::close);


    // 2、自定义类中的 信号和槽 的使用
    Teacher* t = new Teacher(this);
    Student* s = new Student(this);
    // 绑定 老师教授的信号 到  学生学习的槽
    void (Teacher:: *pTeach)(QString) = &Teacher::teach;
    void (Student:: *pLearn)(QString) = &Student::learn;
    // 绑定信号-槽
    connect(t, pTeach, s, pLearn);
    // Qt4版本的写法,  不做函数参数类型的检查
//    connect(t, SIGNAL(teach(QString)), s, SLOT(learn(QString)));

    // 使用emit 触发信号
    emit t->teach("English");
    // 断开信号-槽 绑定
//    disconnect(t, pTeach, s, pLearn);

    // 3、信号绑定信号
    QPushButton* btn2 = new QPushButton(this);
    btn2->setText("English");
    btn2->move(150, 20);
    // 信号和信号 绑定  按键按下时
    // 信号和槽，信号和信号,连接的参数，必须信号函数>=槽函数
    //  lambda表达式(匿名函数)
    //  [](){}
    connect(btn2, &QPushButton::clicked, this, [=](){emit t->teach("Chinese");});


    // 4、练习:一个按键，开关widget页面
    QWidget* widget = new QWidget(nullptr);
    widget->setWindowTitle("new widget");
    QPushButton* btn3 = new QPushButton(this);
    btn3->move(300, 20);
    btn3->setText("open widget");
    connect(btn3, &QPushButton::clicked, this, [=](){
        if(btn3->text() == "open widget")
        {
            btn3->setText("close widget");
            widget->show();
        }
        else
        {
            btn3->setText("open widget");
            widget->close();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

