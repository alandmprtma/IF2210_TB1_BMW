#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>

#include <map>
using namespace std;


class Toko {
  public:
    Toko();
    // key: nama bahan, value: jumlah stok
    map<string,int> stok;
    void beli();
    void jual();
};

#endif