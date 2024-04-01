#ifndef PLANT_HPP
#define PLANT_HPP
#include "Item.hpp"

class Plant: public Item{
private:
    int id_tanaman;
    int durasiPanen;
    int harga;
public: 
    static int jumlahTanaman;
    Plant(string,string,string,int,int);
    int getIdTanaman();
    int getDurasiPanen();
    int getHarga();
};

#endif