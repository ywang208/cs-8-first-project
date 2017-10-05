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
    // tester
    void on_pushButton_clicked();

    // warehouseshoppers.txt
    void get_wareHouseShoppers();
    // Select Name or ID
    bool on_radioButton_Name_clicked();
    bool on_radioButton_ID_clicked();
    // Info PressedEnter
    void on_lineEdit_EntryInfo_returnPressed();
    // Info Clicked Enter & Clear
    bool on_pushButton_EnterInfo_clicked();
    bool on_pushButton_ClearInfo_clicked();
    // Clicked Yes & No
    bool on_pushButton_Yes_clicked();
    bool on_pushButton_No_clicked();

    // Options 1-8
    bool on_radioButton_Options_1_clicked();
    bool on_radioButton_Options_2_clicked();
    bool on_radioButton_Options_3_clicked();
    bool on_radioButton_Options_4_clicked();
    bool on_radioButton_Options_5_clicked();
    bool on_radioButton_Options_6_clicked();
    bool on_radioButton_Options_7_clicked();
    bool on_radioButton_Options_8_clicked();
    // Reports 1-5
    bool on_radioButton_Reports_1_clicked();
    bool on_radioButton_Reports_2_clicked();
    bool on_radioButton_Reports_3_clicked();
    bool on_radioButton_Reports_4_clicked();
    bool on_radioButton_Reports_5_clicked();


private:
    Ui::WholesaleClubMembers *ui;

    // Basic input variables warehouseshoppers.txt
    MembersList<std::string>* members_name;
    MembersList<size_t>* members_id;
    MembersList<std::string>* members_type;
    MembersList<std::string>* expiration_date;


};

#endif // WHOLESALECLUBMEMBERS_H
