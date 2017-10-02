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
    // GET INPUT TEXT FILE
    void get_data();
    // ENTER IN LINEEDIT
    void on_lineEdit_MemberEntry_returnPressed();
    // SUBMIT BUTTON
    bool on_pushButton_Submit_clicked();
    // CLEAR BUTTON
    bool on_pushButton_Clear_clicked();
    // CLICK YES
    bool on_pushButton_Yes_clicked();
    // CLICK NO
    bool on_pushButton_No_clicked();




    // OPTIONS
    bool on_radioButton_optionsTotal_clicked();
    bool on_radioButton_optionsSearch_clicked();
    bool on_radioButton_optionsDate_clicked();
    bool on_radioButton_optionsAdd_clicked();
    bool on_radioButton_optionsDelete_clicked();
    bool on_radioButton_optionsPurchases_clicked();
    bool on_radioButton_optionsReport_clicked();
    bool on_radioButton_optionsQuit_clicked();

    // REPORTS
    bool on_radioButton_reportsPrintAnyDay_clicked();
    bool on_radioButton_reportsPrintTotal_clicked();
    bool on_radioButton_reportsQttSorted_clicked();
    bool on_radioButton_reportsRebateSorted_clicked();
    bool on_radioButton_reportsAmountDue_clicked();
    bool on_radioButton_reportQuit_clicked();

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
