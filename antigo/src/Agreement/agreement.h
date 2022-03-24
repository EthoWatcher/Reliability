#ifndef AGREEMENT_H
#define AGREEMENT_H

#include "Agreement_global.h"
#include "../relatorio_paper.h"
class AGREEMENT_EXPORT Agreement
{
public:
    Agreement();
    QString generate_report(QString path);
};

#endif // AGREEMENT_H
