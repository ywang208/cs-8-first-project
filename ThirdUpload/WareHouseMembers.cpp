#include "WareHouseMembers.h"
#include "ui_WareHouseMembers.h"

WareHouseMembers::WareHouseMembers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WareHouseMembers)
{
    ui->setupUi(this);
    ui->pushButton_Rebate->setVisible(false);
    ui->pushButton_Rebate->setEnabled(false);
    ui->label_AskForBasic->setVisible(false);
    ui->label_AskForBasic->setEnabled(false);
    ui->radioButton_Yes_Basic->setVisible(false);
    ui->radioButton_Yes_Basic->setEnabled(false);
    ui->radioButton__No_Basic->setVisible(false);
    ui->radioButton__No_Basic->setEnabled(false);
}

WareHouseMembers::~WareHouseMembers()
{
    delete ui;
}

/*

03/09/2013
77777
Crest Toothpaste
7.59	1 //4 white spaces
03/09/2013

*/

// radio buttons for membership type
bool WareHouseMembers::on_radioButton_Basic_clicked()
{
    members_date = new MembersList<std::string>;
    members_id = new MembersList<int>;
    members_items = new MembersList<std::string>;
    items_price = new MembersList<double>;
    items_quantity = new MembersList<size_t>;
    ui->textBrowser->setText("Basic Members:\n");
    return ui->radioButton_Basic->isChecked();
}

bool WareHouseMembers::on_radioButton_Preferred_clicked()
{
    members_date = new MembersList<std::string>;
    members_id = new MembersList<int>;
    members_items = new MembersList<std::string>;
    items_price = new MembersList<double>;
    items_quantity = new MembersList<size_t>;
    preferred_rebate = new MembersList<double>;
    ui->textBrowser->setText("Preferred Members:\n");
    ui->pushButton_Rebate->setVisible(true);
    ui->pushButton_Rebate->setEnabled(true);
    ui->label_AskForBasic->setVisible(true);
    ui->label_AskForBasic->setEnabled(true);
    ui->radioButton_Yes_Basic->setVisible(true);
    ui->radioButton_Yes_Basic->setEnabled(true);
    ui->radioButton__No_Basic->setVisible(true);
    ui->radioButton__No_Basic->setEnabled(true);
    return ui->radioButton_Preferred->isChecked();
}

bool WareHouseMembers::on_radioButton_All_clicked()
{
    members_date = new MembersList<std::string>;
    members_id = new MembersList<int>;
    members_items = new MembersList<std::string>;
    items_price = new MembersList<double>;
    items_quantity = new MembersList<size_t>;
    preferred_rebate = new MembersList<double>;
    ui->textBrowser->setText("All Members:\n");
    ui->pushButton_Rebate->setVisible(true);
    ui->pushButton_Rebate->setEnabled(true);
    ui->label_AskForBasic->setVisible(true);
    ui->label_AskForBasic->setEnabled(true);
    ui->radioButton_Yes_Basic->setVisible(true);
    ui->radioButton_Yes_Basic->setEnabled(true);
    ui->radioButton__No_Basic->setVisible(true);
    ui->radioButton__No_Basic->setEnabled(true);
    return ui->radioButton_All->isChecked();
}

// push button for text file (input of day1.txt)
void WareHouseMembers::on_pushButton_textfile_clicked()
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
}


// push button for sorting names
void WareHouseMembers::on_pushButton_name_clicked()
{
    ui->textBrowser->setText(QString::fromStdString("Data: " + members_date->output_linkedlist() + '\n'));
}


void WareHouseMembers::on_pushButton_sorted_clicked()
{
    members_date->select_sort();
    ui->textBrowser->setText(QString::fromStdString("Data: " + members_date->output_linkedlist() + '\n'));
}
