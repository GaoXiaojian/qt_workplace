#include "myslider.h"
#include "ui_myslider.h"

MySlider::MySlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MySlider)
{
    ui->setupUi(this);
    void (QLCDNumber:: *plcdNumberSlot)(int) = &QLCDNumber::display;
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->lcdNumber, plcdNumberSlot);

}

MySlider::~MySlider()
{
    delete ui;
}

void MySlider::setValue(int num)
{
    ui->horizontalSlider->setValue(num);
}
