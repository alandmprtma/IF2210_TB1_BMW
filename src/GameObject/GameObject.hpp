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
    int winWeight;
    int winGulden;
    std::vector<int> sizeInventory;
    std::vector<int> sizeCrops;
    std::vector<int> sizeFarm;
    std::vector<Bangunan> bangunanList;
    
    
public:
    
    GameObject();
    void muatTanaman(string pathTanaman);
    void muatProduk(string pathProduk);
    void muatHewan(string pathHewan);
    void muatMisc(string pathMisc);
    void muatBangunan(string pathBangunan);
    int stringToInt(string num);
    std::vector<Plant> getPlantList();
    std::vector<Produk> getProdukList();
    std::vector<Animal> getAnimalList();
    int getWinWeight();
    int getWinGulden();
    std::vector<int> getSizeInventory();
    std::vector<int> getSizeCrops();
    std::vector<int> getSizeFarm();
    std::vector<Bangunan> getBangunanList();
    
    Plant findPlant(string name);
    Animal findAnimal(string name);
    Produk findProduk(string name);

};



#endif