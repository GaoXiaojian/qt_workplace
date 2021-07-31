#ifndef DATABASEWIDGET_H
#define DATABASEWIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class DatabaseWidget; }
QT_END_NAMESPACE

class DatabaseWidget : public QWidget
{
    Q_OBJECT

public:
    DatabaseWidget(QWidget *parent = nullptr);
    ~DatabaseWidget();

private slots:
    void on_pushButtonSubmit_clicked();

    void on_pushButtonRevert_clicked();

    void on_pushButtonSearch_clicked();

private:
    Ui::DatabaseWidget *ui;
    QSqlTableModel* model;
    QSqlDatabase db;
};
#endif // DATABASEWIDGET_H
