#include "Produk.hpp"

// Static variable Init
int Produk::jumlahProduk = 0;

// constructor
Produk::Produk(string kodeHuruf,string nama,string tipe,string orisinil,int beratTambahan,int harga): Item(kodeHuruf,nama,tipe),
    orisinil(orisinil), beratTambahan(beratTambahan),harga(harga)
    {
        jumlahProduk += 1;
        id_produk = jumlahProduk;
    }