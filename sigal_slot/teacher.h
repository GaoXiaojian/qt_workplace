#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 信号函数
    // 1、只声明不实现
    // 2、可以有参数,允许重载
    // 3、返回值为void
    // 4、类必须继承自QObject，并写在signals内
    void teach();
    void teach(QString param);
};

#endif // TEACHER_H
