#ifndef WHOLESALECLUBMEMBERS_H
#define WHOLESALECLUBMEMBERS_H
#define IO_ReadOnly QIODevice::ReadOnly
#define IO_WriteOnly QIODevice::WriteOnly
#define TAX_RATE 0.0875         // Tax rate
#define REBATE_RATE 0.0500      // Rebate rate
#define PREFERRED_FEE 75        // Preferred fees
#define BASIC_FEE 60            // Basic fees
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
class QComboBox;
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
    void default_html();
    void logo_html();
    void invalid_html();
    void name_html();
    void id_html();
    void options_html();
    void default_settings();
    void options_default_settings();
    void member_entry_settings();
    void member_entry_settings_vice();
    void push_button_back_settins();
    void get_warehouseshoppers();
    void get_dayspurcahsed();
    void output_txt_file();
    // 1. ID or Name
    bool on_radioButton_ID_clicked();
    bool on_radioButton_Name_clicked();
    void valid_user_entry();
    // 2. Enter; pressed clicked; clear clicked
    bool on_pushButton_Enter_clicked();
    bool on_pushButton_Clear_clicked();
    void on_lineEdit_MembersEntry_returnPressed();
    // 3. options
    bool on_radioButton_MembersOptions_1_clicked();
    bool on_radioButton_MembersOptions_2_clicked();
    bool on_radioButton_MembersOptions_3_clicked();
    bool on_radioButton_MembersOptions_4_clicked();
    bool on_radioButton_MembersOptions_5_clicked();
    bool on_radioButton_MembersOptions_6_clicked();
    bool on_radioButton_MembersOptions_7_clicked();
    bool on_radioButton_MembersOptions_8_clicked();
    bool on_radioButton_MembersOptions_9_clicked();
    // 4. reports
    bool on_radioButton_MembersReports_1_clicked();
    bool on_radioButton_MembersReports_2_clicked();
    bool on_radioButton_MembersReports_3_clicked();
    bool on_radioButton_MembersReports_4_clicked();
    bool on_radioButton_MembersReports_5_clicked();
    bool on_radioButton_MembersReports_6_clicked();
    // 5. yes or no
    bool on_pushButton_Yes_clicked();
    bool on_pushButton_No_clicked();
    // edit options 2
    void on_lineEdit_MembersOption_2_returnPressed();
    bool on_pushButton_Clear_MembersOption_2_clicked();
    bool on_pushButton_Enter_MembersOption_2_clicked();
    bool on_pushButton_Back_MembersOption_2_clicked();
    // edit options 3
    void on_lineEdit_MembersOption_3_returnPressed();
    bool on_pushButton_Clear_MembersOption_3_clicked();
    bool on_pushButton_Enter__MembersOption_3_clicked();
    bool on_pushButton_Back_MembersOption_3_clicked();
    // edit options 4
    void on_lineEdit_MembersOption_4_returnPressed();
    bool on_pushButton_Clear_MembersOption_4_clicked();
    bool on_pushButton_Enter_MembersOption_4_clicked();
    bool on_pushButton_Back_MembersOption_4_clicked();
    // edit options 5
    void on_lineEdit_MembersOption_5_returnPressed();
    bool on_pushButton_Clear_MembersOption_5_clicked();
    bool on_pushButton_Enter_MembersOption_5_clicked();
    bool on_pushButton_Back_MembersOption_5_clicked();
    // edit options 6
    void on_lineEdit_MembersOption_6_returnPressed();
    bool on_pushButton_Clear_MembersOption_6_clicked();
    bool on_pushButton_Enter_MembersOption_6_clicked();
    bool on_pushButton_Back_MembersOption_6_clicked();
    // Checkboxes
    bool on_checkBox_Back_clicked();
    bool on_checkBox_Cancel_clicked();
    bool on_checkBox_Downgrade_clicked();
    bool on_checkBox_Update_clicked();

    void Menu(const QString& choice);
private:
    Ui::WholesaleClubMembers *ui;
    // Basic input variables warehouseshoppers.txt
    MembersList<std::string>* members_name;
    MembersList<size_t>* members_id;
    MembersList<std::string>* members_type;
    MembersList<std::string>* expiration_date;
    MembersList<double>* total_amount;
    MembersList<double>* rebate_amount;
    // Basic input variables day(n).txt
    MembersList<std::string>* purchase_of_date;
    MembersList<size_t>* purchase_members_id;
    MembersList<std::string>* purchase_item_name;
    MembersList<std::string>* item_price_quantity;
    MembersList<double>* items_price;
    MembersList<size_t>* items_quanty;
};

#endif // WHOLESALECLUBMEMBERS_H
// 03/05/2013
// 12345
// 1 gallon milk
// 2.49	   13
