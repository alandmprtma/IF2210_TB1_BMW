#ifndef MUAT_HPP
#define MUAT_HPP

#include "../Item/Plant.hpp"
#include "../Exception/Exception.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


class Muat{

protected:

    std::vector<Plant> plantList;

public:

    std::vector<Plant> muatTanaman(string pathTanaman);
    int stringToInt(string num);

};



#endif