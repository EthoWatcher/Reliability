#ifndef AGREEMENT_H
#define AGREEMENT_H

#include "Agreement_global.h"
#include "./src/relatorio_paper.h"
class AGREEMENT_EXPORT Agreement
{
public:
    Agreement();
    QString generate_report(QString path,
                            std::vector<int> etrografia_1,
                            std::vector<int> etrografia_2,
                            std::vector<int> catalogo,
                            QList<QString> cata_name
                            );
};

#endif // AGREEMENT_H
