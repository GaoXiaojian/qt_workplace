#include "databasewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseWidget w;
    w.show();
    return a.exec();
}
