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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pb_load_eto;
    QGroupBox *eto;
    QVBoxLayout *verticalLayout_8;
    QLabel *lb_eto_1;
    QLabel *lb_eto_2;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_7;
    QWidget *wd_set_categories;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_9;
    QWidget *wd_matriz_2;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_3;
    QSpinBox *sb_qnt_simp_2;
    QLabel *label_2;
    QSpinBox *sb_sim_boots;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_5;
    QSpinBox *sb_numero_maximo;
    QLabel *label_6;
    QSpinBox *sb_taxa_mudanca;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_4;
    QSpinBox *sb_reamostra;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_creat_analisis;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
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
        MainWindow->resize(869, 892);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(600, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/logo_ethowatcher.png")));
        label->setScaledContents(true);

        verticalLayout_5->addWidget(label);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_14 = new QVBoxLayout(tab_4);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(0, 200));
        horizontalLayout_5 = new QHBoxLayout(groupBox_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pb_load_eto = new QPushButton(groupBox_5);
        pb_load_eto->setObjectName(QString::fromUtf8("pb_load_eto"));
        pb_load_eto->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(pb_load_eto);

        eto = new QGroupBox(groupBox_5);
        eto->setObjectName(QString::fromUtf8("eto"));
        verticalLayout_8 = new QVBoxLayout(eto);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        lb_eto_1 = new QLabel(eto);
        lb_eto_1->setObjectName(QString::fromUtf8("lb_eto_1"));

        verticalLayout_8->addWidget(lb_eto_1);

        lb_eto_2 = new QLabel(eto);
        lb_eto_2->setObjectName(QString::fromUtf8("lb_eto_2"));

        verticalLayout_8->addWidget(lb_eto_2);


        horizontalLayout_5->addWidget(eto);

        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_7 = new QVBoxLayout(groupBox_6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        wd_set_categories = new QWidget(groupBox_6);
        wd_set_categories->setObjectName(QString::fromUtf8("wd_set_categories"));

        verticalLayout_7->addWidget(wd_set_categories);


        horizontalLayout_5->addWidget(groupBox_6);


        verticalLayout_14->addWidget(groupBox_5);

        widget_4 = new QWidget(tab_4);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_8 = new QGroupBox(widget_4);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setMinimumSize(QSize(300, 300));
        verticalLayout_9 = new QVBoxLayout(groupBox_8);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        wd_matriz_2 = new QWidget(groupBox_8);
        wd_matriz_2->setObjectName(QString::fromUtf8("wd_matriz_2"));

        verticalLayout_9->addWidget(wd_matriz_2);


        horizontalLayout_4->addWidget(groupBox_8);

        groupBox_7 = new QGroupBox(widget_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMaximumSize(QSize(300, 16777215));
        verticalLayout_13 = new QVBoxLayout(groupBox_7);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        groupBox_9 = new QGroupBox(groupBox_7);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        verticalLayout_10 = new QVBoxLayout(groupBox_9);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_3 = new QLabel(groupBox_9);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_10->addWidget(label_3);

        sb_qnt_simp_2 = new QSpinBox(groupBox_9);
        sb_qnt_simp_2->setObjectName(QString::fromUtf8("sb_qnt_simp_2"));
        sb_qnt_simp_2->setMinimum(1);

        verticalLayout_10->addWidget(sb_qnt_simp_2);

        label_2 = new QLabel(groupBox_9);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_10->addWidget(label_2);

        sb_sim_boots = new QSpinBox(groupBox_9);
        sb_sim_boots->setObjectName(QString::fromUtf8("sb_sim_boots"));
        sb_sim_boots->setMinimum(1);

        verticalLayout_10->addWidget(sb_sim_boots);


        verticalLayout_13->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(groupBox_7);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        verticalLayout_11 = new QVBoxLayout(groupBox_10);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_5 = new QLabel(groupBox_10);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_11->addWidget(label_5);

        sb_numero_maximo = new QSpinBox(groupBox_10);
        sb_numero_maximo->setObjectName(QString::fromUtf8("sb_numero_maximo"));
        sb_numero_maximo->setMinimum(1);

        verticalLayout_11->addWidget(sb_numero_maximo);

        label_6 = new QLabel(groupBox_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_11->addWidget(label_6);

        sb_taxa_mudanca = new QSpinBox(groupBox_10);
        sb_taxa_mudanca->setObjectName(QString::fromUtf8("sb_taxa_mudanca"));
        sb_taxa_mudanca->setMinimum(1);

        verticalLayout_11->addWidget(sb_taxa_mudanca);


        verticalLayout_13->addWidget(groupBox_10);

        widget_3 = new QWidget(groupBox_7);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_12 = new QVBoxLayout(widget_3);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_12->addWidget(label_4);

        sb_reamostra = new QSpinBox(widget_3);
        sb_reamostra->setObjectName(QString::fromUtf8("sb_reamostra"));
        sb_reamostra->setMinimum(1);
        sb_reamostra->setValue(10);

        verticalLayout_12->addWidget(sb_reamostra);


        verticalLayout_13->addWidget(widget_3);


        horizontalLayout_4->addWidget(groupBox_7);


        verticalLayout_14->addWidget(widget_4);

        widget_2 = new QWidget(tab_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 100));
        widget_2->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pb_creat_analisis = new QPushButton(widget_2);
        pb_creat_analisis->setObjectName(QString::fromUtf8("pb_creat_analisis"));

        horizontalLayout_3->addWidget(pb_creat_analisis);


        verticalLayout_14->addWidget(widget_2);

        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(tab_3);
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

        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(300, 300));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        wd_matriz = new QWidget(groupBox_4);
        wd_matriz->setObjectName(QString::fromUtf8("wd_matriz"));

        verticalLayout_3->addWidget(wd_matriz);


        verticalLayout_4->addWidget(groupBox_4);

        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);

        verticalLayout_4->addWidget(pushButton_2);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_5->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 869, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Agreement analysis", nullptr));
        label->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Use etographies", nullptr));
        pb_load_eto->setText(QCoreApplication::translate("MainWindow", "Load etographie", nullptr));
        eto->setTitle(QCoreApplication::translate("MainWindow", "Etographies", nullptr));
        lb_eto_1->setText(QString());
        lb_eto_2->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Categories", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Agreement table", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Bootstrap controlers", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "Simplifica\303\247\303\265es no calculo da matriz de confus\303\243o maxima", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Simplificacao da matriz medida", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Simplificacao da matriz bootstrap", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "Otimiza\303\247\303\243o no calculo de vies e prevalencia", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Numero maximo de combinacoes", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "taxa de mudanca", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Quantidade de re amostras", nullptr));
        pb_creat_analisis->setText(QCoreApplication::translate("MainWindow", "Generate Report", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Create agreement table using etographies files", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "1- Insert at least three behavioral categories", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "2- Digite the categorie name", nullptr));
        pb_add_categorie->setText(QCoreApplication::translate("MainWindow", "Add new categorie", nullptr));
        pb_create_matriz->setText(QCoreApplication::translate("MainWindow", "3- Done", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Categories", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Agreement table", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Generate agreement report", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Create custom agreement table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
