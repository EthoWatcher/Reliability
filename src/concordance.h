#ifndef CONCORDANCE_H
#define CONCORDANCE_H
#include <vector>

using namespace  std;

class concordance
{
public:
    concordance();
};


std::vector< std::vector<int> > constroi_matrix_concordancia_cohen(std::vector<int> etografia_1, std::vector<int> etografia_2, std::vector<int> catalogo);
float calcula_concordancia_observada(std::vector< std::vector<int> > matriz_concordancia);
float calcula_concordancia_acaso(std::vector< std::vector<int> > matriz_concordancia);
float calculo_vies_categoria(std::vector<std::vector<int> > matiz_concordancia_22);
float calculo_prevalencia_categoria(std::vector<std::vector<int> > matiz_concordancia_22);
float calculo_kappa_maximo(std::vector<std::vector<int> > matiz_concordancia_22);
float calculo_por_categoria(std::vector<std::vector<int> > matiz_concordancia_22);



#endif // CONCORDANCE_H
