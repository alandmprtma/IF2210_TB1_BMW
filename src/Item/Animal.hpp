#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "Item.hpp"

class Animal: public Item{
private:
    int id_hewan;
    int beratPanen;
    int harga;
    int berat;
public: 
    static int jumlahHewan;
    Animal(string,string,string,int,int);
    int getHarga();
    int getBeratPanen();
    int getId_Hewan();
    int getBerat();
    void setBerat(int x);
};

#endif