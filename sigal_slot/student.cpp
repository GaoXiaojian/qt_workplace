#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{
}

void Student::learn()
{
    qDebug() << "student start to learn";
}

void Student::learn(QString param)
{
    qDebug() << "student start to learn, param is" << param.toUtf8().data();
}
