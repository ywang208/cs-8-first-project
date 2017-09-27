#ifndef WAREHOUSEMEMBERS_H
#define WAREHOUSEMEMBERS_H
#include <QtDebug>
#include <QFile>
#include <QMainWindow>
#include <QTextStream>
#include <QString>
#include <QMainWindow>
#include "memberslist.h"
#define IO_ReadOnly QIODevice::ReadOnly
QT_BEGIN_NAMESPACE
class QTextBrowser;
class QRadioButton;
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

namespace Ui {
class WareHouseMembers;
}

class WareHouseMembers : public QMainWindow
{
    Q_OBJECT

public:
    explicit WareHouseMembers(QWidget *parent = 0);
    ~WareHouseMembers();

private slots:
    void on_pushButton_textfile_clicked();
    void on_pushButton_name_clicked();

private:
    Ui::WareHouseMembers *ui;
    MembersList<std::string>* members_date;
    MembersList<size_t>* members_id;
    MembersList<std::string>* members_items;
    MembersList<double>* items_price;
    MembersList<size_t>* items_quantity;
    MembersList<double>* members_total;
};
/*
03/05/2013
12345
1 gallon milk
2.49	13
03/05/2013
*/
#endif // WAREHOUSEMEMBERS_H
