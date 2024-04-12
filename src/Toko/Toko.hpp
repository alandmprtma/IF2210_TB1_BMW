#ifndef TOKO_HPP
#define TOKO_HPP

#include "../Item/Bangunan.hpp"

#include <iostream>

#include <map>
using namespace std;


template <class T>
void taruhBarang(T barang, vector<T> etalaseBarang){

}
template <class T>
T ambilBarang(T barang, vector<T> etalaseBarang){

}

class Toko {
  protected:
    vector<Bangunan> etalaseBangunan;

  public:
    /*
    default ctor
    */
    Toko();
    /*
    Method untuk melakukan penjualan dengan objek yang memiliki tipe Bangunan
    */
    void titipJual(Bangunan el);
    /*
    Method untuk melakukan pembelian dengan objek yang memiliki tipe Bangunan
    */
    void mauBeli(Bangunan el);
    /*
    Mencetak tampilan toko ke dalam CLI
    */
    void welcome();
    // Virtual Function beli
    virtual void beli();
    // Virtual Function jual
    virtual void jual();

// class Toko {
//   private:
//     map<string,int> stok;
//   public:
//     Toko();
//     // key: nama bahan, value: jumlah stok
//     map<string,int> getStok();
//     void beli();
//     void jual();
// };
};

#endif