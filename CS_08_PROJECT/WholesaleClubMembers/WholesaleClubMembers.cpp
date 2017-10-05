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
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("Welcome to Wholesale Club!<br/><br/><br/><br/>");
    html_qstr_default.append("</span>");
    html_qstr_default.append("<span style=\"font-size:18pt;font-weight:600;color:#ff0000;\">");
    html_qstr_default.append("<br/><br/><br/><br/><br/>"
                             "Please select either your name or ID to enter in:");
    html_qstr_default.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_default);

    // DEFAULT IMAGE Display TextBrowser
    QPixmap warehouse_logo("/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/"
                           "build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug/"
                           "warehouselogo.png");
    ui->label_WarehouseLogo->setPixmap(warehouse_logo);

    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_WarehouseLogo->setVisible(true);

    // Name or ID groupbox
    ui->groupBox_Name_ID->setVisible(true);
    ui->groupBox_Name_ID->setEnabled(true);

    // Entry Info groupbox
    ui->groupBox_EntryInfo->setVisible(false);
    ui->groupBox_EntryInfo->setEnabled(false);

    // Members options
    ui->groupBox_Options->setVisible(false);
    ui->groupBox_Options->setEnabled(false);

    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);

    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);


    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);

    get_wareHouseShoppers();
}

WholesaleClubMembers::~WholesaleClubMembers()
{
    delete ui;
}

// tester
void WholesaleClubMembers::on_pushButton_clicked()
{

}

// warehouseshoppers.txt
void WholesaleClubMembers::get_wareHouseShoppers()
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

// Name Clicked
bool WholesaleClubMembers::on_radioButton_Name_clicked()
{
    // DEFAULT GREETINGS Member Entry TextBrowser
    QString html_qstr_nameEntry = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_nameEntry.append("Welcome to Wholesale Club!<br/><br/><br/><br/>");
    html_qstr_nameEntry.append("</span>");
    html_qstr_nameEntry.append("<span style=\"font-size:18pt;font-weight:600;color:#ff0000;\">");
    html_qstr_nameEntry.append("<br/><br/><br/><br/><br/><br/>"
                             "Enter your name below:");
    html_qstr_nameEntry.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_nameEntry);

    // Name or ID groupbox
    ui->groupBox_Name_ID->setVisible(false);
    ui->groupBox_Name_ID->setEnabled(false);

    // Entry Info groupbox
    ui->groupBox_EntryInfo->setVisible(true);
    ui->groupBox_EntryInfo->setEnabled(true);

    // lineEdit, pushButton for enter and clear
    ui->lineEdit_EntryInfo->setVisible(true);
    ui->lineEdit_EntryInfo->setEnabled(true);
    ui->pushButton_EnterInfo->setVisible(true);
    ui->pushButton_EnterInfo->setEnabled(true);
    ui->pushButton_ClearInfo->setVisible(true);
    ui->pushButton_ClearInfo->setEnabled(true);

    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);

    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);

    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);

    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);

    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);

    // Members options
    ui->groupBox_Options->setVisible(false);
    ui->groupBox_Options->setEnabled(false);

    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);

    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);

    // placeholder "name"
    ui->lineEdit_EntryInfo->setPlaceholderText("Enter your name: ");

    return ui->radioButton_Name->isChecked();
}

// ID Clicked
bool WholesaleClubMembers::on_radioButton_ID_clicked()
{
    QString html_qstr_idEntry = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_idEntry.append("Welcome to Wholesale Club!<br/><br/><br/><br/>");
    html_qstr_idEntry.append("</span>");
    html_qstr_idEntry.append("<span style=\"font-size:18pt;font-weight:600;color:#ff0000;\">");
    html_qstr_idEntry.append("<br/><br/><br/><br/><br/><br/>"
                             "Enter your id below:");
    html_qstr_idEntry.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_idEntry);

    // Name or ID groupbox
    ui->groupBox_Name_ID->setVisible(false);
    ui->groupBox_Name_ID->setEnabled(false);
    // Entry Info groupbox
    ui->groupBox_EntryInfo->setVisible(true);
    ui->groupBox_EntryInfo->setEnabled(true);
    // lineEdit, pushButton for enter and clear
    ui->lineEdit_EntryInfo->setVisible(true);
    ui->lineEdit_EntryInfo->setEnabled(true);
    ui->pushButton_EnterInfo->setVisible(true);
    ui->pushButton_EnterInfo->setEnabled(true);
    ui->pushButton_ClearInfo->setVisible(true);
    ui->pushButton_ClearInfo->setEnabled(true);

    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);

    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);

    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);

    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);

    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);

    // Members options
    ui->groupBox_Options->setVisible(false);
    ui->groupBox_Options->setEnabled(false);

    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);

    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);

    // placeholder "id"
    ui->lineEdit_EntryInfo->setPlaceholderText("Enter your ID: ");

    return ui->radioButton_ID->isChecked();
}

// Info PressedEnter
void WholesaleClubMembers::on_lineEdit_EntryInfo_returnPressed()
{
    if(members_name->find_member(ui->lineEdit_EntryInfo->text().toStdString()) ||
       members_id->find_member(ui->lineEdit_EntryInfo->text().toULongLong()))
    {
        // Display users options
        QString html_qstr_options = "<span style=\"font-size:14pt;font-weight:600;color:#17DA5E;\">";
        html_qstr_options.append("Welcome back to WholeSaleClub, ");
        html_qstr_options.append(ui->lineEdit_EntryInfo->text());
        html_qstr_options.append("! Glad to see you today.<br/>How can we assist you today?<br/>"
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
        html_qstr_options.append("</span>");
        ui->textBrowser_MembersEntry->setHtml(html_qstr_options);

        // Name or ID groupbox
        ui->groupBox_Name_ID->setVisible(false);
        ui->groupBox_Name_ID->setEnabled(false);
        // Entry Info groupbox
        ui->groupBox_EntryInfo->setVisible(false);
        ui->groupBox_EntryInfo->setEnabled(false);
        // lineEdit, pushButton for enter and clear
        ui->lineEdit_EntryInfo->setVisible(false);
        ui->lineEdit_EntryInfo->setEnabled(false);
        ui->pushButton_EnterInfo->setVisible(false);
        ui->pushButton_EnterInfo->setEnabled(false);
        ui->pushButton_ClearInfo->setVisible(false);
        ui->pushButton_ClearInfo->setEnabled(false);

        // Option 2 groupbox
        ui->groupBox_EntryInfo_Option_2->setVisible(false);
        ui->groupBox_EntryInfo_Option_2->setEnabled(false);

        // Option 3 groupbox
        ui->groupBox_EntryInfo_Option_3->setVisible(false);
        ui->groupBox_EntryInfo_Option_3->setEnabled(false);

        // Option 4 groupbox
        ui->groupBox_EntryInfo_Option_4->setVisible(false);
        ui->groupBox_EntryInfo_Option_4->setEnabled(false);

        // Option 5 groupbox
        ui->groupBox_EntryInfo_Option_5->setVisible(false);
        ui->groupBox_EntryInfo_Option_5->setEnabled(false);

        // Option 6 groupbox
        ui->groupBox_EntryInfo_Option_6->setVisible(false);
        ui->groupBox_EntryInfo_Option_6->setEnabled(false);

        // Members options
        ui->groupBox_Options->setVisible(true);
        ui->groupBox_Options->setEnabled(true);

        // Members reports
        ui->groupBox_Reports->setVisible(false);
        ui->groupBox_Reports->setEnabled(false);

        // yes & no
        ui->groupBox_Yes_No->setVisible(false);
        ui->groupBox_Yes_No->setEnabled(false);

        // Clear user entry
        ui->lineEdit_EntryInfo->clear();
    }
    else
    {
        // Display users error
        QString html_qstr_error = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
        html_qstr_error.append("Sorry, no matching name or id."
                                 "<br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                                 "Please try again:");
        html_qstr_error.append("</span>");
        ui->textBrowser_MembersEntry->setHtml(html_qstr_error);
        // Clear user entry
        ui->lineEdit_EntryInfo->clear();
    }
    ui->lineEdit_EntryInfo->clear();
}

// Info ClickedEnter
bool WholesaleClubMembers::on_pushButton_EnterInfo_clicked()
{
    on_lineEdit_EntryInfo_returnPressed();
    return ui->pushButton_EnterInfo->isChecked();
}

// Info ClickedClear
bool WholesaleClubMembers::on_pushButton_ClearInfo_clicked()
{
    ui->lineEdit_EntryInfo->clear();
    return ui->pushButton_ClearInfo->isChecked();
}

// Clicked Yes
bool WholesaleClubMembers::on_pushButton_Yes_clicked()
{
    // Display Greetings
    QString html_qstr_quit = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_quit.append("Thank you for shopping by!<br/>We hope to see you again!");
    html_qstr_quit.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_quit);
    // Name or ID groupbox
    ui->groupBox_Name_ID->setVisible(false);
    ui->groupBox_Name_ID->setEnabled(false);
    // Entry Info groupbox
    ui->groupBox_EntryInfo->setVisible(false);
    ui->groupBox_EntryInfo->setEnabled(false);
    // Members options
    ui->groupBox_Options->setVisible(false);
    ui->groupBox_Options->setEnabled(false);
    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);
    return ui->pushButton_Yes->isChecked();
}

// Clicked No
bool WholesaleClubMembers::on_pushButton_No_clicked()
{
    // Display Options
     QString html_qstr_back = "<span style=\"font-size:15pt;font-weight:600;color:#17DA5E;\">";
     html_qstr_back.append("Welcome back to WholeSaleClub, ");
     html_qstr_back.append(ui->lineEdit_EntryInfo->text());
     html_qstr_back.append("! Glad to see you today.<br/>How can we assist you today?<br/>"
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
     html_qstr_back.append("</span>");
     ui->textBrowser_MembersEntry->setHtml(html_qstr_back);
     // Name or ID groupbox
     ui->groupBox_Name_ID->setVisible(false);
     ui->groupBox_Name_ID->setEnabled(false);
     // Entry Info groupbox
     ui->groupBox_EntryInfo->setVisible(false);
     ui->groupBox_EntryInfo->setEnabled(false);
     // Members options
     ui->groupBox_Options->setVisible(true);
     ui->groupBox_Options->setEnabled(true);
     // Members reports
     ui->groupBox_Reports->setVisible(false);
     ui->groupBox_Reports->setEnabled(false);
     // yes & no
     ui->groupBox_Yes_No->setVisible(false);
     ui->groupBox_Yes_No->setEnabled(false);
     // Option 2 groupbox
     ui->groupBox_EntryInfo_Option_2->setVisible(false);
     ui->groupBox_EntryInfo_Option_2->setEnabled(false);
     // Option 3 groupbox
     ui->groupBox_EntryInfo_Option_3->setVisible(false);
     ui->groupBox_EntryInfo_Option_3->setEnabled(false);
     // Option 4 groupbox
     ui->groupBox_EntryInfo_Option_4->setVisible(false);
     ui->groupBox_EntryInfo_Option_4->setEnabled(false);
     // Option 5 groupbox
     ui->groupBox_EntryInfo_Option_5->setVisible(false);
     ui->groupBox_EntryInfo_Option_5->setEnabled(false);
     // Option 6 groupbox
     ui->groupBox_EntryInfo_Option_6->setVisible(false);
     ui->groupBox_EntryInfo_Option_6->setEnabled(false);

    return ui->pushButton_No->isChecked();
}


// Options 1 show total purchases
bool WholesaleClubMembers::on_radioButton_Options_1_clicked()
{
    // Display option 1
    QString html_qstr_Options_1 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_1.append("total");
    html_qstr_Options_1.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_1);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);
    // Members options
    ui->groupBox_Options->setVisible(true);
    ui->groupBox_Options->setEnabled(true);
    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);

    return ui->radioButton_Options_1->isChecked();
}
// Options 2 search item by name
bool WholesaleClubMembers::on_radioButton_Options_2_clicked()
{
    // Display option 2
    QString html_qstr_Options_2 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_2.append("search");
    html_qstr_Options_2.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_2);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(true);
    ui->groupBox_EntryInfo_Option_2->setEnabled(true);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);
    // Members options
    ui->groupBox_Options->setVisible(true);
    ui->groupBox_Options->setEnabled(true);
    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);
    // placeholder
    ui->lineEdit_EntryInfo_Option_2->setPlaceholderText("Item name: ");
    return ui->radioButton_Options_2->isChecked();
}
// Options 3 show exp date
bool WholesaleClubMembers::on_radioButton_Options_3_clicked()
{
    // Display option 3
    QString html_qstr_Options_3 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_3.append("date");
    html_qstr_Options_3.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_3);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(true);
    ui->groupBox_EntryInfo_Option_3->setEnabled(true);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);
    // Members options
    ui->groupBox_Options->setVisible(true);
    ui->groupBox_Options->setEnabled(true);
    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);
    // placeholder
    ui->lineEdit_EntryInfo_Option_3->setPlaceholderText("Date: ");
    return ui->radioButton_Options_3->isChecked();
}
// Options 4 add member
bool WholesaleClubMembers::on_radioButton_Options_4_clicked()
{
    // Display option 4
    QString html_qstr_Options_4 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_4.append("Add");
    html_qstr_Options_4.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_4);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(true);
    ui->groupBox_EntryInfo_Option_4->setEnabled(true);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);
    // Members options
    ui->groupBox_Options->setVisible(true);
    ui->groupBox_Options->setEnabled(true);
    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);
    // placeholder
    ui->lineEdit_EntryInfo_Option_4->setPlaceholderText("Enter name to add: ");
    return ui->radioButton_Options_4->isChecked();
}
// Options 5 delete member
bool WholesaleClubMembers::on_radioButton_Options_5_clicked()
{
    // Display option 5
    QString html_qstr_Options_5 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_5.append("Delete");
    html_qstr_Options_5.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_5);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(true);
    ui->groupBox_EntryInfo_Option_5->setEnabled(true);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);
    // Members options
    ui->groupBox_Options->setVisible(true);
    ui->groupBox_Options->setEnabled(true);
    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);
    // placeholder
    ui->lineEdit_EntryInfo_Option_5->setPlaceholderText("Enter name to delete: ");
    return ui->radioButton_Options_5->isChecked();
}
// Options 6 create purchases
bool WholesaleClubMembers::on_radioButton_Options_6_clicked()
{
    // Display option 6
    QString html_qstr_Options_6 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_6.append("Create purchases");
    html_qstr_Options_6.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_6);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(true);
    ui->groupBox_EntryInfo_Option_6->setEnabled(true);
    // Members options
    ui->groupBox_Options->setVisible(true);
    ui->groupBox_Options->setEnabled(true);
    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);
    // placeholder
    ui->lineEdit_EntryInfo_Option_6->setPlaceholderText("Purchases: ");
    return ui->radioButton_Options_6->isChecked();
}
// Options 7 show reports
bool WholesaleClubMembers::on_radioButton_Options_7_clicked()
{
    // Display option 7
    QString html_qstr_Options_7 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_7.append("Show reports");
    html_qstr_Options_7.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_7);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);
    // Members options
    ui->groupBox_Options->setVisible(true);
    ui->groupBox_Options->setEnabled(true);
    // Members reports
    ui->groupBox_Reports->setVisible(true);
    ui->groupBox_Reports->setEnabled(true);
    // yes & no
    ui->groupBox_Yes_No->setVisible(false);
    ui->groupBox_Yes_No->setEnabled(false);

    // placeholder
    return ui->radioButton_Options_7->isChecked();
}
// Options 8 quit
bool WholesaleClubMembers::on_radioButton_Options_8_clicked()
{
    // Display option 8
    QString html_qstr_Options_8 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_8.append("Are you sure you want to quit?");
    html_qstr_Options_8.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_8);
    // Option 2 groupbox
    ui->groupBox_EntryInfo_Option_2->setVisible(false);
    ui->groupBox_EntryInfo_Option_2->setEnabled(false);
    // Option 3 groupbox
    ui->groupBox_EntryInfo_Option_3->setVisible(false);
    ui->groupBox_EntryInfo_Option_3->setEnabled(false);
    // Option 4 groupbox
    ui->groupBox_EntryInfo_Option_4->setVisible(false);
    ui->groupBox_EntryInfo_Option_4->setEnabled(false);
    // Option 5 groupbox
    ui->groupBox_EntryInfo_Option_5->setVisible(false);
    ui->groupBox_EntryInfo_Option_5->setEnabled(false);
    // Option 6 groupbox
    ui->groupBox_EntryInfo_Option_6->setVisible(false);
    ui->groupBox_EntryInfo_Option_6->setEnabled(false);
    // Members options
    ui->groupBox_Options->setVisible(false);
    ui->groupBox_Options->setEnabled(false);
    // Members reports
    ui->groupBox_Reports->setVisible(false);
    ui->groupBox_Reports->setEnabled(false);
    // yes & no
    ui->groupBox_Yes_No->setVisible(true);
    ui->groupBox_Yes_No->setEnabled(true);
    return ui->radioButton_Options_8->isChecked();
}

// Reports 1 print any day
bool WholesaleClubMembers::on_radioButton_Reports_1_clicked()
{

    return ui->radioButton_Reports_1->isChecked();
}
// Reports 2 print total
bool WholesaleClubMembers::on_radioButton_Reports_2_clicked()
{
    return ui->radioButton_Reports_2->isChecked();
}
// Reports 3 quantity sorted
bool WholesaleClubMembers::on_radioButton_Reports_3_clicked()
{
    return ui->radioButton_Reports_3->isChecked();
}
// Reports 4 rebated sorted
bool WholesaleClubMembers::on_radioButton_Reports_4_clicked()
{
    return ui->radioButton_Reports_4->isChecked();
}
// Reports 5 amount due
bool WholesaleClubMembers::on_radioButton_Reports_5_clicked()
{
    return ui->radioButton_Reports_5->isChecked();
}

