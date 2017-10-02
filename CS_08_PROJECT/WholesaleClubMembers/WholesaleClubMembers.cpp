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
    // Needed for display
    spent_amount = new MembersList<double>;
    rebate_amount = new MembersList<double>;
    daily_total_amount = new MembersList<double>;
    yearly_total_amount = new MembersList<double>;
    // Input variables day1.txt,day2.txt,etc
    items_name = new MembersList<std::string>;
    items_quantity = new MembersList<size_t>;
    items_price = new MembersList<double>;

    // DEFAULT GREETINGS
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("Welcome to Wholesale Club!"
                             "<br/><br/><br/><br/><br/><br/><br/>"
                             "Please enter your enter name or membership number below:\n");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);

    // GUI IMAGE OVER OUTPUT
    ui->textBrowser_Output->setVisible(false);
    QPixmap warehouse_logo("/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/"
                           "build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug/"
                           "warehouselogo.png");
    ui->label_image->setPixmap(warehouse_logo);

    // Setting user lineEdit and pushButtons for submit and clear to enabled
    ui->lineEdit_MemberEntry->setVisible(true);
    ui->lineEdit_MemberEntry->setEnabled(true);
    ui->pushButton_Submit->setVisible(true);
    ui->pushButton_Submit->setEnabled(true);
    ui->pushButton_Clear->setVisible(true);
    ui->pushButton_Clear->setEnabled(true);

    // Setting Yes and No buttons to invisible until needed
    ui->pushButton_Yes->setVisible(false);
    ui->pushButton_Yes->setEnabled(false);
    ui->pushButton_No->setVisible(false);
    ui->pushButton_No->setEnabled(false);

    // Setting users options and reports to invisible until needed
    ui->groupBox_options->setVisible(false);
    ui->groupBox_options->setEnabled(false);
    ui->groupBox_reports->setVisible(false);
    ui->groupBox_reports->setEnabled(false);

}

WholesaleClubMembers::~WholesaleClubMembers()
{
    delete ui;
}

// GET TEXT FILE
void WholesaleClubMembers::get_data()
{
    /*
    warehouseshoppers.txt
    Sally Shopper   // members_name
    12345           // members_id
    Basic           // members_type
    11/01/2013      // members_date
    **********
    Fred Frugal     // members_name
    67899           // members_id
    Preferred       // members_type
    12/15/2013      // members_date
    **********
    day5.txt:
    **********
    03/09/2013              // members_date
    77777                   // members_id
    Crest Toothpaste        // items_name
    7.59	1               // items price & items quantity
    **********
    day4.txt:
    **********
    03/13/2013              // members_date
    12345                   // members_id
    1 gallon milk           // items_name
    2.49	3               // items price & items quantity
    **********
    day3.txt:
    **********
    03/07/2013              // members_date
    12345                   // members_id
    1 gallon milk           // items_name
    2.49	15              // items price & items quantity
    **********
    day2.txt:
    **********
    03/06/2013              // members_date
    61616                   // members_id
    1 gallon milk           // items_name
    2.49	5               // items price & items quantity
    **********
    day1.txt:
    **********
    03/05/2013              // members_date
    12345                   // members_id
    1 gallon milk           // items_name
    2.49	13              // items price & items quantity
    **********
    ui->label_image->setVisible(false);
    ui->label_image->setEnabled(false);
    ui->textBrowser_Output->setVisible(true);

    ui->textBrowser_Output->setText(QString::fromStdString(
                                        "Name: " + members_name->output_linkedlist() + ", " +
                                        "ID: " + members_id->output_linkedlist() + ", " +
                                        "Type: " + members_type->output_linkedlist() + ", " +
                                        "Date: " + expiration_date->output_linkedlist() + ".\n"));
    */

    QFile file("/Users/philipkim/Qt/QtProject/Computer_Science_08"
               "/CS_08_PROJECT/build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug"
               "/warehouseshoppers.txt");
    if(!file.exists())
        ui->textBrowser_MemberEntry->setText("Text file does not exist");
    else if(!file.open(IO_ReadOnly))
        ui->textBrowser_MemberEntry->setText("Error with text file");
    else
    {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        size_t counter = 0;
        QString QStr_line;
        while(!in.atEnd())
        {
            ++counter;
            QStr_line = in.readLine().toLower();
            members_name->push_back(QStr_line.toStdString());
            QStr_line = in.readLine().toLower();
            members_id->push_back(QStr_line.toULongLong());
            QStr_line = in.readLine().toLower();
            members_type->push_back(QStr_line.toStdString());
            QStr_line = in.readLine().toLower();
            expiration_date->push_back(QStr_line.toStdString());
        }
    }
    file.close();
}

// PRESSED ENTER
void WholesaleClubMembers::on_lineEdit_MemberEntry_returnPressed()
{
    get_data(); // gets data from text file
    if(members_name->find_member(ui->lineEdit_MemberEntry->text().toLower().toStdString()))
    {
        QString html_qstr_default = "<span style=\"font-size:12pt;font-weight:600;color:#17DA5E;\">";
        html_qstr_default.append("Welcome back to WholeSaleClub, ");
        html_qstr_default.append(ui->lineEdit_MemberEntry->text());
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
        ui->textBrowser_MemberEntry->setHtml(html_qstr_default);

        ui->lineEdit_MemberEntry->clear();

        ui->lineEdit_MemberEntry->setVisible(false);
        ui->lineEdit_MemberEntry->setEnabled(false);

        ui->pushButton_Submit->setVisible(false);
        ui->pushButton_Submit->setEnabled(false);

        ui->pushButton_Clear->setVisible(false);
        ui->pushButton_Clear->setEnabled(false);

        ui->groupBox_options->setVisible(true);
        ui->groupBox_options->setEnabled(true);
    }

}

// SUBMIT BUTTON
bool WholesaleClubMembers::on_pushButton_Submit_clicked()
{
    // gets the text file info Sally Shopper
    get_data();

    if(members_name->find_member(ui->lineEdit_MemberEntry->text().toStdString()))
    {
        QString html_qstr_default = "<span style=\"font-size:8pt;font-weight:600;color:#17DA5E;\">";
        html_qstr_default.append("Welcome back! ");
        html_qstr_default.append(ui->lineEdit_MemberEntry->text());
        html_qstr_default.append("How can we assist you today?<br/>"
                                 "1. Totol purchases for this month<br/>"
                                 "2. Item's quantity and purchases<br/>"
                                 "3. Expiration date and amount due<br/>"
                                 "4. Add a new member<br/>"
                                 "5. Delete a member<br/>"
                                 "6. Create a purchase<br/>"
                                 "7. Reports<br/>"
                                 "8. Quit<br/><br/><br/>"
                                 "Please 1-8:<br/>");
        html_qstr_default.append("</span>");
        ui->textBrowser_MemberEntry->setHtml(html_qstr_default);

        ui->lineEdit_MemberEntry->clear();
        ui->lineEdit_MemberEntry->setPlaceholderText("Enter 1-8: ");

        ui->groupBox_options->setVisible(true);
        ui->groupBox_options->setEnabled(true);
    }
    else
    {
        QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
        html_qstr_default.append("Welcome to Wholesale Club!\n<br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                                 "<br/><br/><br/><br/><br/><br/>"
                                 "Sorry that does not match our database:\n");
        html_qstr_default.append("</span>");
        ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    }
    return ui->pushButton_Submit->isChecked();
}

// ENTER NAME IN LINEEDIT CLEAR
bool WholesaleClubMembers::on_pushButton_Clear_clicked()
{
    ui->lineEdit_MemberEntry->clear();
    return ui->pushButton_Clear->isChecked();
}

// YES
bool WholesaleClubMembers::on_pushButton_Yes_clicked()
{
    ui->pushButton_Yes->setVisible(false);
    ui->pushButton_Yes->setEnabled(false);
    ui->pushButton_No->setVisible(false);
    ui->pushButton_No->setEnabled(false);

    ui->groupBox_options->setVisible(false);
    ui->groupBox_options->setEnabled(false);
    ui->groupBox_reports->setVisible(false);
    ui->groupBox_reports->setEnabled(false);

    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("Thank you for stopping by WholeSale Club!<br/>"
                             "Come back soon! And have a nice day.<br/>");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);

    return ui->pushButton_Yes->isChecked();
}

// NO
bool WholesaleClubMembers::on_pushButton_No_clicked()
{
    ui->pushButton_Yes->setVisible(false);
    ui->pushButton_Yes->setEnabled(false);
    ui->pushButton_No->setVisible(false);
    ui->pushButton_No->setEnabled(false);

    ui->groupBox_options->setVisible(true);
    ui->groupBox_options->setEnabled(true);
    ui->groupBox_reports->setVisible(false);
    ui->groupBox_reports->setEnabled(false);

    QString html_qstr_default = "<span style=\"font-size:12pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("Please select the following options:<br/>"
                             "1. Totol purchases for this month<br/>"
                             "2. Item's quantity and purchases<br/>"
                             "3. Expiration date and amount due<br/>"
                             "4. Add a new member<br/>"
                             "5. Delete a member<br/>"
                             "6. Create a purchase<br/>"
                             "7. Reports<br/>"
                             "8. Quit<br/><br/><br/>"
                             "Please 1-8:<br/>");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);

    return ui->pushButton_No->isChecked();
}


// RADIO BUTTONS FOR OPTIONS
bool WholesaleClubMembers::on_radioButton_optionsTotal_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("total");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_optionsTotal->isChecked();
}

bool WholesaleClubMembers::on_radioButton_optionsSearch_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("search");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_optionsSearch->isChecked();
}

bool WholesaleClubMembers::on_radioButton_optionsDate_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("date");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_optionsDate->isChecked();
}

bool WholesaleClubMembers::on_radioButton_optionsAdd_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("add");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_optionsAdd->isChecked();
}

bool WholesaleClubMembers::on_radioButton_optionsDelete_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("delete");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_optionsDelete->isChecked();
}

bool WholesaleClubMembers::on_radioButton_optionsPurchases_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("purchases");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_optionsPurchases->isChecked();
}

bool WholesaleClubMembers::on_radioButton_optionsReport_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("reports");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    ui->groupBox_reports->setVisible(true);
    ui->groupBox_reports->setEnabled(true);
    return ui->radioButton_optionsReport->isChecked();
}

bool WholesaleClubMembers::on_radioButton_optionsQuit_clicked()
{

    ui->pushButton_Yes->setVisible(true);
    ui->pushButton_Yes->setEnabled(true);
    ui->pushButton_No->setVisible(true);
    ui->pushButton_No->setEnabled(true);

    return ui->radioButton_optionsQuit->isChecked();
}


// RADIO BUTTONS FOR REPORTS
bool WholesaleClubMembers::on_radioButton_reportsPrintAnyDay_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("repots: print any day");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_reportsPrintAnyDay->isChecked();
}

bool WholesaleClubMembers::on_radioButton_reportsPrintTotal_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("repots: print total");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_reportsPrintTotal->isChecked();
}

bool WholesaleClubMembers::on_radioButton_reportsQttSorted_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("repots: print qty sorted");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);

    return ui->radioButton_reportsQttSorted->isChecked();
}

bool WholesaleClubMembers::on_radioButton_reportsRebateSorted_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("repots: print rebate sorted");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);

    return ui->radioButton_reportsRebateSorted->isChecked();
}

bool WholesaleClubMembers::on_radioButton_reportsAmountDue_clicked()
{
    QString html_qstr_default = "<span style=\"font-size:18pt;font-weight:600;color:#17DA5E;\">";
    html_qstr_default.append("repots: print amount due");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);
    return ui->radioButton_reportsAmountDue->isChecked();
}

bool WholesaleClubMembers::on_radioButton_reportQuit_clicked()
{

    ui->pushButton_Yes->setVisible(true);
    ui->pushButton_Yes->setEnabled(true);
    ui->pushButton_No->setVisible(true);
    ui->pushButton_No->setEnabled(true);

    return ui->radioButton_reportQuit->isChecked();
}
