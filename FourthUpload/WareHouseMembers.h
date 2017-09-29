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
    // membership text file input/output
    bool on_txtFileEntry_pushButton_clicked();
    // membership type (Basic, Preferred, All)
    bool on_Basic_radioButton_clicked();
    bool on_Preferred_radioButton_clicked();
    bool on_All_radioButton_clicked();
    // membership edit name, id, items
    bool on_name_pushButton_clicked();
    bool on_id_pushButton_clicked();
    bool on_items_pushButton_clicked();
    // members date
    bool on_date_pushButton_clicked();
    bool on_enterDate_pushButton_clicked();
    // pushButtons prices, rebate, sorted
    void on_prices_pushButton_clicked();
    void on_rebate_pushButton_clicked();
    void on_sored_pushButton_clicked();


private:
    Ui::WareHouseMembers* ui;
    MembersList<std::string>* members_date;
    MembersList<size_t>* members_id;
    MembersList<std::string>* members_items;
    MembersList<double>* items_price;
    MembersList<size_t>* items_quantity;
    MembersList<double>* preferred_rebate;
    Date<size_t>* members_Date;
};

#endif // WAREHOUSEMEMBERS_H
