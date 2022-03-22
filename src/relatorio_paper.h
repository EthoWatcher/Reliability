#ifndef RELATORIO_PAPER_H
#define RELATORIO_PAPER_H

#include <vector>
#include "concordance.h"
#include "bootstrap.h"
#include <QtCore>
#include <QTemporaryFile>
#include <QProcess>
#include <QFileDialog>
#include <QFile>


class Relatorio_paper
{
public:

    Relatorio_paper(std::vector<int> etrografia_1,
                                     std::vector<int> etrografia_2,
                                     std::vector<int> catalogo,
                                     int qnt_amostras);

    std::vector< Calculo_paper *>  varios_kappa;
    Calculo_paper *medido;
    QString txt_relatorio;

    void generate_relatorio();

};
void gera_relatorio_python(QString path, QString text);





QString creat_var(QString name, QString saida_ls);
QString creat_list(QList<QString> saida_ls);
QString generate_list_number_json(std::vector<int> ls_int);
QString creat_object(QList<QString> saida_ls);


#endif // RELATORIO_PAPER_H
