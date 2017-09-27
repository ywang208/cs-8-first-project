#include "WareHouseMembers.h"
#include "ui_WareHouseMembers.h"

WareHouseMembers::WareHouseMembers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WareHouseMembers)
{
    ui->setupUi(this);
}

WareHouseMembers::~WareHouseMembers()
{
    delete ui;
}

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

        members_date = new MembersList<std::string>;
        QTextStream in(&file);
        in.setCodec("UTF-8");
        size_t counter = 0;
        QString QStr_line = in.readLine();
        while (!in.atEnd()) {
            ++counter;
            QStr_line = in.readLine();
            members_date->push_back(QStr_line.toStdString());
//            QStr_line = in.readLine();
//            members_id->push_back(QStr_line.toUInt());
//            QStr_line = in.readLine();
//            members_items->push_back(QStr_line.toStdString());
//            QStr_line = in.readLine();
//            items_price->push_back(QStr_line.toDouble());
//            QStr_line = in.readLine();
//            items_quantity->push_back(QStr_line.toUInt());
        }


        //    if(!file.exists())
        //        ui->textBrowser->append("Text file does not exist");
        //    else if(!file.open(IO_ReadOnly))
        //        ui->textBrowser->setText("Error with text file");
        //    else
        //    {
        //        QTextStream stream(&file);
        //        stream.setCodec("UTF-8");
        //        size_t counter = 0;
        //        while(!stream.atEnd())
        //        {
        //            ++counter;
        //            QStr_line = stream.readLine();
        //            QStringList lineList = QStr_line.split("\",\"");
        //            ui->textBrowser->setText(ui->textBrowser->toPlainText() + QStr_line + "\n");
        //            qDebug() << "linea: "<< QStr_line;
        //        }
        //    }


        file.close();
    }
}


void WareHouseMembers::on_pushButton_name_clicked()
{
    ui->textBrowser->setText(QString::fromStdString("Data: " + members_date->output_linkedlist() + "\n"
/*                                                    "ID: " + members_id->output_linkedlist() + "\n" +
                                                    "Items: " + members_items->output_linkedlist() + "\n" +
                                                    "Price: " + items_price->output_linkedlist() + "\n" +
                                                    "Quantity: " + items_quantity->output_linkedlist() + ".\n"*/));

}
