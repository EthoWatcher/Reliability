/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pb_add_categorie;
    QLineEdit *le_categorie_text;
    QWidget *wd_catregorias;
    QPushButton *pb_create_matriz;
    QWidget *wd_matriz;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(627, 638);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pb_add_categorie = new QPushButton(centralwidget);
        pb_add_categorie->setObjectName(QString::fromUtf8("pb_add_categorie"));
        pb_add_categorie->setGeometry(QRect(164, 30, 111, 23));
        le_categorie_text = new QLineEdit(centralwidget);
        le_categorie_text->setObjectName(QString::fromUtf8("le_categorie_text"));
        le_categorie_text->setGeometry(QRect(40, 30, 113, 20));
        wd_catregorias = new QWidget(centralwidget);
        wd_catregorias->setObjectName(QString::fromUtf8("wd_catregorias"));
        wd_catregorias->setGeometry(QRect(320, 30, 241, 121));
        pb_create_matriz = new QPushButton(centralwidget);
        pb_create_matriz->setObjectName(QString::fromUtf8("pb_create_matriz"));
        pb_create_matriz->setGeometry(QRect(30, 130, 251, 23));
        wd_matriz = new QWidget(centralwidget);
        wd_matriz->setObjectName(QString::fromUtf8("wd_matriz"));
        wd_matriz->setGeometry(QRect(20, 190, 581, 291));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 510, 181, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 627, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pb_add_categorie->setText(QCoreApplication::translate("MainWindow", "Add new categorie", nullptr));
        pb_create_matriz->setText(QCoreApplication::translate("MainWindow", "Create Agreement Matriz", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Generate agreement report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
