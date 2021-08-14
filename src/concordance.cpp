#include "concordance.h"
#include <numeric>
#include <math.h>
concordance::concordance()
{
}




std::vector< std::vector<int> > constroi_matrix_concordancia_cohen(std::vector<int> etografia_1, std::vector<int> etografia_2 , std::vector<int> catalogo ){

      int matrix_size = catalogo.size();
      std::vector< std::vector<int> > matriz_concordancia = std::vector<std::vector<int>>(matrix_size, std::vector<int>(matrix_size));

    for(int quadro_da_analise = 0; quadro_da_analise < etografia_1.size(); quadro_da_analise++){
        int  marcacao_1 = etografia_1[quadro_da_analise];
        int  marcacao_2 = etografia_2[quadro_da_analise];

        matriz_concordancia[marcacao_2][marcacao_1] = matriz_concordancia[marcacao_2][marcacao_1] +1;

    }

    return matriz_concordancia;


}


float calcula_concordancia_observada(std::vector<std::vector<int> > matriz_concordancia)
{

    auto conta_quantidade_quadros = [&]() -> int {
            int contador_dados = 0;
            for (auto linha: matriz_concordancia){
                for(auto elemento: linha){

                    contador_dados = contador_dados +elemento;
                }
            }

            return contador_dados;
            };

    auto conta_quadros_concordante= [&]() -> int {
            int contador_pos_linha = 0;
            int qnt_quadros_concordante = 0;
            for (auto linha: matriz_concordancia){
                int contador_pos_coluna = 0;
                for(auto elemento: linha){
                    bool r_diagonal = contador_pos_coluna == contador_pos_linha;

                    if(r_diagonal){
                        qnt_quadros_concordante = qnt_quadros_concordante + elemento;
                    }

                contador_pos_coluna++;
                }

            contador_pos_linha++;
            }

            return qnt_quadros_concordante;
        };


    int quant_quadros_marcados = conta_quantidade_quadros();
    int quant_quadros_concordante =conta_quadros_concordante() ;

    float proporcao_concordancia_observada = (float) quant_quadros_concordante/ (float) quant_quadros_marcados;
    return proporcao_concordancia_observada;
}

float calcula_concordancia_acaso(std::vector<std::vector<int> > matriz_concordancia){

    auto conta_quantidade_quadros = [](std::vector<std::vector<int> > matriz_concordancia ) -> int {
            int contador_dados = 0;
            for (auto linha: matriz_concordancia){
                for(auto elemento: linha){

                    contador_dados = contador_dados +elemento;
                }
            }

                return contador_dados;
            };

    auto conta_quantidade_linha = [&]() -> std::vector<float> {
        int qnt_elementos =conta_quantidade_quadros(matriz_concordancia);
        std::vector<float> qnt_linha;
        for (auto linha: matriz_concordancia){
            float qnt_elementos_linha=0;
            qnt_elementos_linha = accumulate(linha.begin(), linha.end(), qnt_elementos_linha);
            qnt_linha.push_back(qnt_elementos_linha/qnt_elementos);
        }
       return qnt_linha;

    };

    auto conta_quantidade_coluna = [&]() -> std::vector<float>{
       int qnt_elementos = conta_quantidade_quadros(matriz_concordancia);
       std::vector<float> qnt_coluna;

       int i_coluna = 0;
        for (auto linha: matriz_concordancia){
            float soma_coluna = 0;
            for(auto linha:matriz_concordancia){
                soma_coluna = soma_coluna + linha[i_coluna];
            }
          qnt_coluna.push_back(soma_coluna/ qnt_elementos);
          i_coluna++;
        }


      return qnt_coluna;
    };

//    int quant_quadros_marcados = conta_quantidade_quadros();
    std::vector<float> soma_linha = conta_quantidade_linha();
    std::vector<float> soma_coluna = conta_quantidade_coluna();
    float concordancia_ao_acaso =0;
    for(int i=0; i< soma_coluna.size(); i++){
       float n1 = soma_linha[i];
       float n2 = soma_linha[i];
       concordancia_ao_acaso = concordancia_ao_acaso + (n1* n2);

    }



    return concordancia_ao_acaso;

}

float calcula_kappa_medio(std::vector<std::vector<int> > matriz_concordancia){
    // Gian implementar o calculo do kappa medio



    float acaso = calcula_concordancia_acaso(matriz_concordancia);
    float concordancia = calcula_concordancia_observada(matriz_concordancia);
    float kappa = (concordancia - acaso)/(1 - acaso);

    return kappa;


}

//

// matriz de confusão nxn e temos que converter numa matriz de confusão 2x2
// do comportamento e diferente do comportamento
// calular o kappa por categoria
// calcular a prevalencia por categoria - OK
// calcular o vies por categoria - OK
// calcular o kappa maximo. - OK
// the Kappa Statistic in Reliability Studies: Use, Interpretation, and Sample Size Requirements
float calculo_por_categoria(std::vector<std::vector<int> > matriz_concordancia_22)// apenas para matrizes 2x2
{
    float n_1 = matriz_concordancia_22[0][0] + matriz_concordancia_22[0][1] + matriz_concordancia_22[1][0];
    float n_2 = matriz_concordancia_22[1][1] + matriz_concordancia_22[0][1] + matriz_concordancia_22[1][0];
    float dividendo_1 = matriz_concordancia_22[0][0];
    float dividendo_2 = matriz_concordancia_22[1][1];


    float agreement_1 = (float) dividendo_1/n_1;
    float agreement_2 = (float) dividendo_2/n_2;
}

float calculo_vies_categoria(std::vector<std::vector<int> > matriz_concordancia_22)
{
    float n = matriz_concordancia_22[0][0] + matriz_concordancia_22[0][1] + matriz_concordancia_22[1][0] + matriz_concordancia_22[1][1];
    float dividendo = fabs(matriz_concordancia_22[0][1] - matriz_concordancia_22[1][0]);
    float vies = (float) dividendo/n;
    return vies;
}


float calculo_prevalencia_categoria(std::vector<std::vector<int> > matriz_concordancia_22)
{
    float n = matriz_concordancia_22[0][0] + matriz_concordancia_22[0][1] + matriz_concordancia_22[1][0] + matriz_concordancia_22[1][1];
    float dividendo = fabs(matriz_concordancia_22[0][0] - matriz_concordancia_22[1][1]);
    float prevalencia = (float) dividendo/n;
    return prevalencia;
}
float calculo_kappa_maximo(std::vector<std::vector<int> > matriz_concordancia_22)
{
    float n = matriz_concordancia_22[0][0] + matriz_concordancia_22[0][1] + matriz_concordancia_22[1][0] + matriz_concordancia_22[1][1];
    float dividendo = matriz_concordancia_22[0][0] + matriz_concordancia_22[1][1];
    float kappa_maximo = (float) dividendo/n;
}
