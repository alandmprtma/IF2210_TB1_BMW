#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "../Item/Plant.hpp"
#include "../Item/Produk.hpp"
#include "../Item/Animal.hpp"
#include "../Item/Bangunan.hpp"
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
    std::vector<Animal> animalList;
    std::vector<Bangunan> bangunanList;
    

public:
    
    GameObject();
    void muatTanaman(string pathTanaman);
    void muatProduk(string pathProduk);
    void muatHewan(string pathHewan);
    void muatBangunan(string pathBangunan);
    int stringToInt(string num);
    std::vector<Plant> getPlantList();
    std::vector<Produk> getProdukList();
    std::vector<Animal> getAnimalList();
    std::vector<Bangunan> getBangunanList();
};



#endif