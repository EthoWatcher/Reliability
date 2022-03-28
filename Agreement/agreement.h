#ifndef AGREEMENT_H
#define AGREEMENT_H

#include "Agreement_global.h"
#include "./src/relatorio_paper.h"
#include "./src/ethowatcher.h"
#include <QtCore>
#include <QThread>
#include <QObject>

class AGREEMENT_EXPORT Agreement : public QThread
{
    Q_OBJECT
public:
//    explicit Agreement(QObject *parent =0);
    Agreement();

    void run() override {
            QString result;
            /* ... here is the expensive or blocking operation ... */
            relatorio->generate_relatorio();
            gera_relatorio_python(path, relatorio->txt_relatorio);
            emit finished();

//            emit resultReady(result);
        }


    Relatorio_paper *relatorio;
    QString path;

    QString generate_report(QString path,
                            std::vector<int> etrografia_1,
                            std::vector<int> etrografia_2,
                            std::vector<int> catalogo,
                            QList<QString> cata_name,
                            int qnt_reamostras,
                            int qnt_simpl, int qnt_simpl_boots);

    Etografia read_eto(QString path);
    std::vector<int> extrai_lista_quadros(Etografia eto);
    std::tuple<QList<QString> , std::vector<int> > get_catalogo(Etografia eto);
    std::vector< std::vector<int> > get_matrix_concordancia_cohen(std::vector<int> etografia_1, std::vector<int> etografia_2 , std::vector<int> catalogo );

    void processa();
public slots:
    void process();
    void chega_valor(int a);

signals:
    void qnt_bootstrap(int a);
    void finished();


};



#endif // AGREEMENT_H
