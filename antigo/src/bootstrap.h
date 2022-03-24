#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H
#include <vector>
#include <tuple>

class Bootstrap
{
public:
    Bootstrap(std::vector<int> etrografia_1, std::vector<int> etrografia_2, int s_rand=10);
    std::tuple<std::vector<int>, std::vector<int> > generate_new_etografia();
private:

    std::vector<int> original_1;
    std::vector<int> original_2;
    std::vector<std::tuple<int, int>> list_concordance;
};

#endif // BOOTSTRAP_H
