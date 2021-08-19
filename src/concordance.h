#ifndef CONCORDANCE_H
#define CONCORDANCE_H
#include <vector>
#include "ethowatcher.h"


using namespace  std;
#include <QXmlStreamWriter>
#include <QFileDialog>

class Concordance_Cohen
{
public:
    Concordance_Cohen();

    void carrega_etografia(Etografia eto1, Etografia eto2);
    void grava_xml_analise(QString caminho_arquivo);
    void grava_csv_analise(QString caminho_arquivo);

private:
    void calculo_concordancia();
    void le_xml_analise(QString caminho_arquivo);

};


std::vector< std::vector<int> > constroi_matrix_concordancia_cohen(std::vector<int> etografia_1, std::vector<int> etografia_2, std::vector<int> catalogo);
float calcula_concordancia_observada(std::vector< std::vector<int> > matriz_concordancia);
float calcula_concordancia_acaso(std::vector< std::vector<int> > matriz_concordancia);
float calculo_vies_categoria(std::vector<std::vector<int> > matiz_concordancia_22);
float calculo_prevalencia_categoria(std::vector<std::vector<int> > matiz_concordancia_22);
float calculo_kappa_maximo(std::vector<std::vector<int> > matiz_concordancia_22);
float calculo_por_categoria(std::vector<std::vector<int> > matiz_concordancia_22);


float transforma_matris_nn_22();




// Calculo da concordancia

class Concordance_Fleiss{

public:
    Concordance_Fleiss();

private:
    void calculo_concordancia();

//    void grava_xml_analise(QString caminho_arquivo);
//    void grava_csv_analise(QString caminho_arquivo);

};





#endif // CONCORDANCE_H
