#ifndef PRODUK_HPP
#define PRODUK_HPP
#include "Item.hpp"

class Produk : Item{
private:
    int id_produk;
    string orisinil;
    int beratTambahan;
    int harga;
public:
    static int jumlahProduk;
    Produk(string,string,string,string,int,int);
};
#endif