#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "Item.hpp"

class Animal: public Item{
private:
    int id_hewan;
    int beratPanen;
    int harga;
public: 
    static int jumlahHewan;
    Animal(string,string,string,int,int);
};

#endif