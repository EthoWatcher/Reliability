#include <QString>
#include <QtTest>

#include "ethowatcher.h"
#include "concordance.h"

#include <QApplication>
#include <QDir>

QString PATH_DATA = "C:/ethowatcher/biblioteca/data/";

class Teste_analise_concordanciaTest : public QObject
{
    Q_OBJECT

public:
    Teste_analise_concordanciaTest();

private Q_SLOTS:
    void testCase1();
    void testCase12();
    void criando_matriz();
};

Teste_analise_concordanciaTest::Teste_analise_concordanciaTest()
{
}

void Teste_analise_concordanciaTest::testCase1()
{
    QVERIFY2(false, "Failure for some reason");
}

void Teste_analise_concordanciaTest::testCase12()
{


//    Etografia eto_lida2 = lerETOXML(PATH_DATA + "1e3z1h4.etoxml");

    // essa opção vai crashar
    // fazer um teste somente com essa opção
    // Etografia eto_lida1 = lerETOXML("");


    //    QString nome_arquivo = abrindo_etografia();
    //    Etografia eto_lida = lerETOXML(nome_arquivo);

    QVERIFY2(true, "Failure");

}



void Teste_analise_concordanciaTest::criando_matriz(){
    // Dados extraídos de lehner.
    // F = 0, R =1, G= 2, W=3, A1=4, A2=5
    // {F, F, F, G, G, G, F, F, F, F, G, G, W, A1, A1, A1, G, A1, F, W, F, G, F, F, F, R, R, R, F, F}
    // {F, F, F, G, G, G, F, F, W, F, G, G, W, A2, A1, A1, G, A1, F, W, F, G ,F , F, F, R, R, R, F, F}
    std::vector<int> etrografia_1  = {0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 3, 4, 4, 4, 2, 4, 0, 3, 0, 2, 0, 0, 0, 1, 1, 1, 0, 0};
    std::vector<int> etrografia_2  = {0, 0, 0, 2, 2, 2, 0, 0, 3, 0, 2, 2, 3, 5, 4, 4, 2, 4, 0, 3, 0, 2 ,0 , 0, 0, 1, 1, 1, 0, 0};
    std::vector<int> catalogo  = {0, 1, 2, 3, 4, 5};

    auto matriz_concordancia = constroi_matrix_concordancia_cohen(etrografia_1, etrografia_2, catalogo);

    qDebug() << calcula_concordancia_acaso(matriz_concordancia);


}

QTEST_MAIN(Teste_analise_concordanciaTest)

#include "tst_teste_analise_concordanciatest.moc"
