#include <QString>
#include <QtTest>


#include "ethowatcher.h"
#include "concordance.h"
#include <QApplication>
#include <QDir>

// add necessary includes here
QString PATH_DATA = "C:/Doutorado_softwares/Reliability/data/"; //variavel global.


class test_concordancia : public QObject
{
    Q_OBJECT

public:
    test_concordancia();
    ~test_concordancia();

private slots:
    void test_case1();
//    void testCase1();
    void testCase12();
    void criando_matriz();
//    void teste_parser();
    void teste_calculo_vies();
    void teste_calculo_prevalencia();
    void teste_calculo_kappa_maximo();



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


void test_concordancia::testCase12()
{
    //     adicionar para que encontre o arquivo.
        Etografia eto_lida2 = lerETOXML(PATH_DATA + "1e3z1h4.etoxml");

        // essa opção vai crashar
        // fazer um teste somente com essa opção
        // Etografia eto_lida1 = lerETOXML("");


        //    QString nome_arquivo = abrindo_etografia();
        //    Etografia eto_lida = lerETOXML(nome_arquivo);

        QVERIFY2(true, "Failure");
}



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
    std::vector<std::vector<int>> vetor_entrada= {{29,21},{23,27}};
    float kappa_maximo = calculo_kappa_maximo(vetor_entrada);
    qDebug() <<kappa_maximo;


}

QTEST_MAIN(test_concordancia)

#include "tst_test_concordancia.moc"
