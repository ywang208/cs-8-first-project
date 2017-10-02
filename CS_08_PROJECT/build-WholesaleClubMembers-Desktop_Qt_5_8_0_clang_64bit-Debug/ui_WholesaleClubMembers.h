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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WholesaleClubMembers
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_MemberEntry;
    QLineEdit *lineEdit_MemberEntry;
    QPushButton *pushButton_Submit;
    QTextBrowser *textBrowser_MemberEntry;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Yes;
    QPushButton *pushButton_No;
    QGroupBox *groupBox_options;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_optionsTotal;
    QRadioButton *radioButton_optionsSearch;
    QRadioButton *radioButton_optionsDate;
    QRadioButton *radioButton_optionsAdd;
    QRadioButton *radioButton_optionsDelete;
    QRadioButton *radioButton_optionsPurchases;
    QRadioButton *radioButton_optionsReport;
    QRadioButton *radioButton_optionsQuit;
    QGroupBox *groupBox_reports;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_reportsPrintAnyDay;
    QRadioButton *radioButton_reportsPrintTotal;
    QRadioButton *radioButton_reportsQttSorted;
    QRadioButton *radioButton_reportsRebateSorted;
    QRadioButton *radioButton_reportsAmountDue;
    QRadioButton *radioButton_reportQuit;
    QGroupBox *groupBox_Output;
    QLabel *label_image;
    QTextBrowser *textBrowser_Output;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WholesaleClubMembers)
    {
        if (WholesaleClubMembers->objectName().isEmpty())
            WholesaleClubMembers->setObjectName(QStringLiteral("WholesaleClubMembers"));
        WholesaleClubMembers->resize(1244, 746);
        centralWidget = new QWidget(WholesaleClubMembers);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_MemberEntry = new QGroupBox(centralWidget);
        groupBox_MemberEntry->setObjectName(QStringLiteral("groupBox_MemberEntry"));
        groupBox_MemberEntry->setGeometry(QRect(30, 20, 481, 591));
        lineEdit_MemberEntry = new QLineEdit(groupBox_MemberEntry);
        lineEdit_MemberEntry->setObjectName(QStringLiteral("lineEdit_MemberEntry"));
        lineEdit_MemberEntry->setGeometry(QRect(20, 270, 271, 51));
        lineEdit_MemberEntry->setClearButtonEnabled(true);
        pushButton_Submit = new QPushButton(groupBox_MemberEntry);
        pushButton_Submit->setObjectName(QStringLiteral("pushButton_Submit"));
        pushButton_Submit->setGeometry(QRect(300, 270, 80, 51));
        textBrowser_MemberEntry = new QTextBrowser(groupBox_MemberEntry);
        textBrowser_MemberEntry->setObjectName(QStringLiteral("textBrowser_MemberEntry"));
        textBrowser_MemberEntry->setGeometry(QRect(20, 40, 441, 211));
        pushButton_Clear = new QPushButton(groupBox_MemberEntry);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(380, 270, 80, 51));
        pushButton_Yes = new QPushButton(groupBox_MemberEntry);
        pushButton_Yes->setObjectName(QStringLiteral("pushButton_Yes"));
        pushButton_Yes->setGeometry(QRect(70, 270, 81, 51));
        pushButton_No = new QPushButton(groupBox_MemberEntry);
        pushButton_No->setObjectName(QStringLiteral("pushButton_No"));
        pushButton_No->setGeometry(QRect(150, 270, 81, 51));
        groupBox_options = new QGroupBox(groupBox_MemberEntry);
        groupBox_options->setObjectName(QStringLiteral("groupBox_options"));
        groupBox_options->setGeometry(QRect(70, 320, 194, 261));
        verticalLayout = new QVBoxLayout(groupBox_options);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_optionsTotal = new QRadioButton(groupBox_options);
        radioButton_optionsTotal->setObjectName(QStringLiteral("radioButton_optionsTotal"));

        verticalLayout->addWidget(radioButton_optionsTotal);

        radioButton_optionsSearch = new QRadioButton(groupBox_options);
        radioButton_optionsSearch->setObjectName(QStringLiteral("radioButton_optionsSearch"));

        verticalLayout->addWidget(radioButton_optionsSearch);

        radioButton_optionsDate = new QRadioButton(groupBox_options);
        radioButton_optionsDate->setObjectName(QStringLiteral("radioButton_optionsDate"));

        verticalLayout->addWidget(radioButton_optionsDate);

        radioButton_optionsAdd = new QRadioButton(groupBox_options);
        radioButton_optionsAdd->setObjectName(QStringLiteral("radioButton_optionsAdd"));

        verticalLayout->addWidget(radioButton_optionsAdd);

        radioButton_optionsDelete = new QRadioButton(groupBox_options);
        radioButton_optionsDelete->setObjectName(QStringLiteral("radioButton_optionsDelete"));

        verticalLayout->addWidget(radioButton_optionsDelete);

        radioButton_optionsPurchases = new QRadioButton(groupBox_options);
        radioButton_optionsPurchases->setObjectName(QStringLiteral("radioButton_optionsPurchases"));

        verticalLayout->addWidget(radioButton_optionsPurchases);

        radioButton_optionsReport = new QRadioButton(groupBox_options);
        radioButton_optionsReport->setObjectName(QStringLiteral("radioButton_optionsReport"));

        verticalLayout->addWidget(radioButton_optionsReport);

        radioButton_optionsQuit = new QRadioButton(groupBox_options);
        radioButton_optionsQuit->setObjectName(QStringLiteral("radioButton_optionsQuit"));

        verticalLayout->addWidget(radioButton_optionsQuit);

        groupBox_reports = new QGroupBox(groupBox_MemberEntry);
        groupBox_reports->setObjectName(QStringLiteral("groupBox_reports"));
        groupBox_reports->setGeometry(QRect(270, 320, 151, 205));
        verticalLayout_2 = new QVBoxLayout(groupBox_reports);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButton_reportsPrintAnyDay = new QRadioButton(groupBox_reports);
        radioButton_reportsPrintAnyDay->setObjectName(QStringLiteral("radioButton_reportsPrintAnyDay"));

        verticalLayout_2->addWidget(radioButton_reportsPrintAnyDay);

        radioButton_reportsPrintTotal = new QRadioButton(groupBox_reports);
        radioButton_reportsPrintTotal->setObjectName(QStringLiteral("radioButton_reportsPrintTotal"));

        verticalLayout_2->addWidget(radioButton_reportsPrintTotal);

        radioButton_reportsQttSorted = new QRadioButton(groupBox_reports);
        radioButton_reportsQttSorted->setObjectName(QStringLiteral("radioButton_reportsQttSorted"));

        verticalLayout_2->addWidget(radioButton_reportsQttSorted);

        radioButton_reportsRebateSorted = new QRadioButton(groupBox_reports);
        radioButton_reportsRebateSorted->setObjectName(QStringLiteral("radioButton_reportsRebateSorted"));

        verticalLayout_2->addWidget(radioButton_reportsRebateSorted);

        radioButton_reportsAmountDue = new QRadioButton(groupBox_reports);
        radioButton_reportsAmountDue->setObjectName(QStringLiteral("radioButton_reportsAmountDue"));

        verticalLayout_2->addWidget(radioButton_reportsAmountDue);

        radioButton_reportQuit = new QRadioButton(groupBox_reports);
        radioButton_reportQuit->setObjectName(QStringLiteral("radioButton_reportQuit"));

        verticalLayout_2->addWidget(radioButton_reportQuit);

        groupBox_Output = new QGroupBox(centralWidget);
        groupBox_Output->setObjectName(QStringLiteral("groupBox_Output"));
        groupBox_Output->setGeometry(QRect(520, 20, 721, 591));
        label_image = new QLabel(groupBox_Output);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(30, 40, 651, 511));
        textBrowser_Output = new QTextBrowser(groupBox_Output);
        textBrowser_Output->setObjectName(QStringLiteral("textBrowser_Output"));
        textBrowser_Output->setGeometry(QRect(40, 40, 651, 511));
        WholesaleClubMembers->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WholesaleClubMembers);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1244, 22));
        WholesaleClubMembers->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WholesaleClubMembers);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WholesaleClubMembers->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WholesaleClubMembers);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WholesaleClubMembers->setStatusBar(statusBar);

        retranslateUi(WholesaleClubMembers);

        QMetaObject::connectSlotsByName(WholesaleClubMembers);
    } // setupUi

    void retranslateUi(QMainWindow *WholesaleClubMembers)
    {
        WholesaleClubMembers->setWindowTitle(QApplication::translate("WholesaleClubMembers", "WholesaleClubMembers", Q_NULLPTR));
        groupBox_MemberEntry->setTitle(QString());
        lineEdit_MemberEntry->setPlaceholderText(QApplication::translate("WholesaleClubMembers", "Enter Name or ID", Q_NULLPTR));
        pushButton_Submit->setText(QApplication::translate("WholesaleClubMembers", "Submit", Q_NULLPTR));
        pushButton_Clear->setText(QApplication::translate("WholesaleClubMembers", "Clear", Q_NULLPTR));
        pushButton_Yes->setText(QApplication::translate("WholesaleClubMembers", "Yes", Q_NULLPTR));
        pushButton_No->setText(QApplication::translate("WholesaleClubMembers", "No", Q_NULLPTR));
        groupBox_options->setTitle(QString());
        radioButton_optionsTotal->setText(QApplication::translate("WholesaleClubMembers", "1. Show total purchases", Q_NULLPTR));
        radioButton_optionsSearch->setText(QApplication::translate("WholesaleClubMembers", "2. Search Item name", Q_NULLPTR));
        radioButton_optionsDate->setText(QApplication::translate("WholesaleClubMembers", "3. Show Exp Date", Q_NULLPTR));
        radioButton_optionsAdd->setText(QApplication::translate("WholesaleClubMembers", "4. Add", Q_NULLPTR));
        radioButton_optionsDelete->setText(QApplication::translate("WholesaleClubMembers", "5. Delete", Q_NULLPTR));
        radioButton_optionsPurchases->setText(QApplication::translate("WholesaleClubMembers", "6. Purchase", Q_NULLPTR));
        radioButton_optionsReport->setText(QApplication::translate("WholesaleClubMembers", "7. Report", Q_NULLPTR));
        radioButton_optionsQuit->setText(QApplication::translate("WholesaleClubMembers", "8. Quit", Q_NULLPTR));
        groupBox_reports->setTitle(QString());
        radioButton_reportsPrintAnyDay->setText(QApplication::translate("WholesaleClubMembers", "1. Print any day", Q_NULLPTR));
        radioButton_reportsPrintTotal->setText(QApplication::translate("WholesaleClubMembers", "2. Print total ", Q_NULLPTR));
        radioButton_reportsQttSorted->setText(QApplication::translate("WholesaleClubMembers", "3. Qty sorted", Q_NULLPTR));
        radioButton_reportsRebateSorted->setText(QApplication::translate("WholesaleClubMembers", "4. Rebate sorted", Q_NULLPTR));
        radioButton_reportsAmountDue->setText(QApplication::translate("WholesaleClubMembers", "5. Amount due", Q_NULLPTR));
        radioButton_reportQuit->setText(QApplication::translate("WholesaleClubMembers", "6. Quit", Q_NULLPTR));
        groupBox_Output->setTitle(QString());
        label_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WholesaleClubMembers: public Ui_WholesaleClubMembers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHOLESALECLUBMEMBERS_H
