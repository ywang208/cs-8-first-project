/********************************************************************************
** Form generated from reading UI file 'WholesaleClubMembers.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHOLESALECLUBMEMBERS_H
#define UI_WHOLESALECLUBMEMBERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WholesaleClubMembers
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_MembersEntry;
    QTextBrowser *textBrowser_MembersEntry;
    QLineEdit *lineEdit_MembersEntry;
    QLabel *label_MembersEntry;
    QPushButton *pushButton_Enter;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_No;
    QPushButton *pushButton_Yes;
    QGroupBox *groupBox_Options;
    QRadioButton *radioButton_Options_1;
    QRadioButton *radioButton_Options_2;
    QRadioButton *radioButton_Options_4;
    QRadioButton *radioButton_Options_3;
    QRadioButton *radioButton_Options_6;
    QRadioButton *radioButton_Options_5;
    QRadioButton *radioButton_Options_8;
    QRadioButton *radioButton_Options_7;
    QGroupBox *groupBox_Reports;
    QRadioButton *radioButton_Reports_1;
    QRadioButton *radioButton_Reports_4;
    QRadioButton *radioButton_Reports_3;
    QRadioButton *radioButton_Reports_5;
    QRadioButton *radioButton_Reports_2;
    QGroupBox *groupBox_Name_ID;
    QRadioButton *radioButton_name;
    QRadioButton *radioButton_ID;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_DisplayReports;
    QLabel *label_DisplayReports;
    QTextBrowser *textBrowser_DisplayReports;
    QMenuBar *menuBar;
    QMenu *menuWholesale_Club_Members;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WholesaleClubMembers)
    {
        if (WholesaleClubMembers->objectName().isEmpty())
            WholesaleClubMembers->setObjectName(QStringLiteral("WholesaleClubMembers"));
        WholesaleClubMembers->resize(1050, 962);
        centralWidget = new QWidget(WholesaleClubMembers);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_MembersEntry = new QGroupBox(centralWidget);
        groupBox_MembersEntry->setObjectName(QStringLiteral("groupBox_MembersEntry"));
        groupBox_MembersEntry->setGeometry(QRect(20, 20, 441, 821));
        groupBox_MembersEntry->setAlignment(Qt::AlignCenter);
        textBrowser_MembersEntry = new QTextBrowser(groupBox_MembersEntry);
        textBrowser_MembersEntry->setObjectName(QStringLiteral("textBrowser_MembersEntry"));
        textBrowser_MembersEntry->setGeometry(QRect(20, 40, 401, 361));
        lineEdit_MembersEntry = new QLineEdit(groupBox_MembersEntry);
        lineEdit_MembersEntry->setObjectName(QStringLiteral("lineEdit_MembersEntry"));
        lineEdit_MembersEntry->setGeometry(QRect(30, 450, 251, 51));
        label_MembersEntry = new QLabel(groupBox_MembersEntry);
        label_MembersEntry->setObjectName(QStringLiteral("label_MembersEntry"));
        label_MembersEntry->setGeometry(QRect(30, 430, 81, 16));
        pushButton_Enter = new QPushButton(groupBox_MembersEntry);
        pushButton_Enter->setObjectName(QStringLiteral("pushButton_Enter"));
        pushButton_Enter->setGeometry(QRect(300, 450, 61, 51));
        pushButton_Clear = new QPushButton(groupBox_MembersEntry);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(360, 450, 61, 51));
        pushButton_No = new QPushButton(groupBox_MembersEntry);
        pushButton_No->setObjectName(QStringLiteral("pushButton_No"));
        pushButton_No->setGeometry(QRect(220, 420, 61, 51));
        pushButton_Yes = new QPushButton(groupBox_MembersEntry);
        pushButton_Yes->setObjectName(QStringLiteral("pushButton_Yes"));
        pushButton_Yes->setGeometry(QRect(160, 420, 61, 51));
        groupBox_Options = new QGroupBox(groupBox_MembersEntry);
        groupBox_Options->setObjectName(QStringLiteral("groupBox_Options"));
        groupBox_Options->setGeometry(QRect(30, 420, 191, 261));
        groupBox_Options->setAlignment(Qt::AlignCenter);
        radioButton_Options_1 = new QRadioButton(groupBox_Options);
        radioButton_Options_1->setObjectName(QStringLiteral("radioButton_Options_1"));
        radioButton_Options_1->setGeometry(QRect(11, 31, 191, 22));
        radioButton_Options_2 = new QRadioButton(groupBox_Options);
        radioButton_Options_2->setObjectName(QStringLiteral("radioButton_Options_2"));
        radioButton_Options_2->setGeometry(QRect(11, 59, 171, 22));
        radioButton_Options_4 = new QRadioButton(groupBox_Options);
        radioButton_Options_4->setObjectName(QStringLiteral("radioButton_Options_4"));
        radioButton_Options_4->setGeometry(QRect(11, 115, 141, 22));
        radioButton_Options_3 = new QRadioButton(groupBox_Options);
        radioButton_Options_3->setObjectName(QStringLiteral("radioButton_Options_3"));
        radioButton_Options_3->setGeometry(QRect(11, 87, 151, 22));
        radioButton_Options_6 = new QRadioButton(groupBox_Options);
        radioButton_Options_6->setObjectName(QStringLiteral("radioButton_Options_6"));
        radioButton_Options_6->setGeometry(QRect(11, 171, 161, 22));
        radioButton_Options_5 = new QRadioButton(groupBox_Options);
        radioButton_Options_5->setObjectName(QStringLiteral("radioButton_Options_5"));
        radioButton_Options_5->setGeometry(QRect(11, 143, 161, 22));
        radioButton_Options_8 = new QRadioButton(groupBox_Options);
        radioButton_Options_8->setObjectName(QStringLiteral("radioButton_Options_8"));
        radioButton_Options_8->setGeometry(QRect(11, 227, 91, 22));
        radioButton_Options_7 = new QRadioButton(groupBox_Options);
        radioButton_Options_7->setObjectName(QStringLiteral("radioButton_Options_7"));
        radioButton_Options_7->setGeometry(QRect(11, 199, 141, 22));
        groupBox_Reports = new QGroupBox(groupBox_MembersEntry);
        groupBox_Reports->setObjectName(QStringLiteral("groupBox_Reports"));
        groupBox_Reports->setGeometry(QRect(250, 420, 161, 181));
        groupBox_Reports->setAlignment(Qt::AlignCenter);
        radioButton_Reports_1 = new QRadioButton(groupBox_Reports);
        radioButton_Reports_1->setObjectName(QStringLiteral("radioButton_Reports_1"));
        radioButton_Reports_1->setGeometry(QRect(11, 31, 121, 22));
        radioButton_Reports_4 = new QRadioButton(groupBox_Reports);
        radioButton_Reports_4->setObjectName(QStringLiteral("radioButton_Reports_4"));
        radioButton_Reports_4->setGeometry(QRect(11, 115, 131, 22));
        radioButton_Reports_3 = new QRadioButton(groupBox_Reports);
        radioButton_Reports_3->setObjectName(QStringLiteral("radioButton_Reports_3"));
        radioButton_Reports_3->setGeometry(QRect(11, 87, 131, 22));
        radioButton_Reports_5 = new QRadioButton(groupBox_Reports);
        radioButton_Reports_5->setObjectName(QStringLiteral("radioButton_Reports_5"));
        radioButton_Reports_5->setGeometry(QRect(11, 143, 121, 22));
        radioButton_Reports_2 = new QRadioButton(groupBox_Reports);
        radioButton_Reports_2->setObjectName(QStringLiteral("radioButton_Reports_2"));
        radioButton_Reports_2->setGeometry(QRect(11, 59, 111, 22));
        groupBox_Name_ID = new QGroupBox(groupBox_MembersEntry);
        groupBox_Name_ID->setObjectName(QStringLiteral("groupBox_Name_ID"));
        groupBox_Name_ID->setGeometry(QRect(150, 410, 141, 141));
        QFont font;
        font.setPointSize(17);
        groupBox_Name_ID->setFont(font);
        groupBox_Name_ID->setAlignment(Qt::AlignCenter);
        radioButton_name = new QRadioButton(groupBox_Name_ID);
        radioButton_name->setObjectName(QStringLiteral("radioButton_name"));
        radioButton_name->setGeometry(QRect(31, 83, 70, 26));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButton_name->sizePolicy().hasHeightForWidth());
        radioButton_name->setSizePolicy(sizePolicy);
        radioButton_ID = new QRadioButton(groupBox_Name_ID);
        radioButton_ID->setObjectName(QStringLiteral("radioButton_ID"));
        radioButton_ID->setGeometry(QRect(31, 51, 56, 26));
        sizePolicy.setHeightForWidth(radioButton_ID->sizePolicy().hasHeightForWidth());
        radioButton_ID->setSizePolicy(sizePolicy);
        lineEdit = new QLineEdit(groupBox_MembersEntry);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 730, 171, 41));
        groupBox_DisplayReports = new QGroupBox(centralWidget);
        groupBox_DisplayReports->setObjectName(QStringLiteral("groupBox_DisplayReports"));
        groupBox_DisplayReports->setGeometry(QRect(470, 20, 561, 711));
        groupBox_DisplayReports->setAlignment(Qt::AlignCenter);
        label_DisplayReports = new QLabel(groupBox_DisplayReports);
        label_DisplayReports->setObjectName(QStringLiteral("label_DisplayReports"));
        label_DisplayReports->setGeometry(QRect(20, 30, 521, 651));
        textBrowser_DisplayReports = new QTextBrowser(groupBox_DisplayReports);
        textBrowser_DisplayReports->setObjectName(QStringLiteral("textBrowser_DisplayReports"));
        textBrowser_DisplayReports->setGeometry(QRect(20, 40, 521, 651));
        WholesaleClubMembers->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WholesaleClubMembers);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1050, 22));
        menuWholesale_Club_Members = new QMenu(menuBar);
        menuWholesale_Club_Members->setObjectName(QStringLiteral("menuWholesale_Club_Members"));
        menuWholesale_Club_Members->setInputMethodHints(Qt::ImhNone);
        WholesaleClubMembers->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WholesaleClubMembers);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WholesaleClubMembers->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WholesaleClubMembers);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WholesaleClubMembers->setStatusBar(statusBar);

        menuBar->addAction(menuWholesale_Club_Members->menuAction());

        retranslateUi(WholesaleClubMembers);

        QMetaObject::connectSlotsByName(WholesaleClubMembers);
    } // setupUi

    void retranslateUi(QMainWindow *WholesaleClubMembers)
    {
        WholesaleClubMembers->setWindowTitle(QApplication::translate("WholesaleClubMembers", "WholesaleClubMembers", Q_NULLPTR));
        groupBox_MembersEntry->setTitle(QApplication::translate("WholesaleClubMembers", "Members Entry:", Q_NULLPTR));
        label_MembersEntry->setText(QApplication::translate("WholesaleClubMembers", "Enter here:", Q_NULLPTR));
        pushButton_Enter->setText(QApplication::translate("WholesaleClubMembers", "Enter", Q_NULLPTR));
        pushButton_Clear->setText(QApplication::translate("WholesaleClubMembers", "Clear", Q_NULLPTR));
        pushButton_No->setText(QApplication::translate("WholesaleClubMembers", "No", Q_NULLPTR));
        pushButton_Yes->setText(QApplication::translate("WholesaleClubMembers", "Yes", Q_NULLPTR));
        groupBox_Options->setTitle(QApplication::translate("WholesaleClubMembers", "Options:", Q_NULLPTR));
        radioButton_Options_1->setText(QApplication::translate("WholesaleClubMembers", "1. Show total purchases", Q_NULLPTR));
        radioButton_Options_2->setText(QApplication::translate("WholesaleClubMembers", "2. Search item names", Q_NULLPTR));
        radioButton_Options_4->setText(QApplication::translate("WholesaleClubMembers", "4. Add members", Q_NULLPTR));
        radioButton_Options_3->setText(QApplication::translate("WholesaleClubMembers", "3. Show exp date", Q_NULLPTR));
        radioButton_Options_6->setText(QApplication::translate("WholesaleClubMembers", "6. Create Purchases", Q_NULLPTR));
        radioButton_Options_5->setText(QApplication::translate("WholesaleClubMembers", "5. Delete members", Q_NULLPTR));
        radioButton_Options_8->setText(QApplication::translate("WholesaleClubMembers", "8. Quit", Q_NULLPTR));
        radioButton_Options_7->setText(QApplication::translate("WholesaleClubMembers", "7. Show reports", Q_NULLPTR));
        groupBox_Reports->setTitle(QApplication::translate("WholesaleClubMembers", "Reports:", Q_NULLPTR));
        radioButton_Reports_1->setText(QApplication::translate("WholesaleClubMembers", "1. Print any day", Q_NULLPTR));
        radioButton_Reports_4->setText(QApplication::translate("WholesaleClubMembers", "4. Rebate sorted", Q_NULLPTR));
        radioButton_Reports_3->setText(QApplication::translate("WholesaleClubMembers", "3. Quantity sorted", Q_NULLPTR));
        radioButton_Reports_5->setText(QApplication::translate("WholesaleClubMembers", "5. Amount due", Q_NULLPTR));
        radioButton_Reports_2->setText(QApplication::translate("WholesaleClubMembers", "2. Print total", Q_NULLPTR));
        groupBox_Name_ID->setTitle(QApplication::translate("WholesaleClubMembers", "Name or ID", Q_NULLPTR));
        radioButton_name->setText(QApplication::translate("WholesaleClubMembers", "Name", Q_NULLPTR));
        radioButton_ID->setText(QApplication::translate("WholesaleClubMembers", "ID #", Q_NULLPTR));
        groupBox_DisplayReports->setTitle(QApplication::translate("WholesaleClubMembers", "Display Reports:", Q_NULLPTR));
        label_DisplayReports->setText(QString());
        menuWholesale_Club_Members->setTitle(QApplication::translate("WholesaleClubMembers", "Wholesale Club Members", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WholesaleClubMembers: public Ui_WholesaleClubMembers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHOLESALECLUBMEMBERS_H
