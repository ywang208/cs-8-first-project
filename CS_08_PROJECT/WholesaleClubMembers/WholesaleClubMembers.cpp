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
    total_amount = new MembersList<double>;
    rebate_amount = new MembersList<double>;
    // Basic input variables day(n).txt
    purchase_of_date = new MembersList<std::string>;
    purchase_members_id = new MembersList<size_t>;
    purchase_item_name = new MembersList<std::string>;
    item_price_quantity = new MembersList<std::string>;
    items_price = new MembersList<double>;
    items_quanty = new MembersList<size_t>;
    // Settings
    default_html();
    logo_html();
    default_settings();
    get_warehouseshoppers();
    get_dayspurcahsed();
}

WholesaleClubMembers::~WholesaleClubMembers()
{
    delete ui;
}
void WholesaleClubMembers::default_html()
{
    QString html_qstr_default = "<span style=\"font-size:22pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("Welcome to Wholesale Club!<br/><br/><br/><br/>");
    html_qstr_default.append("</span>");
    html_qstr_default.append("<span style=\"font-size:18pt;font-weight:600;color:#ff0000;\">");
    html_qstr_default.append("<br/><br/><br/><br/><br/><br/<br/><br/><br/>"
                             "Please select either your name or ID to enter in:");
    html_qstr_default.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_default);
}
void WholesaleClubMembers::logo_html()
{
    QPixmap warehouse_logo("/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/"
                           "build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug/"
                           "warehouselogo.png");
    ui->label_DisplayReports->setPixmap(warehouse_logo);
}
void WholesaleClubMembers::name_html()
{
    QString html_qstr_nameEntry = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_nameEntry.append("Welcome to Wholesale back, ");
    html_qstr_nameEntry.append("<br/><br/><br/><br/>");
    html_qstr_nameEntry.append("</span>");
    html_qstr_nameEntry.append("<span style=\"font-size:18pt;font-weight:600;color:#ff0000;\">");
    html_qstr_nameEntry.append("<br/><br/><br/><br/><br/>"
                               "Enter your name below:");
    html_qstr_nameEntry.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_nameEntry);
}
void WholesaleClubMembers::id_html()
{
    QString html_qstr_nameEntry = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_nameEntry.append("Welcome to Wholesale Club!");
    html_qstr_nameEntry.append("<br/><br/><br/><br/>");
    html_qstr_nameEntry.append("</span>");
    html_qstr_nameEntry.append("<span style=\"font-size:18pt;font-weight:600;color:#ff0000;\">");
    html_qstr_nameEntry.append("<br/><br/><br/><br/><br/>"
                               "Enter your ID # below:");
    html_qstr_nameEntry.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_nameEntry);
}
void WholesaleClubMembers::invalid_html()
{
    QString html_qstr_error = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_error.append("<br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                           "Please try again:");
    html_qstr_error.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_error);
    ui->lineEdit_MembersEntry->clear();
}
void WholesaleClubMembers::options_html()
{
    QString html_qstr_options = "<span style=\"font-size:15pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_options.append("Welcome back to WholeSaleClub,<br/>");
    if(on_radioButton_ID_clicked())
    {
        ui->groupBox_MembersEntryInfo->setVisible(false);
        ui->groupBox_MembersEntryInfo->setEnabled(false);
        html_qstr_options.append(members_name->return_member(members_id->find_position_member(ui->lineEdit_MembersEntry->text().toULongLong()))->data.c_str());
    }
    else if(on_radioButton_Name_clicked())
    {
        ui->groupBox_MembersEntryInfo->setVisible(false);
        ui->groupBox_MembersEntryInfo->setEnabled(false);
        html_qstr_options.append(members_name->return_member(members_name->find_position_member(ui->lineEdit_MembersEntry->text().toStdString()))->data.c_str());
    }
    else
        ui->lineEdit_MembersEntry->setText("Try again.");
    html_qstr_options.append("! Glad to see you today.<br/>How can we assist you?<br/>"
                             "Please choose from these options:<br/>"
                             "1. Totol purchases for this month<br/>"
                             "2. Item's quantity and purchases<br/>"
                             "3. Expiration date and amount due<br/>"
                             "4. Add a new member<br/>"
                             "5. Delete a member<br/>"
                             "6. Create a purchase<br/>"
                             "7. Reports<br/>"
                             "8. Quit<br/><br/><br/>"
                             "Please click on the radio button options below:<br/>");
    html_qstr_options.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_options);

}
void WholesaleClubMembers::default_settings()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_DisplayReports->setVisible(true);
    // Entry Info groupbox
    ui->groupBox_MembersEntry->setVisible(true);
    ui->groupBox_MembersEntry->setEnabled(true);
    // Entry Info lineEdit
    ui->groupBox_MembersEntryInfo->setVisible(false);
    ui->groupBox_MembersEntryInfo->setEnabled(false);
    // Name or ID groupbox
    ui->groupBox_NameID->setVisible(true);
    ui->groupBox_NameID->setEnabled(true);
    // yes & no
    ui->groupBox_YesNo->setVisible(false);
    ui->groupBox_YesNo->setEnabled(false);
    // options default
    options_default_settings();
    // Members reports
    ui->groupBox_MembersReports->setVisible(false);
    ui->groupBox_MembersReports->setEnabled(false);
}
void WholesaleClubMembers::options_default_settings()
{
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    ui->groupBox_MembersOption_2->setVisible(false);
    ui->groupBox_MembersOption_2->setEnabled(false);
    ui->groupBox_MembersOption_3->setVisible(false);
    ui->groupBox_MembersOption_3->setEnabled(false);
    ui->groupBox_MembersOption_4->setVisible(false);
    ui->groupBox_MembersOption_4->setEnabled(false);
    ui->groupBox_MembersOption_5->setVisible(false);
    ui->groupBox_MembersOption_5->setEnabled(false);
    ui->groupBox_MembersOption_6->setVisible(false);
    ui->groupBox_MembersOption_6->setEnabled(false);
    ui->groupBox_Option_Choice->setVisible(false);
    ui->groupBox_Option_Choice->setEnabled(false);
}
void WholesaleClubMembers::member_entry_settings()
{
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    ui->groupBox_MembersEntryInfo->setVisible(false);
    ui->groupBox_MembersEntryInfo->setEnabled(false);
}
void WholesaleClubMembers::member_entry_settings_vice()
{
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    ui->groupBox_MembersEntryInfo->setVisible(true);
    ui->groupBox_MembersEntryInfo->setEnabled(true);
}
void WholesaleClubMembers::push_button_back_settins()
{
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    ui->groupBox_MembersReports->setVisible(false);
    ui->groupBox_MembersReports->setEnabled(false);
}
void WholesaleClubMembers::get_warehouseshoppers()
{
    QString director_path = "/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/"
                            "build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug/";
    QString text_file = "warehouseshoppers.txt";
    director_path.append(text_file);
    QFile file(director_path);

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
            QStr_line = in.readLine();
            members_id->push_back(QStr_line.toULongLong());
            QStr_line = in.readLine();
            members_type->push_back(QStr_line.toStdString());
            QStr_line = in.readLine();
            expiration_date->push_back(QStr_line.toStdString());
        }
    }
    file.close();

}
void WholesaleClubMembers::get_dayspurcahsed()
{
    QString director_path = "/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/"
                            "build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug/";
    QString days = "day2.txt";
    director_path.append(days);
    qDebug() << "path: " << director_path << endl;
    QFile file(director_path);
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
            QStr_line = in.readLine();
            purchase_of_date->push_back(QStr_line.toStdString());
            QStr_line = in.readLine();
            purchase_members_id->push_back(QStr_line.toULongLong());
            QStr_line = in.readLine();
            purchase_item_name->push_back(QStr_line.toStdString());

            // reads price first
            in >> QStr_line;
            in.skipWhiteSpace();
            items_price->push_back(QStr_line.simplified().toDouble());

            // then reads quantity
            in >> QStr_line;
            in.skipWhiteSpace();
            items_quanty->push_back(QStr_line.simplified().toULongLong());
        }
    }
    file.close();
    ui->textBrowser_DisplayReports->setText(
                QString::fromStdString(
                    "Date:" + purchase_of_date->output_linkedlist() + '\n' +
                    "ID#: " + purchase_members_id->output_linkedlist() + '\n' +
                    "Item name: " + purchase_item_name->output_linkedlist() + '\n' +
                    "Item price and qty: " + item_price_quantity->output_linkedlist() + '\n' +
                    "only price: " + items_price->output_linkedlist() + '\n' +
                    "only qty: " + items_quanty->output_linkedlist() + '\n' +
                    "$: "));
}
// OUTPUT TEXT FILE ONTO A TEXT FILE NEW FUNCTION
void WholesaleClubMembers::output_txt_file()
{
    QFile director_path("/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/"
                        "build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug/mytext.txt");

    if(director_path.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&director_path);
        stream << members_name->output_linkedlist().c_str();
        director_path.close();
        qDebug() << " DONE\n";
    }
    else
    {
        ui->textBrowser_MembersEntry->setText("Error");
    }
}

void WholesaleClubMembers::Menu(const QString& choice)
{
    QString html_qstr_options = "<span style=\"font-size:15pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_options.append("Welcome back to WholeSaleClub, ");
    html_qstr_options.append("!<br/>Glad to see you today.<br/>How can we assist you today?<br/>"
                             "Please choose from these options:<br/>");
    html_qstr_options.append(choice);
    html_qstr_options.append("Please click on the radio button options below:<br/>");
    html_qstr_options.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_options);
}

// Select ID
bool WholesaleClubMembers::on_radioButton_ID_clicked()
{
    id_html();
    ui->groupBox_NameID->setVisible(false);
    ui->groupBox_NameID->setEnabled(false);
    ui->groupBox_MembersEntryInfo->setVisible(true);
    ui->groupBox_MembersEntryInfo->setEnabled(true);
    ui->lineEdit_MembersEntry->setPlaceholderText("ID #:");
    return ui->radioButton_ID->isChecked();
}
// Select Name
bool WholesaleClubMembers::on_radioButton_Name_clicked()
{
    name_html();
    ui->groupBox_NameID->setVisible(false);
    ui->groupBox_NameID->setEnabled(false);
    ui->groupBox_MembersEntryInfo->setVisible(true);
    ui->groupBox_MembersEntryInfo->setEnabled(true);
    ui->lineEdit_MembersEntry->setPlaceholderText("Name:");
    return ui->radioButton_Name->isChecked();
}
// Clicked enter
bool WholesaleClubMembers::on_pushButton_Enter_clicked()
{
    on_lineEdit_MembersEntry_returnPressed();
    return ui->pushButton_Enter->isChecked();
}
// Clicked clear
bool WholesaleClubMembers::on_pushButton_Clear_clicked()
{
    ui->lineEdit_MembersEntry->clear();
    return ui->pushButton_Clear->isChecked();
}
// clicked yes
bool WholesaleClubMembers::on_pushButton_Yes_clicked()
{
    ui->textBrowser_MembersEntry->setText("WOuld you like to upgrade to Preferred?");
    ui->groupBox_YesNo->setVisible(false);
    ui->groupBox_YesNo->setEnabled(false);
    return ui->pushButton_Yes->isChecked();
}
// clicked no
bool WholesaleClubMembers::on_pushButton_No_clicked()
{
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    ui->groupBox_YesNo->setVisible(false);
    ui->groupBox_YesNo->setEnabled(false);
    return ui->pushButton_Yes->isChecked();
}
// Validate user
void WholesaleClubMembers::valid_user_entry()
{
    if(on_radioButton_ID_clicked())
    {
        member_entry_settings();
        ui->textBrowser_MembersEntry->setText("ID!");
        if(members_id->find_member(ui->lineEdit_MembersEntry->text().toULongLong()))
            options_html();
        else
        {
            QString html_qstr_error = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
            html_qstr_error.append("Sorry, no matching ID #."
                                   "<br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                                   "Please try again:");
            html_qstr_error.append("</span>");
            ui->textBrowser_MembersEntry->setHtml(html_qstr_error);
            ui->lineEdit_MembersEntry->clear();
            member_entry_settings_vice();
        }
    }
    else if(on_radioButton_Name_clicked())
    {
        member_entry_settings();
        ui->textBrowser_MembersEntry->setText("NAME!");
        if(members_name->find_member(ui->lineEdit_MembersEntry->text().toStdString()))
            options_html();
        else
        {
            QString html_qstr_error = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
            html_qstr_error.append("Sorry, no matching name."
                                   "<br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                                   "Please try again:");
            html_qstr_error.append("</span>");
            ui->textBrowser_MembersEntry->setHtml(html_qstr_error);
            ui->lineEdit_MembersEntry->clear();
            member_entry_settings_vice();
        }
    }
    else
    {
        QString html_qstr_error = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
        html_qstr_error.append("Please select ID # or Name below:"
                               "<br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                               "Please try again:");
        html_qstr_error.append("</span>");
        ui->textBrowser_MembersEntry->setHtml(html_qstr_error);
        ui->lineEdit_MembersEntry->clear();
        ui->groupBox_MembersEntryInfo->setVisible(true);
        ui->groupBox_MembersEntryInfo->setEnabled(true);
    }
}
// Pressed enter
void WholesaleClubMembers::on_lineEdit_MembersEntry_returnPressed()
{
    valid_user_entry();
    ui->lineEdit_MembersEntry->clear();
}


// options 1
bool WholesaleClubMembers::on_radioButton_MembersOptions_1_clicked()
{
    // Display option 1
    QString html_qstr_Options_1 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_1.append("total");
    html_qstr_Options_1.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_1);
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    ui->textBrowser_MembersEntry->setText("Print all purchases for this month.");
    return ui->radioButton_MembersOptions_1->isChecked();
}
// option 2 enter item names
bool WholesaleClubMembers::on_radioButton_MembersOptions_2_clicked()
{
    // Display option 2
    QString html_qstr_Options_2 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_2.append("search");
    html_qstr_Options_2.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_2);
    ui->groupBox_MembersOption_2->setVisible(true);
    ui->groupBox_MembersOption_2->setEnabled(true);
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    return ui->radioButton_MembersOptions_2->isChecked();
}//Menu("#2 enter item names: ");
void WholesaleClubMembers::on_lineEdit_MembersOption_2_returnPressed()
{
    ui->textBrowser_MembersEntry->setText("Item: ");
    on_pushButton_Clear_MembersOption_2_clicked();
    ui->groupBox_MembersOption_2->setVisible(false);
    ui->groupBox_MembersOption_2->setEnabled(false);
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    Menu("#2 enter items");

}
bool WholesaleClubMembers::on_pushButton_Clear_MembersOption_2_clicked()
{
    ui->lineEdit_MembersOption_2->clear();
    return ui->pushButton_Clear_MembersOption_2->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Enter_MembersOption_2_clicked()
{
    on_pushButton_Clear_MembersOption_2_clicked();
    on_lineEdit_MembersOption_2_returnPressed();
    return ui->pushButton_Enter_MembersOption_2->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Back_MembersOption_2_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_DisplayReports->setVisible(true);
    push_button_back_settins();
    ui->groupBox_MembersOption_2->setVisible(false);
    ui->groupBox_MembersOption_2->setEnabled(false);
    return ui->pushButton_Back_MembersOption_2->isChecked();
}
// option 3 enter month to check exp date
bool WholesaleClubMembers::on_radioButton_MembersOptions_3_clicked()
{
    // Display option 3
    QString html_qstr_Options_3 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_3.append("date");
    html_qstr_Options_3.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_3);
    ui->groupBox_MembersOption_3->setVisible(true);
    ui->groupBox_MembersOption_3->setEnabled(true);
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    return ui->radioButton_MembersOptions_3->isChecked();
}
void WholesaleClubMembers::on_lineEdit_MembersOption_3_returnPressed()
{
    ui->textBrowser_MembersEntry->setText("Date: " + QString::fromStdString(expiration_date->output_linkedlist().c_str()));
    on_pushButton_Clear_MembersOption_3_clicked();
    ui->groupBox_MembersOption_3->setVisible(false);
    ui->groupBox_MembersOption_3->setEnabled(false);
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    Menu("#3 enter date");
}
bool WholesaleClubMembers::on_pushButton_Clear_MembersOption_3_clicked()
{
    ui->lineEdit_MembersOption_3->clear();
    return ui->pushButton_Clear_MembersOption_3->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Enter__MembersOption_3_clicked()
{
    on_lineEdit_MembersOption_3_returnPressed();
    on_pushButton_Clear_MembersOption_3_clicked();
    return ui->pushButton_Enter__MembersOption_3->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Back_MembersOption_3_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_DisplayReports->setVisible(true);
    push_button_back_settins();
    ui->groupBox_MembersOption_3->setVisible(false);
    ui->groupBox_MembersOption_3->setEnabled(false);
    return ui->pushButton_Back_MembersOption_3->isChecked();
}
// option 4 add member
bool WholesaleClubMembers::on_radioButton_MembersOptions_4_clicked()
{
    // Display option 3
    QString html_qstr_Options_3 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_3.append("date");
    html_qstr_Options_3.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_3);
    ui->groupBox_MembersOption_4->setVisible(true);
    ui->groupBox_MembersOption_4->setEnabled(true);
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    return ui->radioButton_MembersOptions_4->isChecked();
}
void WholesaleClubMembers::on_lineEdit_MembersOption_4_returnPressed()
{
    ui->textBrowser_MembersEntry->setText("Add members: " + QString::fromStdString(members_name->output_linkedlist().c_str()));
    on_pushButton_Clear_MembersOption_6_clicked();
    ui->groupBox_MembersOption_4->setVisible(false);
    ui->groupBox_MembersOption_4->setEnabled(false);
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    Menu("#4 add memner");
}
bool WholesaleClubMembers::on_pushButton_Clear_MembersOption_4_clicked()
{
    ui->lineEdit_MembersOption_4->clear();
    return ui->pushButton_Clear_MembersOption_4->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Enter_MembersOption_4_clicked()
{
    on_lineEdit_MembersOption_4_returnPressed();
    on_pushButton_Clear_MembersOption_4_clicked();
    return ui->pushButton_Enter_MembersOption_4->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Back_MembersOption_4_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_DisplayReports->setVisible(true);
    push_button_back_settins();
    ui->groupBox_MembersOption_4->setVisible(false);
    ui->groupBox_MembersOption_4->setEnabled(false);
    return ui->pushButton_Back_MembersOption_4->isChecked();
}
// option 5 delete member
bool WholesaleClubMembers::on_radioButton_MembersOptions_5_clicked()
{
    // Display option 5
    QString html_qstr_Options_5 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_5.append("Delete");
    html_qstr_Options_5.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_5);
    ui->groupBox_MembersOption_5->setVisible(true);
    ui->groupBox_MembersOption_5->setEnabled(true);
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    return ui->radioButton_MembersOptions_5->isChecked();
}
void WholesaleClubMembers::on_lineEdit_MembersOption_5_returnPressed()
{
    ui->textBrowser_MembersEntry->setText("Delete member: " + QString::fromStdString(members_name->output_linkedlist().c_str()));
    on_pushButton_Clear_MembersOption_5_clicked();
    ui->groupBox_MembersOption_5->setVisible(false);
    ui->groupBox_MembersOption_5->setEnabled(false);
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    Menu("Delete members");
}
bool WholesaleClubMembers::on_pushButton_Clear_MembersOption_5_clicked()
{
    ui->lineEdit_MembersOption_5->clear();
    return ui->pushButton_Clear_MembersOption_5->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Enter_MembersOption_5_clicked()
{
    on_lineEdit_MembersOption_5_returnPressed();
    on_pushButton_Clear_MembersOption_5_clicked();
    return ui->pushButton_Enter_MembersOption_5->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Back_MembersOption_5_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_DisplayReports->setVisible(true);
    push_button_back_settins();
    ui->groupBox_MembersOption_5->setVisible(false);
    ui->groupBox_MembersOption_5->setEnabled(false);
    return ui->pushButton_Back_MembersOption_5->isChecked();
}
// option 6 create purchase
bool WholesaleClubMembers::on_radioButton_MembersOptions_6_clicked()
{
    // Display option 6
    QString html_qstr_Options_6 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_6.append("Create purchases");
    html_qstr_Options_6.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_6);
    ui->groupBox_MembersOption_6->setVisible(true);
    ui->groupBox_MembersOption_6->setEnabled(true);
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    return ui->radioButton_MembersOptions_6->isChecked();
}
void WholesaleClubMembers::on_lineEdit_MembersOption_6_returnPressed()
{
    ui->textBrowser_MembersEntry->setText("Create purchase: " + QString::fromStdString(members_name->output_linkedlist().c_str()));
    on_pushButton_Clear_MembersOption_6_clicked();
    ui->groupBox_MembersOption_6->setVisible(false);
    ui->groupBox_MembersOption_6->setEnabled(false);
    ui->groupBox_MembersOptions->setVisible(true);
    ui->groupBox_MembersOptions->setEnabled(true);
    Menu("create purchases");
}
bool WholesaleClubMembers::on_pushButton_Clear_MembersOption_6_clicked()
{
    ui->lineEdit_MembersOption_6->clear();
    return ui->pushButton_Clear_MembersOption_6->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Enter_MembersOption_6_clicked()
{
    on_lineEdit_MembersOption_6_returnPressed();
    on_pushButton_Clear_MembersOption_6_clicked();
    return ui->pushButton_Enter_MembersOption_6->isChecked();
}
bool WholesaleClubMembers::on_pushButton_Back_MembersOption_6_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_DisplayReports->setVisible(true);
    push_button_back_settins();
    ui->groupBox_MembersOption_6->setVisible(false);
    ui->groupBox_MembersOption_6->setEnabled(false);
    return ui->pushButton_Back_MembersOption_6->isChecked();
}
// option 7 reports
bool WholesaleClubMembers::on_radioButton_MembersOptions_7_clicked()
{
    // Display option 7
    QString html_qstr_Options_7 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_7.append("Show reports");
    html_qstr_Options_7.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_7);
    // Members options
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    // Members reports
    ui->groupBox_MembersReports->setVisible(true);
    ui->groupBox_MembersReports->setEnabled(true);
    return ui->radioButton_MembersOptions_7->isChecked();
}
// option 8 options
bool WholesaleClubMembers::on_radioButton_MembersOptions_8_clicked()
{
    // Display option 8
    QString html_qstr_Options_7 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_7.append("Would you like to upgrade to preferred or downgrade to basic");
    html_qstr_Options_7.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_7);
    // Members options
    ui->groupBox_MembersOptions->setVisible(false);
    ui->groupBox_MembersOptions->setEnabled(false);
    // Members reports
    ui->groupBox_MembersReports->setVisible(false);
    ui->groupBox_MembersReports->setEnabled(false);
    // Option 7 groupbox
    ui->groupBox_Option_Choice->setVisible(true);
    ui->groupBox_Option_Choice->setEnabled(true);
    return ui->radioButton_MembersOptions_8->isChecked();
}
// option 9 quit
bool WholesaleClubMembers::on_radioButton_MembersOptions_9_clicked()
{
    // Display option 8
    QString html_qstr_Options_8 = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_Options_8.append("Are you sure you want to quit?");
    html_qstr_Options_8.append("</span>");
    ui->textBrowser_MembersEntry->setHtml(html_qstr_Options_8);
    options_default_settings();
    ui->groupBox_YesNo->setVisible(true);
    ui->groupBox_YesNo->setEnabled(true);
    return ui->radioButton_MembersOptions_9->isChecked();
}


// reports print any given day
bool WholesaleClubMembers::on_radioButton_MembersReports_1_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    return ui->radioButton_MembersReports_1->isChecked();
}
// reports total purchases
bool WholesaleClubMembers::on_radioButton_MembersReports_2_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);

    return ui->radioButton_MembersReports_2->isChecked();
}
// reports total qty sorted
bool WholesaleClubMembers::on_radioButton_MembersReports_3_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    return ui->radioButton_MembersReports_3->isChecked();
}
// reports rebated sorted by id
bool WholesaleClubMembers::on_radioButton_MembersReports_4_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    return ui->radioButton_MembersOptions_4->isChecked();
}
// reports amount due
bool WholesaleClubMembers::on_radioButton_MembersReports_5_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(true);
    ui->label_DisplayReports->setVisible(false);
    return ui->radioButton_MembersReports_5->isChecked();
}
// back to options
bool WholesaleClubMembers::on_radioButton_MembersReports_6_clicked()
{
    // Logo/Display Reports
    ui->textBrowser_DisplayReports->setVisible(false);
    ui->label_DisplayReports->setVisible(true);
    push_button_back_settins();
    return ui->radioButton_MembersReports_6->isChecked();
}

