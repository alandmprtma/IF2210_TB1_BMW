#ifndef MUAT_HPP
#define MUAT_HPP

#include "../Item/Plant.hpp"
#include "../Item/Produk.hpp"
#include "../Item/Animal.hpp"
#include "../Exception/Exception.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


class Muat{

private:
    std::vector<Plant> plantList;
    std::vector<Produk> produkList;
    std::vector<Animal> animalList;
    

public:
    
    Muat();
    void muatTanaman(string pathTanaman);
    void muatProduk(string pathProduk);
    void muatHewan(string pathHewan);
    int stringToInt(string num);
    std::vector<Plant> getPlantList();
    std::vector<Produk> getProdukList();
    std::vector<Animal> getAnimalList();

};



#endif