#ifndef CONCORDANCE_H
#define CONCORDANCE_H
#include <vector>
#include "ethowatcher.h"


using namespace  std;
#include <QXmlStreamWriter>
#include <QFileDialog>
#include <algorithm>

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

    Etografia eto1;
    Etografia eto2;

};

std::vector<std::vector<int> > gera_matrix_22_pela_categoria(std::vector<int> etrografia_1, std::vector<int> etrografia_2, std::vector<int> catalogo, int id_categ);
std::vector<std::vector<int> > gera_matrix_22(std::vector<std::vector<int> > matrix_nn);




std::vector< std::vector<int> > constroi_matrix_concordancia_cohen(std::vector<int> etografia_1, std::vector<int> etografia_2, std::vector<int> catalogo);
float calcula_concordancia_observada(std::vector< std::vector<int> > matriz_concordancia);
float calcula_concordancia_acaso(std::vector< std::vector<int> > matriz_concordancia);
float calculo_vies_categoria(std::vector<std::vector<int> > matiz_concordancia_22);
float calculo_prevalencia_categoria(std::vector<std::vector<int> > matiz_concordancia_22);
std::vector<std::vector<int> > arruma_matrix_kappa_maximo(std::vector<std::vector<int> > matiz_concordancia_22);
float calculo_por_categoria(std::vector<std::vector<int> > matiz_concordancia_22);



float transforma_matris_nn_22();




// Calculo da concordancia

class Concordance_Fleiss{

public:
    Concordance_Fleiss();

    void add_arquivos_etografia(Etografia eto_grafia);
    QString text_fleiss_concordancia();
    void gravar_csv(QString path_eto, QString t_saida);

private:
    void calculo_concordancia();
    double calcularPI(std::vector<int> entrada, double qnt_de_TCC);
    double calcularPJ(std::vector<int> entrada, double qntd_videos, double qnt_quadros);

    //guarda a lista de etografias para a análise.
    std::vector< dadosVideo *> dadosDosVideos;
    std::vector< analiseEtografica *> etografiaDosVideos;
    std::vector< catalago *> catalagoDosVideos;
    std::vector< Etografia *> list_etografias;
    int quantidadeDeVideo;


    std::vector< analiseEtografica *> etografiaKoho;
    std::vector< dadosVideo *> videosKoho;
    std::vector< catalago *> catalagoKoho;


    std::vector<std::vector< std::vector<int> > > anaEtoDosVideos;
    std::vector<int> frameFleisLinha;

    //SAIDA ?
    std::vector< std::vector<int> > frameFleisTabela;
    std::vector<double> PIcalculados;
    std::vector<double> PJcalculados;
    double Pe;
    double P_medio;
    double Kappa;


//    void grava_xml_analise(QString caminho_arquivo);
//    void grava_csv_analise(QString caminho_arquivo);

};





#endif // CONCORDANCE_H
