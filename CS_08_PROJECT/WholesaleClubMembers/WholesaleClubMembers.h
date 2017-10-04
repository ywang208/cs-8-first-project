#ifndef WHOLESALECLUBMEMBERS_H
#define WHOLESALECLUBMEMBERS_H
#define IO_ReadOnly QIODevice::ReadOnly
#include <QMainWindow>
#include <QTextStream>
#include <QWidget>
#include <QString>
#include <QtDebug>
#include <QLabel>
#include <QFile>
#include "MembersList.h"
QT_BEGIN_NAMESPACE
class QTextBrowser;
class QRadioButton;
class QPushButton;
class QLineEdit;
class QGroupBox;
QT_END_NAMESPACE

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
    void get_shoppers();                            // warehouseshoppers.txt
    void on_lineEdit_MembersEntry_returnPressed();  // Members Entry; Pressed Enter
    bool on_radioButton_ID_clicked();               // Members ID Clicked
    bool on_radioButton_name_clicked();             // Members Name Clicked
    bool on_pushButton_Enter_clicked();             // Members Entry; Clicked Enter
    bool on_pushButton_Clear_clicked();             // Members Entry; Clicked Clear
    bool on_pushButton_Yes_clicked();               // Members Entry; Clicked Yes
    bool on_pushButton_No_clicked();                // Members Entry; Clicked No
    // Members Entry; RadioButton Options 1-8
    bool on_radioButton_Options_1_clicked();
    bool on_radioButton_Options_2_clicked();
    bool on_radioButton_Options_3_clicked();
    bool on_radioButton_Options_4_clicked();
    bool on_radioButton_Options_5_clicked();
    bool on_radioButton_Options_6_clicked();
    bool on_radioButton_Options_7_clicked();
    bool on_radioButton_Options_8_clicked();
    // Members Entry; RadioButton Reports 1-5
    bool on_radioButton_Reports_1_clicked();
    bool on_radioButton_Reports_2_clicked();
    bool on_radioButton_Reports_3_clicked();
    bool on_radioButton_Reports_4_clicked();
    bool on_radioButton_Reports_5_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::WholesaleClubMembers *ui;
    // Basic input variables warehouseshoppers.txt
    MembersList<std::string>* members_name;
    MembersList<size_t>* members_id;
    MembersList<std::string>* members_type;
    MembersList<std::string>* expiration_date;
    // Needed for display
    //MembersList<double>* spent_amount;
    //MembersList<double>* rebate_amount;
    //MembersList<double>* daily_total_amount;
    //MembersList<double>* yearly_total_amount;
    // Input variables day1.txt,day2.txt,etc
    //MembersList<std::string>* items_name;
    //MembersList<size_t>* items_quantity;
    //MembersList<double>* items_price;
};

#endif // WHOLESALECLUBMEMBERS_H
