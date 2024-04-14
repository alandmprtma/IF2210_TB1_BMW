#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "Item.hpp"

#define DEFAULT_ID_HEWAN -1
#define DEFAULT_BERAT_PANEN -1
#define DEFAULT_HARGA -1
#define NULL_ANIMAL Animal()

class Animal: public Item{
private:
    int id_hewan;
    int beratPanen;
    int harga;
    int berat;
public: 
    Animal();
    Animal(const Animal& other);
    Animal(string,string,string,int,int);
    int getHarga()const;
    int getBeratPanen()const;
    int getId_Hewan()const;
    int getBerat()const;
    void setBerat(int x);
    static int jumlahHewan;
    bool operator==(const Animal&);
    Animal&  operator=(const Animal&);
};

#endif