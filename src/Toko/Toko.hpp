#ifndef TOKO_HPP
#define TOKO_HPP

#include "../Item/Bangunan.hpp"
#include "../Item/Plant.hpp"

#include <iostream>

#include <map>
using namespace std;


// template <class T>
// void taruhBarang(T barang, vector<T> etalaseBarang){

// }
// template <class T>
// T ambilBarang(T barang, vector<T> etalaseBarang){

// }

class Toko {
  protected:
    map<string,int> stok;

  public:
    /*
    default ctor
    */
    Toko();
    // /*
    // Method untuk melakukan penjualan dengan objek yang memiliki tipe Bangunan
    // */
    // void titipJual(Bangunan el);
    // /*
    // Method untuk melakukan pembelian dengan objek yang memiliki tipe Bangunan
    // */
    // void mauBeli(Bangunan el);
    /*
    Mencetak tampilan toko ke dalam CLI
    */
    void welcome();
    // Virtual Function beli
    void beli();
    // Virtual Function jual
    void jual();
    // Get Stok
    map<string,int> getStok();

    void setStok(string Barang);
};

#endif
