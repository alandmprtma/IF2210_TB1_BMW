#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "../Item/Plant.hpp"
#include "../Item/Produk.hpp"
#include "../Exception/Exception.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


class GameObject{

private:
    std::vector<Plant> plantList;
    std::vector<Produk> produkList;
    

public:
    
    GameObject();
    void muatTanaman(string pathTanaman);
    void muatProduk(string pathProduk);
    int stringToInt(string num);
    std::vector<Plant> getPlantList();
    std::vector<Produk> getProdukList();

};



#endif