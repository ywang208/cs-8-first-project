#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_data()
{
    QFile file("/Users/philipkim/Qt/QtProject/Computer_Science_08/CS_08_PROJECT/build-warehouse-Desktop_Qt_5_8_0_clang_64bit-Debug/day1.txt");
    QString line;
    if(!file.exists())
        ui->textBrowser->append("file is not exists");
    else if(!file.open(IO_ReadOnly))
        ui->textBrowser->setText("Error");
    else
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        int nr = 0;
        while(!stream.atEnd())
        {
            ++nr;
            line = stream.readLine();
            QStringList lineList = line.split("\",\"");
            ui->textBrowser->setText(ui->textBrowser->toPlainText() + line + "\n");
            qDebug() << "linea: "<< line;
        }
    }
    file.close();
}

void MainWindow::on_pushButton_clicked()
{
    if(on_radioButton_clicked())
    {
        ui->textBrowser->setText("Basic Bitches");
        get_data();
    }
    else if(on_radioButton_2_clicked())
    {
        ui->textBrowser->setText("Preferred Bitches");
        get_data();
    }
    else if(on_radioButton_3_clicked())
    {
        ui->textBrowser->setText("All Bitches");
        get_data();
    }
    else
    {
        ui->textBrowser->setText("i dont know");
    }
}

bool MainWindow::on_radioButton_clicked()
{
    return ui->radioButton->isChecked();
}

bool MainWindow::on_radioButton_2_clicked()
{
    return ui->radioButton_2->isChecked();
}

bool MainWindow::on_radioButton_3_clicked()
{
    return ui->radioButton_3->isChecked();
}
