#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>

#include <map>
using namespace std;


class Toko {
  private:
    map<string,int> stok;
  public:
    Toko();
    // key: nama bahan, value: jumlah stok
    map<string,int> getStok();
    void beli();
    void jual();
};

#endif