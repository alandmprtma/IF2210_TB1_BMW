#ifndef PLANT_HPP
#define PLANT_HPP
#include "Item.hpp"

class Plant: public Item{
private:
    int id_tanaman;
    int durasiPanen;
    int harga;
    int umur;
public: 
    static int jumlahTanaman;

    Plant();
    string getTanamanNameByID(int);
    Plant(string,string,string,int,int);
    int getIdTanaman();
    int getDurasiPanen();
    int getHarga();
    int getIdTanaman();
    int getUmur();
    void setUmur(int x);

};

#endif