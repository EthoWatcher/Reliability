#include "agreement.h"

Agreement::Agreement()
{
}

QString Agreement::generate_report(QString path,
                                   std::vector<int> etrografia_1,
                                   std::vector<int> etrografia_2,
                                   std::vector<int> catalogo,
                                   QList<QString> cata_name
                                   )
{
//    qDebug() << "report";

//    std::vector<int> etrografia_1  = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
//    std::vector<int> etrografia_2  = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2};
//    std::vector<int> catalogo  = {0, 1, 2};
//    QList<QString> cata_name = {"swimming",
//                                 "climbimg",
//                                 "Immobility"};
////    0 - swimming
////    1 - climbimg
////    2 - Immobility
    Relatorio_paper relatorio = Relatorio_paper(etrografia_1,
                                                etrografia_2,
                                                catalogo,
                                                cata_name,
                                                1000);

    relatorio.generate_relatorio();




    gera_relatorio_python(path, relatorio.txt_relatorio);


    return relatorio.txt_relatorio;

}
