#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    // 槽函数
    // 1、既要声明又要实现
    // 2、返回值为void
    // 3、可以有参数，允许重载
    // 4、类继承自QObject且写在public下
    void learn();
    void learn(QString param);
signals:

};

#endif // STUDENT_H
