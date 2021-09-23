#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pb_reliability_clicked()
{
    tela_reliability = new teaConcordancia();
    tela_reliability->show();
}


void MainWindow::on_pb_teste_1_clicked()
{
    QString fonteVideoETOXML = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://Users//Bio//Desktop//videos//",
                "Video Files (*.etoxml)"
                );
    Etografia eto_lida2 = lerETOXML(fonteVideoETOXML);

    qDebug() << "teste";
}

