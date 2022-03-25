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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_categorie_text;
    QPushButton *pb_add_categorie;
    QPushButton *pb_create_matriz;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QWidget *wd_catregorias;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *wd_matriz;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(664, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(600, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/logo_ethowatcher.png")));
        label->setScaledContents(true);

        verticalLayout_4->addWidget(label);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 200));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        le_categorie_text = new QLineEdit(groupBox_3);
        le_categorie_text->setObjectName(QString::fromUtf8("le_categorie_text"));

        horizontalLayout_2->addWidget(le_categorie_text);

        pb_add_categorie = new QPushButton(groupBox_3);
        pb_add_categorie->setObjectName(QString::fromUtf8("pb_add_categorie"));

        horizontalLayout_2->addWidget(pb_add_categorie);


        verticalLayout_2->addWidget(groupBox_3);

        pb_create_matriz = new QPushButton(widget);
        pb_create_matriz->setObjectName(QString::fromUtf8("pb_create_matriz"));
        pb_create_matriz->setEnabled(false);

        verticalLayout_2->addWidget(pb_create_matriz);


        horizontalLayout->addWidget(widget);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wd_catregorias = new QWidget(groupBox_2);
        wd_catregorias->setObjectName(QString::fromUtf8("wd_catregorias"));

        verticalLayout->addWidget(wd_catregorias);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_4->addWidget(groupBox);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(300, 300));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        wd_matriz = new QWidget(groupBox_4);
        wd_matriz->setObjectName(QString::fromUtf8("wd_matriz"));

        verticalLayout_3->addWidget(wd_matriz);


        verticalLayout_4->addWidget(groupBox_4);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);

        verticalLayout_4->addWidget(pushButton_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 664, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Agreement analysis", nullptr));
        label->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "1- Insert at least three behavioral categories", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "2- Digite the categorie name", nullptr));
        pb_add_categorie->setText(QCoreApplication::translate("MainWindow", "Add new categorie", nullptr));
        pb_create_matriz->setText(QCoreApplication::translate("MainWindow", "3- Done", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Categories", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Agreement table", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Generate agreement report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
