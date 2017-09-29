#ifndef WAREHOUSEMEMBERS_H
#define WAREHOUSEMEMBERS_H
#include <QtDebug>
#include <QFile>
#include <QMainWindow>
#include <QTextStream>
#include <QDataStream>
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

    bool on_radioButton_Basic_clicked();
    bool on_radioButton_Preferred_clicked();
    bool on_radioButton_All_clicked();

    void on_pushButton_sorted_clicked();

private:
    Ui::WareHouseMembers *ui;
    MembersList<std::string>* members_date;
    MembersList<int>* members_id;
    MembersList<std::string>* members_items;
    MembersList<double>* items_price;
    MembersList<size_t>* items_quantity;
    MembersList<double>* preferred_rebate;


    /*
    03/05/2013
    12345
    1 gallon milk
    2.49	13
    03/05/2013
    */
};
#endif // WAREHOUSEMEMBERS_H
