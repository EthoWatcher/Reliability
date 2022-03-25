#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Agreement_global.h"
#include "agreement.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ls_categorias = new QVBoxLayout(ui->wd_catregorias);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_pushButton_clicked()
//{
//    QWidget *parent1 = nullptr;
//    const QString &caption = QString("Save File");
//    QString path = QFileDialog::getSaveFileName(
//                parent1,
//                caption,
//                "C://Users//Bio//Desktop//videos//",
//                "Report (*.xlsx)"
//                );

//    QString saida;

//    Agreement ma;

//    std::vector<int> etrografia_1  = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
//    std::vector<int> etrografia_2  = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2};
//    std::vector<int> catalogo  = {0, 1, 2};

//    QList<QString> cata_name = {"swimming",
//                                 "climbimg",
//                                 "Immobility"};



//    qDebug() << ma.generate_report(path, etrografia_1,
//                                   etrografia_2,
//                                   catalogo,
//                                   cata_name);


//}


void MainWindow::on_pb_add_categorie_clicked()
{
//    QString text =
    QString new_cate_name = ui->le_categorie_text->text();


    QLabel *label = new QLabel(new_cate_name);

    ls_categorias->addWidget(label);

    ui->le_categorie_text->setText("");

    ls_label.append(label);

//    QLayout * layout = ui->wd_cate->layout();

//    QVBoxLayout *vLayout = new QVBoxLayout(ui->wd_cate);


//    label->setGeometry(120, 20, 150, 30);

//    a.setText(new_cate_name);



//    layout
}


void MainWindow::on_pb_create_matriz_clicked()
{
    QList<QString> ls_categories;

    for(auto item:ls_label ){
        ls_categories.push_back(item->text());
    }

    int qn_pontos = ls_categorias->count();

    QGridLayout *matriz_conf = new QGridLayout(ui->wd_matriz);

    int i=0;
    for(auto item: ls_categories)
    {
        matriz_conf->addWidget(new QLabel(item),0,i+1, Qt::AlignCenter);
        matriz_conf->addWidget(new QLabel(item),i+1,0, Qt::AlignCenter);

        i++;
    }


    for(int j=1; j<= ls_categorias->count(); j++){
        QList<QLineEdit*> coluna;
        for(int k=1; k<= ls_categorias->count(); k++){
            QLineEdit *li = new QLineEdit(QString::number(j));

            matriz_conf->addWidget(li,k,j,  Qt::AlignCenter);

            coluna.push_back(li);

        }
        ls_edi.push_back(coluna);

    }


}


void MainWindow::on_pushButton_2_clicked()
{
    std::vector<std::vector<int>> matriz_confusao;
    for(auto linha: ls_edi){
        std::vector<int> col_int;
        for(auto col: linha){
            col_int.push_back(col->text().toInt());
        }
        matriz_confusao.push_back(col_int);
    }
    std::vector<int> etrografia_1  = {};
    std::vector<int> etrografia_2  = {};

    for(int i=0; i< matriz_confusao.size(); i++){
        for(int j=0; j< matriz_confusao.size(); j++){
            for(int k=0; k< matriz_confusao[j][i]; k++){
               etrografia_2.push_back(j);
               etrografia_1.push_back(i);
               qDebug() << i << j;
            }

        }
    }


    std::vector<int> catalogo;
    for(int i=0; i< matriz_confusao.size(); i++){
        catalogo.push_back(i);
    }
    QList<QString> cata_name;

    for(auto labl: ls_label){
        cata_name.append(labl->text());
    }

    QWidget *parent1 = nullptr;
    const QString &caption = QString("Save File");
    QString path = QFileDialog::getSaveFileName(
                parent1,
                caption,
                "C://Users//Bio//Desktop//videos//",
                "Report (*.xlsx)"
                );


    Agreement ma;
    qDebug() << ma.generate_report(path, etrografia_1,
                                   etrografia_2,
                                   catalogo,
                                   cata_name);





    qDebug() <<"tese";
}

