#include "WholesaleClubMembers.h"
#include "ui_WholesaleClubMembers.h"

WholesaleClubMembers::WholesaleClubMembers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WholesaleClubMembers)
{
    ui->setupUi(this);

    // Basic input variables warehouseshoppers.txt
    members_name = new MembersList<std::string>;
    members_id = new MembersList<size_t>;
    members_type = new MembersList<std::string>;
    expiration_date = new MembersList<std::string>;

    // DEFAULT GREETINGS Member Entry TextBrowser
    QString html_qstr_default = "<span style=\"font-size:28pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("Welcome to Wholesale Club!<br/><br/><br/><br/>");
    html_qstr_default.append("</span>");
    html_qstr_default.append("<span style=\"font-size:18pt;font-weight:600;color:#ff0000;\">");
    html_qstr_default.append("<br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                             "Please select either your name or ID to enter in:");
    html_qstr_default.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_default);

    // DEFAULT IMAGE Display TextBrowser
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_DisplayReports->setVisible(true);
    QPixmap warehouse_logo("/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/"
                           "build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug/"
                           "warehouselogo.png");
    ui->label_DisplayReports->setPixmap(warehouse_logo);

    // Setting name and id
    ui->groupBox_Name_ID->setVisible(true);
    ui->groupBox_Name_ID->setEnabled(true);

    // Setting user lineEdit
    ui->label_MembersEntry->setVisible(false);
    ui->lineEdit_MembersEntry->setVisible(false);
    ui->lineEdit_MembersEntry->setEnabled(false);

    // Setting pushButtons for submit and clear to enabled
    ui->pushButton_Enter->setVisible(false);
    ui->pushButton_Enter->setEnabled(false);
    ui->pushButton_Clear->setVisible(false);
    ui->pushButton_Clear->setEnabled(false);

    // Setting Yes and No buttons to invisible until needed
    ui->pushButton_Yes->setVisible(false);
    ui->pushButton_Yes->setEnabled(false);
    ui->pushButton_No->setVisible(false);
    ui->pushButton_No->setEnabled(false);

    // Setting users options and reports to invisible until needed
    ui->groupBox_Options->setVisible(false);
    ui->groupBox_Options->setEnabled(false);
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);

}

WholesaleClubMembers::~WholesaleClubMembers()
{
    delete ui;
}

// testing
void WholesaleClubMembers::on_lineEdit_returnPressed()
{

    get_shoppers();

    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);

    ui->textBrowser_DisplayReports->setText(QString::fromStdString(
                                            "Name: " + members_name->output_linkedlist() + "\n" +
                                            "ID: " + members_id->output_linkedlist() + "\n" +
                                            "Type: " + members_type->output_linkedlist() + "\n" +
                                            "Exp Date: " + expiration_date->output_linkedlist() + "\n"));

    size_t position = members_name->find_position_member(ui->lineEdit->text().toStdString());
    ui->textBrowser_MembersEntry->setText("found at position: " + QString::number(position));
    ui->lineEdit->clear();
}

// warehouseshoppers.txt
void WholesaleClubMembers::get_shoppers()
{
    QFile file("/Users/philipkim/Qt/QtProject/Computer_Science_08"
               "/CS_08_PROJECT/build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug"
               "/warehouseshoppers.txt");
    if(!file.exists())
        ui->textBrowser_MembersEntry->setText("Text file does not exist");
    else if(!file.open(IO_ReadOnly))
        ui->textBrowser_MembersEntry->setText("Error with text file");
    else
    {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        size_t counter = 0;
        QString QStr_line;
        while(!in.atEnd())
        {
            ++counter;
            QStr_line = in.readLine()/*.toLower()*/;
            members_name->push_back(QStr_line.toStdString());
            QStr_line = in.readLine()/*.toLower()*/;
            members_id->push_back(QStr_line.toULongLong());
            QStr_line = in.readLine()/*.toLower()*/;
            members_type->push_back(QStr_line.toStdString());
            QStr_line = in.readLine()/*.toLower()*/;
            expiration_date->push_back(QStr_line.toStdString());
        }
    }
    file.close();
}

// Members Entry; Pressed Enter
void WholesaleClubMembers::on_lineEdit_MembersEntry_returnPressed()
{
    // Get warehouseshoppers.txt
    get_shoppers();
    // If members_name or id match the warehouseshoppers.txt
    if(members_name->find_member(ui->lineEdit_MembersEntry->text().toStdString()) ||
       members_id->find_member(ui->lineEdit_MembersEntry->text().toULongLong()))
    {
        // Display users options
        QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
        html_qstr_default.append("Welcome back to WholeSaleClub, ");
        html_qstr_default.append(ui->lineEdit_MembersEntry->text());
        html_qstr_default.append("! Glad to see you today.<br/>How can we assist you today?<br/>"
                                 "Please choose from these options:<br/>"
                                 "1. Totol purchases for this month<br/>"
                                 "2. Item's quantity and purchases<br/>"
                                 "3. Expiration date and amount due<br/>"
                                 "4. Add a new member<br/>"
                                 "5. Delete a member<br/>"
                                 "6. Create a purchase<br/>"
                                 "7. Reports<br/>"
                                 "8. Quit<br/><br/>"
                                 "Please click on the radio button options below:<br/>");
        html_qstr_default.append("</span>");
        ui->textBrowser_MembersEntry->setHtml(html_qstr_default);
        // Clear user entry
        ui->lineEdit_MembersEntry->clear();
        // Setting user lineEdit
        ui->label_MembersEntry->setVisible(false);
        ui->lineEdit_MembersEntry->setVisible(false);
        ui->lineEdit_MembersEntry->setEnabled(false);
        // Setting pushButtons for submit and clear
        ui->pushButton_Enter->setVisible(false);
        ui->pushButton_Enter->setEnabled(false);
        ui->pushButton_Clear->setVisible(false);
        ui->pushButton_Clear->setEnabled(false);
        // Setting users options and reports
        ui->groupBox_Options->setVisible(true);
        ui->groupBox_Options->setEnabled(true);
    }
    else
    {
        // Display users error
        QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
        html_qstr_default.append("Sorry, no matching name or id."
                                 "<br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                                 "Please try again:");
        html_qstr_default.append("</span>");
        ui->textBrowser_MembersEntry->setHtml(html_qstr_default);
        // Clear user entry
        ui->lineEdit_MembersEntry->clear();
    }
}

// Members ID Clicked
bool WholesaleClubMembers::on_radioButton_ID_clicked()
{
    // Setting name and id
    ui->groupBox_Name_ID->setVisible(false);
    ui->groupBox_Name_ID->setEnabled(false);
    // Setting user lineEdit
    ui->label_MembersEntry->setVisible(true);
    ui->lineEdit_MembersEntry->setVisible(true);
    ui->lineEdit_MembersEntry->setEnabled(true);
    ui->lineEdit_MembersEntry->setPlaceholderText("Enter your ID #: ");
    // Setting pushButtons for submit and clear to enabled
    ui->pushButton_Enter->setVisible(true);
    ui->pushButton_Enter->setEnabled(true);
    ui->pushButton_Clear->setVisible(true);
    ui->pushButton_Clear->setEnabled(true);
    return ui->radioButton_ID->isChecked();
}

// Members Name Clicked
bool WholesaleClubMembers::on_radioButton_name_clicked()
{
    // Setting name and id
    ui->groupBox_Name_ID->setVisible(false);
    ui->groupBox_Name_ID->setEnabled(false);
    // Setting user lineEdit
    ui->label_MembersEntry->setVisible(true);
    ui->lineEdit_MembersEntry->setVisible(true);
    ui->lineEdit_MembersEntry->setEnabled(true);
    ui->lineEdit_MembersEntry->setPlaceholderText("Enter your Name: ");
    // Setting pushButtons for submit and clear to enabled
    ui->pushButton_Enter->setVisible(true);
    ui->pushButton_Enter->setEnabled(true);
    ui->pushButton_Clear->setVisible(true);
    ui->pushButton_Clear->setEnabled(true);
    return ui->radioButton_name->isChecked();
}

// Members Entry; Clicked Enter
bool WholesaleClubMembers::on_pushButton_Enter_clicked()
{
    on_lineEdit_MembersEntry_returnPressed();
    return ui->pushButton_Enter->isChecked();
}

// Members Entry; Clicked Clear
bool WholesaleClubMembers::on_pushButton_Clear_clicked()
{
    // Clear user entry
    ui->lineEdit_MembersEntry->clear();
    return ui->pushButton_Clear->isChecked();
}

// Members Entry; Clicked Yes
bool WholesaleClubMembers::on_pushButton_Yes_clicked()
{
    // Display Greetings
    QString html_qstr_Options_8 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_8.append("Thank you for shopping by!<br/>We hope to see you again!");
    html_qstr_Options_8.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_8);
    // Setting Yes and No
    ui->pushButton_Yes->setVisible(false);
    ui->pushButton_Yes->setEnabled(false);
    ui->pushButton_No->setVisible(false);
    ui->pushButton_No->setEnabled(false);
    // Settings display TextBrowser
    ui->label_DisplayReports->setVisible(true);
    ui->textBrowser_DisplayReports->setVisible(false);
    return ui->pushButton_Yes->isChecked();
}

// Members Entry; Clicked No
bool WholesaleClubMembers::on_pushButton_No_clicked()
{
    // Setting Yes and No
    ui->pushButton_Yes->setVisible(false);
    ui->pushButton_Yes->setEnabled(false);
    ui->pushButton_No->setVisible(false);
    ui->pushButton_No->setEnabled(false);
    // Settings display TextBrowser
    ui->label_DisplayReports->setVisible(true);
    ui->textBrowser_DisplayReports->setVisible(false);
    // Display Options
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("Welcome back to WholeSaleClub, ");
    html_qstr_default.append(ui->lineEdit_MembersEntry->text());
    html_qstr_default.append("! Glad to see you today.<br/>How can we assist you today?<br/>"
                             "Please choose from these options:<br/>"
                             "1. Totol purchases for this month<br/>"
                             "2. Item's quantity and purchases<br/>"
                             "3. Expiration date and amount due<br/>"
                             "4. Add a new member<br/>"
                             "5. Delete a member<br/>"
                             "6. Create a purchase<br/>"
                             "7. Reports<br/>"
                             "8. Quit<br/><br/>"
                             "Please click on the radio button options below:<br/>");
    html_qstr_default.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_default);
    // Setting users options
    ui->groupBox_Options->setVisible(true);
    ui->groupBox_Options->setEnabled(true);
    // Setting users reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    return ui->pushButton_No->isChecked();
}


// Members Entry; RadioButton Options 1
bool WholesaleClubMembers::on_radioButton_Options_1_clicked()
{
    // Display option 1
    QString html_qstr_Options_1 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_1.append("total");
    html_qstr_Options_1.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_1);
    return ui->radioButton_Options_1->isChecked();
}
// Members Entry; RadioButton Options 2
bool WholesaleClubMembers::on_radioButton_Options_2_clicked()
{
    // Display option 2
    QString html_qstr_Options_2 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_2.append("search");
    html_qstr_Options_2.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_2);
    return ui->radioButton_Options_2->isChecked();
}
// Members Entry; RadioButton Options 3
bool WholesaleClubMembers::on_radioButton_Options_3_clicked()
{
    // Display option 3
    QString html_qstr_Options_3 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_3.append("date");
    html_qstr_Options_3.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_3);
    return ui->radioButton_Options_3->isChecked();
}
// Members Entry; RadioButton Options 4
bool WholesaleClubMembers::on_radioButton_Options_4_clicked()
{
    // Display option 4
    QString html_qstr_Options_4 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_4.append("Add");
    html_qstr_Options_4.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_4);
    return ui->radioButton_Options_4->isChecked();
}
// Members Entry; RadioButton Options 5
bool WholesaleClubMembers::on_radioButton_Options_5_clicked()
{
    // Display option 5
    QString html_qstr_Options_5 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_5.append("Delete");
    html_qstr_Options_5.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_5);
    return ui->radioButton_Options_5->isChecked();
}
// Members Entry; RadioButton Options 6
bool WholesaleClubMembers::on_radioButton_Options_6_clicked()
{
    // Display option 6
    QString html_qstr_Options_6 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_6.append("Create purchases");
    html_qstr_Options_6.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_6);
    return ui->radioButton_Options_6->isChecked();
}
// Members Entry; RadioButton Options 7
bool WholesaleClubMembers::on_radioButton_Options_7_clicked()
{
    // Display option 7
    QString html_qstr_Options_7 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_7.append("Show Reports");
    html_qstr_Options_7.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_7);
    // Setting reports
    ui->groupBox_Reports->setVisible(true);
    ui->groupBox_Reports->setEnabled(true);
    return ui->radioButton_Options_7->isChecked();
}
// Members Entry; RadioButton Options 8
bool WholesaleClubMembers::on_radioButton_Options_8_clicked()
{
    // Display option 8
    QString html_qstr_Options_8 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_8.append("Are you sure you want to quit?");
    html_qstr_Options_8.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_8);
    // Setting reports
    ui->groupBox_Options->setVisible(false);
    ui->groupBox_Options->setEnabled(false);
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // Setting yes & no
    ui->pushButton_Yes->setVisible(true);
    ui->pushButton_Yes->setEnabled(true);
    ui->pushButton_No->setVisible(true);
    ui->pushButton_No->setEnabled(true);
    // Settings display TextBrowser
    ui->label_DisplayReports->setVisible(true);
    ui->textBrowser_DisplayReports->setVisible(false);
    return ui->radioButton_Options_8->isChecked();
}

// Members Entry; RadioButton Reports 1
bool WholesaleClubMembers::on_radioButton_Reports_1_clicked()
{
    // Setting Display TextBrowser
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    // Display reports 1
    QString html_qstr_Reports_1 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Reports_1.append("Print any day");
    html_qstr_Reports_1.append("</span>");
    ui->textBrowser_DisplayReports->setHtml(html_qstr_Reports_1);
    return ui->radioButton_Reports_1->isChecked();
}
// Members Entry; RadioButton Reports 2
bool WholesaleClubMembers::on_radioButton_Reports_2_clicked()
{
    // Setting Display TextBrowser
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    // Display reports 2
    QString html_qstr_Reports_2 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Reports_2.append("Print total");
    html_qstr_Reports_2.append("</span>");
    ui->textBrowser_DisplayReports->setHtml(html_qstr_Reports_2);
    return ui->radioButton_Reports_2->isChecked();
}
// Members Entry; RadioButton Reports 3
bool WholesaleClubMembers::on_radioButton_Reports_3_clicked()
{
    // Setting Display TextBrowser
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    // Display reports 3
    QString html_qstr_Reports_3 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Reports_3.append("Print sorted quantity");
    html_qstr_Reports_3.append("</span>");
    ui->textBrowser_DisplayReports->setHtml(html_qstr_Reports_3);
    return ui->radioButton_Reports_3->isChecked();
}
// Members Entry; RadioButton Reports 4
bool WholesaleClubMembers::on_radioButton_Reports_4_clicked()
{
    // Setting Display TextBrowser
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    // Display reports 4
    QString html_qstr_Reports_4 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Reports_4.append("Rebate sorted");
    html_qstr_Reports_4.append("</span>");
    ui->textBrowser_DisplayReports->setHtml(html_qstr_Reports_4);
    return ui->radioButton_Reports_2->isChecked();
}
// Members Entry; RadioButton Reports 5
bool WholesaleClubMembers::on_radioButton_Reports_5_clicked()
{
    // Setting Display TextBrowser
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    // Display reports 5
    QString html_qstr_Reports_5 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Reports_5.append("Amount due");
    html_qstr_Reports_5.append("</span>");
    ui->textBrowser_DisplayReports->setHtml(html_qstr_Reports_5);
    return ui->radioButton_Reports_1->isChecked();
}

