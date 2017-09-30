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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WholesaleClubMembers
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_MemberEntry;
    QLineEdit *lineEdit_MemberEntry;
    QPushButton *pushButton;
    QTextBrowser *textBrowser_MemberEntry;
    QPushButton *pushButton_2;
    QPushButton *pushButton_Clear;
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
        WholesaleClubMembers->resize(1244, 718);
        centralWidget = new QWidget(WholesaleClubMembers);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_MemberEntry = new QGroupBox(centralWidget);
        groupBox_MemberEntry->setObjectName(QStringLiteral("groupBox_MemberEntry"));
        groupBox_MemberEntry->setGeometry(QRect(40, 30, 471, 591));
        lineEdit_MemberEntry = new QLineEdit(groupBox_MemberEntry);
        lineEdit_MemberEntry->setObjectName(QStringLiteral("lineEdit_MemberEntry"));
        lineEdit_MemberEntry->setGeometry(QRect(20, 460, 271, 51));
        lineEdit_MemberEntry->setClearButtonEnabled(true);
        pushButton = new QPushButton(groupBox_MemberEntry);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 460, 80, 51));
        textBrowser_MemberEntry = new QTextBrowser(groupBox_MemberEntry);
        textBrowser_MemberEntry->setObjectName(QStringLiteral("textBrowser_MemberEntry"));
        textBrowser_MemberEntry->setGeometry(QRect(20, 50, 411, 391));
        pushButton_2 = new QPushButton(groupBox_MemberEntry);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 550, 80, 24));
        pushButton_Clear = new QPushButton(groupBox_MemberEntry);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(380, 460, 80, 51));
        groupBox_Output = new QGroupBox(centralWidget);
        groupBox_Output->setObjectName(QStringLiteral("groupBox_Output"));
        groupBox_Output->setGeometry(QRect(520, 30, 721, 591));
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
        pushButton->setText(QApplication::translate("WholesaleClubMembers", "Submit", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("WholesaleClubMembers", "test", Q_NULLPTR));
        pushButton_Clear->setText(QApplication::translate("WholesaleClubMembers", "Clear", Q_NULLPTR));
        groupBox_Output->setTitle(QString());
        label_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WholesaleClubMembers: public Ui_WholesaleClubMembers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHOLESALECLUBMEMBERS_H
