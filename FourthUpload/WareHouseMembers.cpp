#include "WareHouseMembers.h"
#include "ui_WareHouseMemberssemembers.h"

WareHouseMembers::WareHouseMembers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WareHouseMembers)
{
    ui->setupUi(this);
    // setting text file entry and button invisible until user selects B,P,A
    ui->txtFileEntry_lineEdit->setVisible(false);
    ui->txtFileEntry_lineEdit->setEnabled(false);
    ui->txtFileEntry_pushButton->setVisible(false);
    ui->txtFileEntry_pushButton->setEnabled(false);
    // setting enter name and button invisible until user wants to use
    ui->name_lineEdit->setVisible(false);
    ui->name_lineEdit->setEnabled(false);
    ui->enterName_pushButton->setVisible(false);
    ui->enterName_pushButton->setEnabled(false);
    // setting enter date and button invisible until user wants to use
    ui->date_lineEdit->setVisible(false);
    ui->date_lineEdit->setEnabled(false);
    ui->enterDate_pushButton->setVisible(false);
    ui->enterDate_pushButton->setEnabled(false);
    // setting enter id and button invisible until user wants to use
    ui->enterID_lineEdit->setVisible(false);
    ui->enterID_lineEdit->setEnabled(false);
    ui->enterID_pushButton->setVisible(false);
    ui->enterID_pushButton->setEnabled(false);
    // setting enter item and button invisible until user wants to use
    ui->enterItem_lineEdit->setVisible(false);
    ui->enterItem_lineEdit->setEnabled(false);
    ui->enterItem_pushButton->setVisible(false);
    ui->enterItem_lineEdit->setEnabled(false);
    // rebate set invisible unless user is preferred
    ui->rebate_pushButton->setVisible(false);
    ui->rebate_pushButton->setEnabled(false);
    // set sort/price to invisible
    ui->sored_pushButton->setVisible(false);
    ui->sored_pushButton->setEnabled(false);
    ui->prices_pushButton->setVisible(false);
    ui->prices_pushButton->setEnabled(false);
    // create new dynamic date, inherteriated from memberlist.h
    members_Date = new Date<size_t>(4,20,2017);
    // creating new dynamic memory of pointers for each variable type required by customer.
    members_date = new MembersList<std::string>;
    members_id = new MembersList<size_t>;
    members_items = new MembersList<std::string>;
    items_price = new MembersList<double>;
    items_quantity = new MembersList<size_t>;
}

WareHouseMembers::~WareHouseMembers()
{
    delete ui;
    delete members_date;
    delete members_id;
    delete members_items;
    delete items_price;
    delete items_quantity;
    delete preferred_rebate;
}

// membership text file input/output
bool WareHouseMembers::on_txtFileEntry_pushButton_clicked()
{
    QFile file("/Users/philipkim/Qt/QtProject/Computer_Science_08"
               "/CS_08_PROJECT/build-WareHouseMembers-Desktop_Qt_5_8_0_clang_64bit-Debug"
               "/day1.txt");
    if(!file.exists())
        ui->textBrowser->append("Text file does not exist");
    else if(!file.open(IO_ReadOnly))
        ui->textBrowser->setText("Error with text file");
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
            QStringList lineList = QStr_line.split("\",\"");
            members_date->push_back(QStr_line.toStdString());
            qDebug() << "linea: "<< QStr_line << endl;
        }
    }
    file.close();
    ui->textBrowser->setText(QString::fromStdString("Data: " + members_date->output_linkedlist() + '\n'));
    return ui->txtFileEntry_pushButton->isChecked();
}

// membership type (Basic, Preferred, All)
bool WareHouseMembers::on_Basic_radioButton_clicked()
{
    ui->txtFileEntry_lineEdit->setVisible(true);
    ui->txtFileEntry_lineEdit->setEnabled(true);
    ui->txtFileEntry_pushButton->setVisible(true);
    ui->txtFileEntry_pushButton->setEnabled(true);
    ui->sored_pushButton->setVisible(true);
    ui->sored_pushButton->setEnabled(true);
    ui->prices_pushButton->setVisible(true);
    ui->prices_pushButton->setEnabled(true);
    return ui->Basic_radioButton->isChecked();
}

bool WareHouseMembers::on_Preferred_radioButton_clicked()
{
    preferred_rebate = new MembersList<double>;
    ui->txtFileEntry_lineEdit->setVisible(true);
    ui->txtFileEntry_lineEdit->setEnabled(true);
    ui->txtFileEntry_pushButton->setVisible(true);
    ui->txtFileEntry_pushButton->setEnabled(true);
    ui->rebate_pushButton->setVisible(true);
    ui->rebate_pushButton->setEnabled(true);
    ui->sored_pushButton->setVisible(true);
    ui->sored_pushButton->setEnabled(true);
    ui->prices_pushButton->setVisible(true);
    ui->prices_pushButton->setEnabled(true);
    return ui->Preferred_radioButton->isChecked();
}

bool WareHouseMembers::on_All_radioButton_clicked()
{
    preferred_rebate = new MembersList<double>;
    ui->txtFileEntry_lineEdit->setVisible(true);
    ui->txtFileEntry_lineEdit->setEnabled(true);
    ui->txtFileEntry_pushButton->setVisible(true);
    ui->txtFileEntry_pushButton->setEnabled(true);
    ui->rebate_pushButton->setVisible(true);
    ui->rebate_pushButton->setEnabled(true);
    ui->sored_pushButton->setVisible(true);
    ui->sored_pushButton->setEnabled(true);
    ui->prices_pushButton->setVisible(true);
    ui->prices_pushButton->setEnabled(true);
    return ui->All_radioButton->isChecked();
}

// membership edit name, id, items
bool WareHouseMembers::on_name_pushButton_clicked()
{
    ui->name_lineEdit->setVisible(true);
    ui->name_lineEdit->setEnabled(true);
    ui->enterName_pushButton->setVisible(true);
    ui->enterName_pushButton->setEnabled(true);
    return ui->name_pushButton->isChecked();
}

bool WareHouseMembers::on_id_pushButton_clicked()
{
    ui->enterID_lineEdit->setVisible(true);
    ui->enterID_lineEdit->setEnabled(true);
    ui->enterID_pushButton->setVisible(true);
    ui->enterID_pushButton->setEnabled(true);

    return ui->enterID_pushButton->isChecked();
}

bool WareHouseMembers::on_items_pushButton_clicked()
{
    ui->enterItem_lineEdit->setVisible(true);
    ui->enterItem_lineEdit->setEnabled(true);
    ui->enterItem_pushButton->setVisible(true);
    ui->enterItem_lineEdit->setEnabled(true);

    return ui->enterItem_pushButton->isChecked();
}

// members edit by date
bool WareHouseMembers::on_date_pushButton_clicked()
{
    ui->date_lineEdit->setVisible(true);
    ui->date_lineEdit->setEnabled(true);
    ui->enterDate_pushButton->setVisible(true);
    ui->enterDate_pushButton->setEnabled(true);
    return ui->date_pushButton->isChecked();
}

bool WareHouseMembers::on_enterDate_pushButton_clicked()
{
    ui->textBrowser->setText(QString::fromStdString("Members Date: " + members_date->printNumeric() + '\n'));
    return ui->enterDate_pushButton->isChecked();
}

// pushButtons prices, rebate, sorted
void WareHouseMembers::on_prices_pushButton_clicked()
{

}

void WareHouseMembers::on_rebate_pushButton_clicked()
{

}

void WareHouseMembers::on_sored_pushButton_clicked()
{
    members_date->select_sort();
    ui->textBrowser->setText(QString::fromStdString("Data: " + members_date->output_linkedlist() + '\n'));
}
