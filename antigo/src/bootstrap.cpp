#include "bootstrap.h"
#include <random>
#include <time.h>

Bootstrap::Bootstrap(std::vector<int> etrografia_1, std::vector<int> etrografia_2, int s_rand)
{
    this->original_1 = etrografia_1;
    this->original_2 = etrografia_2;

    for(int i=0; i< etrografia_1.size(); i++){
        this->list_concordance.push_back( std::tuple<int, int>(etrografia_1[i], etrografia_2[i]) );
    }
    //tem que ver qual é a melhor solução, uma o srand
//    std::srand(s_rand);
//    srand (time(NULL));


}


std::tuple< std::vector<int>, std::vector<int> > Bootstrap::generate_new_etografia(){
//     std::simple_rand.seed(42);
     int r_list[original_1.size()];
     std::vector<int>  nova_eto_1; //[original_1.size()];
     std::vector<int>  nova_eto_2;


     for (int i=0; i< int(original_1.size()) ; i++){
         r_list[i]= 0 + (std::rand() % this->original_1.size() );
     }

     for(int i=0; i< int(original_1.size()); i++){
        int x_rand = r_list[i];
        nova_eto_1.push_back( std::get<0>(this->list_concordance[x_rand]));
        nova_eto_2.push_back( std::get<1>(this->list_concordance[x_rand]));
     }

     std::tuple< std::vector<int>, std::vector<int> >  novas_etografias = std::tuple< std::vector<int>, std::vector<int> > (nova_eto_1, nova_eto_2);
     return  novas_etografias;




}
