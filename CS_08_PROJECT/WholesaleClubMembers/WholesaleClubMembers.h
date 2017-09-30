#ifndef WHOLESALECLUBMEMBERS_H
#define WHOLESALECLUBMEMBERS_H
#include <QMainWindow>
#include <QTextStream>
#include <QDataStream>
#include <QString>
#include <QFile>
#include <QtDebug>
#include <QWidget>
#include <QLabel>
#include <QStringList>
#include <QTextStream>
#include "MembersList.h"
#define STR_EQUAL 0
#define IO_ReadOnly QIODevice::ReadOnly
QT_BEGIN_NAMESPACE
class QTextBrowser;
class QRadioButton;
class QPushButton;
class QLineEdit;
class QComboBox;
class QGroupBox;
class QGridLayout;
QT_END_NAMESPACE
#define IO_ReadOnly QIODevice::ReadOnly

namespace Ui {
class WholesaleClubMembers;
}

class WholesaleClubMembers : public QMainWindow
{
    Q_OBJECT
public:
    explicit WholesaleClubMembers(QWidget *parent = 0);
    ~WholesaleClubMembers();


private slots:

    bool on_pushButton_clicked();                       // SUBMIT BUTTON
    void on_lineEdit_MemberEntry_returnPressed();       // ENTER IN LINEEDIT

    bool on_pushButton_Clear_clicked();


    void on_pushButton_2_clicked();


private:
    Ui::WholesaleClubMembers *ui;
    // Basic input variables warehouseshoppers.txt
    MembersList<std::string>* members_name;
    MembersList<size_t>* members_id;
    MembersList<std::string>* members_type;
    MembersList<std::string>* expiration_date;
    // Needed for display
    MembersList<double>* spent_amount;
    MembersList<double>* rebate_amount;
    MembersList<double>* daily_total_amount;
    MembersList<double>* yearly_total_amount;
    // Input variables day1.txt,day2.txt,etc
    MembersList<std::string>* items_name;
    MembersList<size_t>* items_quantity;
    MembersList<double>* items_price;

};

#endif // WHOLESALECLUBMEMBERS_H
