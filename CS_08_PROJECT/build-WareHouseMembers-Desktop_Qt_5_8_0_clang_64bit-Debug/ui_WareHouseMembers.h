/********************************************************************************
** Form generated from reading UI file 'WareHouseMembers.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEMEMBERS_H
#define UI_WAREHOUSEMEMBERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WareHouseMembers
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_textfile;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_name;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WareHouseMembers)
    {
        if (WareHouseMembers->objectName().isEmpty())
            WareHouseMembers->setObjectName(QStringLiteral("WareHouseMembers"));
        WareHouseMembers->resize(400, 300);
        centralWidget = new QWidget(WareHouseMembers);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_textfile = new QPushButton(centralWidget);
        pushButton_textfile->setObjectName(QStringLiteral("pushButton_textfile"));
        pushButton_textfile->setGeometry(QRect(20, 30, 80, 24));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(120, 10, 256, 192));
        pushButton_name = new QPushButton(centralWidget);
        pushButton_name->setObjectName(QStringLiteral("pushButton_name"));
        pushButton_name->setGeometry(QRect(20, 80, 80, 24));
        WareHouseMembers->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WareHouseMembers);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        WareHouseMembers->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WareHouseMembers);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WareHouseMembers->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WareHouseMembers);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WareHouseMembers->setStatusBar(statusBar);

        retranslateUi(WareHouseMembers);

        QMetaObject::connectSlotsByName(WareHouseMembers);
    } // setupUi

    void retranslateUi(QMainWindow *WareHouseMembers)
    {
        WareHouseMembers->setWindowTitle(QApplication::translate("WareHouseMembers", "WareHouseMembers", Q_NULLPTR));
        pushButton_textfile->setText(QApplication::translate("WareHouseMembers", "Text File", Q_NULLPTR));
        pushButton_name->setText(QApplication::translate("WareHouseMembers", "Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WareHouseMembers: public Ui_WareHouseMembers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEMEMBERS_H
