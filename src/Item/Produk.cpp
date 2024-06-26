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
Produk::Produk():Item(),
id_produk(DEFAULT_ID_PRODUK),orisinil(DEFAULT_ORISINIL_PRODUK),beratTambahan(DEFAULT_BERAT_TAMBAHAN),harga(DEFAULT_HARGA)
{
    
}
int Produk::getBeratTambahan(){
    return beratTambahan;
}
int Produk::getHarga(){
    return harga;
}
int Produk::getIdProduk(){
    return id_produk;
}
string Produk::getOrisinil(){
    return orisinil;
}
bool Produk::operator==(const Produk& other){
     return  this->kodeHuruf == other.kodeHuruf &&
                this->harga == other.harga &&
                this->nama == other.nama &&
                this->tipe == other.tipe;
}
