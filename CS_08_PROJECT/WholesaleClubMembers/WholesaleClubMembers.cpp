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
    html_qstr_default.append("Welcome to Wholesale Club!\n<br/><br/><br/><br/><br/><br/><br/><br/><br/>"
                             "<br/><br/><br/><br/><br/><br/>"
                             "Please enter your enter name or membership number below:\n");
    html_qstr_default.append("</span>");
    ui->textBrowser_MemberEntry->setHtml(html_qstr_default);

    // GUI IMAGE OVER OUTPUT
    ui->textBrowser_Output->setVisible(false);
    QPixmap warehouse_logo("/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/"
                           "build-WholesaleClubMembers-Desktop_Qt_5_8_0_clang_64bit-Debug/"
                           "warehouselogo.png");
    ui->label_image->setPixmap(warehouse_logo);

}

WholesaleClubMembers::~WholesaleClubMembers()
{
    delete ui;
}

// SUBMIT BUTTON
bool WholesaleClubMembers::on_pushButton_clicked()
{
    on_lineEdit_MemberEntry_returnPressed();
    return ui->pushButton->isChecked();
}

// PRESSED ENTER
void WholesaleClubMembers::on_lineEdit_MemberEntry_returnPressed()
{

    std::string str = ui->lineEdit_MemberEntry->text().toStdString();
    qDebug() << str.c_str() << endl;
    qDebug() << "name: " <<  members_name->find_member(str) << endl;
    if(members_name->find_member(str))
        ui->textBrowser_MemberEntry->setText("FOUND!");
    else
        ui->textBrowser_MemberEntry->setText("NOT FOUND!");
}

// ENTER NAME IN LINEEDIT CLEAR
bool WholesaleClubMembers::on_pushButton_Clear_clicked()
{
    ui->lineEdit_MemberEntry->clear();
    return ui->pushButton_Clear->isChecked();
}


// test button
void WholesaleClubMembers::on_pushButton_2_clicked()
{
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

            QStr_line = in.readLine();
            members_name->push_back(QStr_line.toStdString());

            QStr_line = in.readLine();
            members_id->push_back(QStr_line.toULongLong());

            QStr_line = in.readLine();
            members_type->push_back(QStr_line.toStdString());

            QStr_line = in.readLine();
            expiration_date->push_back(QStr_line.toStdString());


            qDebug() << "linea: "<< QStr_line << endl;
        }
    }
    ui->textBrowser_MemberEntry->setText("Recieved Data from warehouseshoppers.txt");
    file.close();


    ui->label_image->setVisible(false);
    ui->label_image->setEnabled(false);
    ui->textBrowser_Output->setVisible(true);

    ui->textBrowser_Output->setText(QString::fromStdString(
                                                           "Name: " + members_name->output_linkedlist() + ", " +
                                                           "ID: " + members_id->output_linkedlist() + ", " +
                                                           "Type: " + members_type->output_linkedlist() + ", " +
                                                           "Date: " + expiration_date->output_linkedlist() + ", "));


    /*
    warehouseshoppers.txt

    Sally Shopper   // members_name
    12345           // members_id
    Basic           // members_type
    11/01/2013      // members_date

    Fred Frugal     // members_name
    67899           // members_id
    Preferred       // members_type
    12/15/2013      // members_date


    **********
    **********
    day5.txt:

    03/09/2013              // members_date
    77777                   // members_id
    Crest Toothpaste        // items_name
    7.59	1               // items price & items quantity

    day4.txt:

    03/13/2013              // members_date
    12345                   // members_id
    1 gallon milk           // items_name
    2.49	3               // items price & items quantity


    day3.txt:

    03/07/2013              // members_date
    12345                   // members_id
    1 gallon milk           // items_name
    2.49	15              // items price & items quantity

    day2.txt:

    03/06/2013              // members_date
    61616                   // members_id
    1 gallon milk           // items_name
    2.49	5               // items price & items quantity

    day1.txt:

    03/05/2013              // members_date
    12345                   // members_id
    1 gallon milk           // items_name
    2.49	13              // items price & items quantity

    */
}






