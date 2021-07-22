#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 1、模态对话框，  不可以对其他窗口进行操作
    connect(ui->actionDialogFix, &QAction::triggered, this, [=](){
        QDialog dialog;
        dialog.exec();
    });

    // 2、非模态对话， 可以对其他窗口进行操作
    connect(ui->actionDialogNotFix, &QAction::triggered, this, [=](){
        QDialog*dialog = new QDialog(this);
        dialog->setAttribute(Qt::WA_DeleteOnClose); // 关闭对话框后，自动释放资源 属性
        dialog->show();
    });

    // 3、已经封装好的几种消息对话框 (模态对话框)
    connect(ui->actionCritical, &QAction::triggered, this, [=](){
        QMessageBox::critical(this, "Crital", "message...");
    });

    connect(ui->actionQuestion, &QAction::triggered, this, [=](){
        if (QMessageBox::Yes == QMessageBox::question(this, "question", "message...") )
        {
            qDebug() << "Retrun Yes";
        }
    });
    connect(ui->actionInformation, &QAction::triggered, this, [=](){
        QMessageBox::information(this, "information", "message...");
    });
    connect(ui->actionWarnning, &QAction::triggered, this, [=](){
        QMessageBox::warning(this, "warning", "message...");
    });

    // 4、自己定义的消息对话框
    connect(ui->actionMyMsg, &QAction::triggered, this, [=](){
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setAttribute(Qt::WA_DeleteOnClose); // 关闭对话框后，自动释放资源 属性
        msgBox->setText("This is my message box");
        msgBox->setInformativeText("This is info text");
        msgBox->setDetailedText("This is detail text");
        msgBox->setStandardButtons(QMessageBox::Save
                                  | QMessageBox::Discard
                                  | QMessageBox::Cancel);
        msgBox->setDefaultButton(QMessageBox::Save);
        int ret = msgBox->exec();
        switch (ret)
        {
        case QMessageBox::Save:
            qDebug() << "Save document!";
            break;
        case QMessageBox::Discard:
            qDebug() << "Discard changes!";
            break;
        case QMessageBox::Cancel:
            qDebug() << "Close document!";
            break;
        }
    });

    // 5、标准对话框
    // 5.1 文件或者目录
    connect(ui->actionOpen, &QAction::triggered, this, [=](){
        QString fileName = QFileDialog::getOpenFileName(this, "Open File", "c:/", "Text files (*.txt *.c *.cpp)");
        qDebug() << fileName;
    });
    // 5.2 颜色
    connect(ui->actionColor, &QAction::triggered, this, [=](){
        QColor color = QColorDialog::getColor(QColor(255,255,255));
        qDebug() << color.red() << color.green() << color.blue();
    });
    // 5.3 字体
    connect(ui->actionFont, &QAction::triggered, this, [=](){
        bool ok;
        QFont font = QFontDialog::getFont(&ok);
        qDebug() << font.toString();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

