#include "WareHouseMembers.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WareHouseMembers w;
    w.show();
    return a.exec();
}
