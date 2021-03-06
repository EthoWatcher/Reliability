#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H
#include <vector>
#include <tuple>
#include <QDebug>
#include <QRandomGenerator>

class Bootstrap
{
public:
    Bootstrap(std::vector<int> etrografia_1, std::vector<int> etrografia_2, int s_rand=10);
    std::tuple<std::vector<int>, std::vector<int> > generate_new_etografia();
private:

    std::vector<int> original_1;
    std::vector<int> original_2;
    std::vector<std::tuple<int, int>> list_concordance;
    QRandomGenerator gen1;
};


class Bootstrap_2{
public:
    Bootstrap_2(std::vector<std::vector<int>> ls_etografias, int qnt_valores_por_etogrfia, int s_rand=10);
    std::tuple<std::vector<int>, std::vector<int> > generate_new_etografia();
    std::vector<std::tuple<int, int>> list_concordance;

private:
    std::vector<std::vector<int>> gera_list_combi(std::vector<int> l_centr);
    QRandomGenerator gen1;


    int qnt_valores_por_etogrfia;

    std::vector<std::vector<int>> ls_combinacoes_etografia_2;


};


class Bootstrap_mult_videos{

public:
    Bootstrap_mult_videos(QList<Bootstrap_2> ls_ml_videos, int qnt_valores_por_etogrfia, int s_rand=10);
    std::tuple<std::vector<int>, std::vector<int> > generate_new_etografia();
    std::vector<std::tuple<int, int>> list_concordance;
private:
    int qnt_valores_por_etogrfia;
    QRandomGenerator gen1;
    QList<Bootstrap_2> ls_ml_videos;



};


#endif // BOOTSTRAP_H
