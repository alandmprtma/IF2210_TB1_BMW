#ifndef PRODUK_HPP
#define PRODUK_HPP
#include "Item.hpp"

#define DEFAULT_ID_PRODUK -1
#define DEFAULT_ORISINIL_PRODUK "@#$"
#define DEFAULT_BERAT_TAMBAHAN -1
#define DEFAULT_HARGA -1

class Produk : public Item{
private:
    int id_produk;
    string orisinil;
    int beratTambahan;
    int harga;
public:
    static int jumlahProduk;
    Produk();
    Produk(string,string,string,string,int,int);
    int getIdProduk();
    string getOrisinil();
    int getBeratTambahan();
    int getHarga();
};
#endif