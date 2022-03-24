#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Agreement_global.h"
#include "agreement.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QWidget *parent1 = nullptr;
    const QString &caption = QString("Save File");
    QString path = QFileDialog::getSaveFileName(
                parent1,
                caption,
                "C://Users//Bio//Desktop//videos//",
                "Report (*.xlsx)"
                );

    QString saida;

    Agreement ma;

    std::vector<int> etrografia_1  = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
    std::vector<int> etrografia_2  = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2};
    std::vector<int> catalogo  = {0, 1, 2};

    QList<QString> cata_name = {"swimming",
                                 "climbimg",
                                 "Immobility"};



    qDebug() << ma.generate_report(path, etrografia_1,
                                   etrografia_2,
                                   catalogo,
                                   cata_name);


}

