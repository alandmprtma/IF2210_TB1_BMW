#ifndef PLANT_HPP
#define PLANT_HPP
#include "Item.hpp"

#define DEFAULT_ID_TANAMAN -1
#define DEFAULT_DURASI_PANEN -1
#define DEFAULT_HARGA -1
#define DEFAULT_UMUR -1

class Plant: public Item{
protected:
    int id_tanaman;
    int durasiPanen;
    int harga;
    int umur;
public: 
    static int jumlahTanaman;

    Plant();
    Plant(const Plant& other);
    Plant(string,string,string,int,int);
    int getIdTanaman() const;
    int getDurasiPanen() const;
    int getHarga() const;
    int getUmur() const;
    void setUmur(int x);
    string getTanamanNameByID(int);
    bool operator==(const Plant& other);
    Plant& operator=(const Plant& other);
};

#endif