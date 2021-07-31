#include "databasewidget.h"
#include "ui_databasewidget.h"
#include <QDebug>
#include <QMessageBox>

#include <QDate>

#include <QVariantList>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

DatabaseWidget::DatabaseWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseWidget)
{
    ui->setupUi(this);

    // 新建数据库 新建表

    // 列出支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    // 1、连接数据库
    // 指定某种驱动类型的一个数据系统 QSqlDatabase
    db = QSqlDatabase::addDatabase("QMYSQL");
    // 设置连接属性
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("gxj@123");

    // 2.新建数据库
    // 打开数据库
    if (db.open() == false)
    {
        QMessageBox::critical(this, "Error", db.lastError().text());
        db.close();
    }
    // 新建一个数据库
    db.exec("create database if not exists database_test_1");

    // 连接上刚刚创建好的数据库
    db.setDatabaseName("database_test_1");

    // 重新打开新数据库
    if (db.open() == false)
    {
        QMessageBox::critical(this, "Error", db.lastError().text());
        db.close();
    }
    // sql请求 对象
    QSqlQuery query(db);

#if 0
    // 3、新建表
    // 创建表前先查询表是否已存在，若存在则先删除再创建，若不存在则创建。
    query.exec("drop table if exists student_table");
    // 创建表
    if (
    query.exec("create table if not exists student_table ( id int not NULL PRIMARY KEY AUTO_INCREMENT, name varchar(50) not NULL, age  int not NULL) ") == false)
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
        db.close();
    }
#endif
    // 4、添加数据
    // 定义sql语句模板
    query.prepare("insert into student_table(id, name, age) values(:id, :name, :age)");
    // 实例化模板
    QVariantList stdIds;
    stdIds << NULL << NULL << NULL;  // id主键可以设置为NULL
    QVariantList stdNames;
    stdNames << "Josh" << "Kate" << "Lucy";
    QVariantList stdAges;
    stdAges << 22 <<  25 << 18;
    query.bindValue(":id", stdIds);
    query.bindValue(":name", stdNames);
    query.bindValue(":age", stdAges);
    if(query.execBatch() == false)
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
        db.close();
    }

    // 5、查询数据
    query.exec("select * from student_table");
    while(query.isActive() && query.next())
    {
        qDebug() <<  query.value( 0 ).toInt() << query.value( 1 ).toString()
        << query.value( 2 ).toInt();
    }

    // 6、结果显示到控件中
    // 6.1 实例化model 一定要用指针方式
    model = new QSqlTableModel(this);
    // 6.2 模型设置给视图控件
    ui->tableView->setModel(model);
    // 6.3 指定 表
    model->setTable("student_table");
    // 6.4 查询
    model->select();
    // 6.5 可以自定义表头
    model->setHeaderData(0, Qt::Horizontal, "编号");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "年龄");
    // 6.6 修改表内内容 不影响数据库
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

DatabaseWidget::~DatabaseWidget()
{
    db.close();
    delete ui;
}


void DatabaseWidget::on_pushButtonSubmit_clicked()
{
    model->submitAll();  // 控件表中的修改提交到数据库表中
}

void DatabaseWidget::on_pushButtonRevert_clicked()
{
    model->revertAll(); // 撤销控件表中模型
    model->select();   //  更新数据模型
}

void DatabaseWidget::on_pushButtonSearch_clicked()
{
    QString name = ui->lineEdit->text();
    // 设置过滤条件
    QString sql = QString("name='%1'").arg(name);
    model->setFilter(sql);
    model->select();
}
