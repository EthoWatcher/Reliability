#include <QString>
#include <QtTest>


#include "ethowatcher.h"
#include "concordance.h"
#include <QApplication>
#include <QDir>

// add necessary includes here
QString PATH_DATA = "C:/Doutorado_softwares/Reliability/data/"; //variavel global.
QString PATH_TESTE = "C:/Doutorado_softwares/saida_teste/";


class test_concordancia : public QObject
{
    Q_OBJECT

public:
    test_concordancia();
    ~test_concordancia();

private slots:
    void test_case1();
//    void testCase1();
//    void testCase12();
    void criando_matriz();
//    void teste_parser();
    void teste_calculo_vies();
    void teste_calculo_prevalencia();
    void teste_calculo_kappa_maximo();
    void teste_calculo_por_categoria();
//    void construindo_lista_dados();
    void test_gera_matrix_22();
    void test_gera_matrix_22_pela_categoria();

//    void test_gera_lista_quador();
//    void test_fless_kappa();
//    void test_integracao_cohen();
    void test_artigo_dados();


};

test_concordancia::test_concordancia()
{

}

test_concordancia::~test_concordancia()
{

}

void test_concordancia::test_case1()
{
//    QVERIFY2(false, "Failure for some reason");
}


//void test_concordancia::testCase12()
//{
//    //     adicionar para que encontre o arquivo.
//        Etografia eto_lida2 = lerETOXML("../data/1e3z1h4.etoxml");

//        // essa opção vai crashar
//        // fazer um teste somente com essa opção
//        // Etografia eto_lida1 = lerETOXML("");


//        //    QString nome_arquivo = abrindo_etografia();
//        //    Etografia eto_lida = lerETOXML(nome_arquivo);

//        QVERIFY2(true, "Failure");
//}

//void test_concordancia::construindo_lista_dados(){

//    Etografia eto_lida2 = lerETOXML("../data/1e3z1h4.etoxml");
//    Etografia eto_lida3 = lerETOXML("../data/1e3z1h4.etoxml");

//    std::vector<int> catalogo  =  eto_lida2.catalogo->id;

//    // funcao para gerar uma tripa de dados para colocar na matrix de concordancia.
//    // pegar os elementos
//    //frameFinal - anota o ponto final
//    //frameInicial - anota o ponto inicial
//    //id  - lista que tem o id marcado
//    // {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3 ....
//    //{0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 3, 4, 4, 4, 2, 4, 0, 3, 0, 2, 0, 0, 0, 1, 1, 1, 0, 0}


////    auto matriz_concordancia = constroi_matrix_concordancia_cohen(eto_lida2, eto_lida3,catalogo);
//    qDebug() << "saida";
//}

// uma função para construir a estrutura de dados.

void test_concordancia::test_gera_matrix_22(){
    // colocar os dados gerados
    std::vector<int> etrografia_1  = {0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 3, 4, 4, 4, 2, 4, 0, 3, 0, 2, 0, 0, 0, 1, 1, 1, 0, 0};
    std::vector<int> etrografia_2  = {0, 0, 0, 2, 2, 2, 0, 0, 3, 0, 2, 2, 3, 5, 4, 4, 2, 4, 0, 3, 0, 2 ,0 , 0, 0, 1, 1, 1, 0, 0};
    std::vector<int> catalogo  = {0, 1, 2, 3, 4, 5};

    std::vector<std::vector<int> > matrix_concordance_nn = constroi_matrix_concordancia_cohen(etrografia_1, etrografia_2, catalogo);
    std::vector<std::vector<int> > matrix_22 = gera_matrix_22(matrix_concordance_nn);


    qDebug() << matrix_22;

}


void test_concordancia::test_gera_matrix_22_pela_categoria(){
    std::vector<int> etrografia_1  = {0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 3, 4, 4, 4, 2, 4, 0, 3, 0, 2, 0, 0, 0, 1, 1, 1, 0, 0};
    std::vector<int> etrografia_2  = {0, 0, 0, 2, 2, 2, 0, 0, 3, 0, 2, 2, 3, 5, 4, 4, 2, 4, 0, 3, 0, 2 ,0 , 0, 0, 1, 1, 1, 0, 0};
    std::vector<int> catalogo  = {0, 1, 2, 3, 4, 5};

    std::vector<std::vector<int> > matrix_22_cat2 = gera_matrix_22_pela_categoria(etrografia_1, etrografia_2, catalogo, 2);


    qDebug() << matrix_22_cat2;

}

//void test_concordancia::test_gera_lista_quador()
//{
//    Etografia eto_lida2 = lerETOXML(PATH_DATA + "1e3z1h4.etoxml");
//    std::vector<int> si = _constroi_lista_quadros(eto_lida2);

//}


//void test_concordancia::teste_parser()
//{
//    Etografia etografia1 = lerETOXML("caminho da etografia");
//    std::vector<int> etrografia_1  = extrai_lista_quadro_quadro(etografia1);
//    Etografia etografia2 = lerETOXML("caminho da etografia");
//    std::vector<int> etrografia_2  = extrai_lista_quadro_quadro(etografia2);

//    // checar se as etografias possuem o mesmo catalogo.

//    std::vector<int> catalogo = extrai_catalogo(etografia1);
//    auto matriz_concordancia = constroi_matrix_concordancia_cohen(etrografia_1, etrografia_2, catalogo);


//    qDebug() << calcula_concordancia_acaso(matriz_concordancia);
//}

void test_concordancia::criando_matriz()
{
    std::vector<int> etrografia_1  = {0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 3, 4, 4, 4, 2, 4, 0, 3, 0, 2, 0, 0, 0, 1, 1, 1, 0, 0};
    std::vector<int> etrografia_2  = {0, 0, 0, 2, 2, 2, 0, 0, 3, 0, 2, 2, 3, 5, 4, 4, 2, 4, 0, 3, 0, 2 ,0 , 0, 0, 1, 1, 1, 0, 0};
    std::vector<int> catalogo  = {0, 1, 2, 3, 4, 5};

    auto matriz_concordancia = constroi_matrix_concordancia_cohen(etrografia_1, etrografia_2, catalogo);


    float concordancia_acaso = calcula_concordancia_acaso(matriz_concordancia);
    float concordancia_observada = calcula_concordancia_observada(matriz_concordancia);

//    float kappa_medio = calcula_kappa_medio(matriz_concordancia);


    qDebug() << calcula_concordancia_acaso(matriz_concordancia);


}
void test_concordancia::teste_calculo_por_categoria(){
    std::vector<std::vector<int>> vetor_entrada= {{29,21},{23,27}};
    float concordancia_categoria_1 = calculo_por_categoria(vetor_entrada);
    //qDebug() <<viez_categoria;


}

void test_concordancia::teste_calculo_vies(){
    std::vector<std::vector<int>> vetor_entrada= {{29,21},{23,27}};
    float viez_categoria = calculo_vies_categoria(vetor_entrada);
    qDebug() <<viez_categoria;


}

void test_concordancia::teste_calculo_prevalencia(){
    std::vector<std::vector<int>> vetor_entrada= {{29,21},{23,27}};
    float prevalencia_categoria = calculo_prevalencia_categoria(vetor_entrada);
    qDebug() <<prevalencia_categoria;


}

void test_concordancia::teste_calculo_kappa_maximo(){
    std::vector<std::vector<int>> vetor_entrada= {{2,1},{7,50}};
    std::vector<std::vector<int>> kappa_maximo_matrix = arruma_matrix_kappa_maximo(vetor_entrada);
//    qDebug() <<10;

}

//void test_concordancia::test_fless_kappa(){
//    Etografia eto_lida2 = lerETOXML(PATH_DATA + "1e3z1h4.etoxml");
//    Etografia eto_lida3 = lerETOXML(PATH_DATA + "1e3z1h4.etoxml");

//    Concordance_Fleiss calculado_fless;

//    calculado_fless.add_arquivos_etografia(eto_lida2);
//    calculado_fless.add_arquivos_etografia(eto_lida2);
//    calculado_fless.add_arquivos_etografia(eto_lida3);

//    QString texto = calculado_fless.text_fleiss_concordancia();
//    calculado_fless.gravar_csv(PATH_TESTE+"teste_fleiss.csv", texto);


//}

//void test_concordancia::test_integracao_cohen()
//{
//  Concordance_Cohen cohen;
//  Etografia eto_lida1 = lerETOXML(PATH_DATA + "1e3z1h4.etoxml");
//  Etografia eto_lida2 = lerETOXML(PATH_DATA + "1e3z1h4.etoxml");

//  QString saida = cohen.carrega_etografia(eto_lida1, eto_lida2 );

//  cohen.gravar_csv(PATH_TESTE+"teste_cohen.csv", saida);
//}

//struct concordanci{

//};


void test_concordancia::test_artigo_dados()
{
    //0 - swimming
    //1 - climbimg
    //2 - Immobility
    std::vector<int> etrografia_1  = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
    std::vector<int> etrografia_2  = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2};
    std::vector<int> catalogo  = {0, 1, 2};

    auto matriz_concordancia = constroi_matrix_concordancia_cohen(etrografia_1, etrografia_2, catalogo);


    float concordancia_acaso = calcula_concordancia_acaso(matriz_concordancia);
    float concordancia_observada = calcula_concordancia_observada(matriz_concordancia);
    float kappa_catalogo = calcula_kappa_medio(matriz_concordancia);
    qDebug() << "Concordancia Cohone catalogo "<< matriz_concordancia << "concordancia acaso: " << concordancia_acaso << "concordancia observada: " << concordancia_observada << "Kappa: " << kappa_catalogo;


    std::vector<std::vector<int> > matrix_22_swimming = gera_matrix_22_pela_categoria(etrografia_1, etrografia_2, catalogo, 0);
    float viez_swimming = calculo_vies_categoria(matrix_22_swimming);
    float prevalencia_swimming = calculo_prevalencia_categoria(matrix_22_swimming);
    float kappa_swimming = calcula_kappa_medio(matrix_22_swimming);
    qDebug() << "Swimming \n" << matrix_22_swimming << "Vies: " << viez_swimming << "Prevalencia: " << prevalencia_swimming << "Kappa: " << kappa_swimming;

    std::vector<std::vector<int>> kappa_maximo_matrix = arruma_matrix_kappa_maximo(matrix_22_swimming);
    float viez_max_swimming = calculo_vies_categoria(kappa_maximo_matrix);
    float prevalencia_max_swimming = calculo_prevalencia_categoria(kappa_maximo_matrix);
    float kappa_max_swimming = calcula_kappa_medio(kappa_maximo_matrix);
    qDebug() << "Swimming max \n" << kappa_maximo_matrix << "Vies: " << viez_max_swimming << "Prevalencia: " << prevalencia_max_swimming << "Kappa: " << kappa_max_swimming;



//    std::vector<std::vector<int> > matrix_22_climbimg = gera_matrix_22_pela_categoria(etrografia_1, etrografia_2, catalogo, 1);


//    std::vector<std::vector<int> > matrix_22_Immobility = gera_matrix_22_pela_categoria(etrografia_1, etrografia_2, catalogo, 2);


//    float kappa_medio = calcula_kappa_medio(matriz_concordancia);


//    qDebug() << calcula_concordancia_acaso(matriz_concordancia


}



QTEST_MAIN(test_concordancia)

#include "tst_test_concordancia.moc"
