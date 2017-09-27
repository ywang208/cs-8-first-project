#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtDebug>
#include <QFile>
#include <QBitArray>
#include <QTextStream>
#include <QString>
#include <QMainWindow>
#define IO_ReadOnly QIODevice::ReadOnly
QT_BEGIN_NAMESPACE
class QTextBrowser;
class QRadioButton;
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void get_data();
private slots:

    void on_pushButton_clicked();
    bool on_radioButton_clicked();
    bool on_radioButton_2_clicked();
    bool on_radioButton_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
