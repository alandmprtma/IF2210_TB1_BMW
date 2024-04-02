#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
using namespace std;

template <class T>
class Toko {
  public:
    Toko();

    virtual void beli() = 0; // Pure Virtual Function
    virtual void jual() = 0; // Pure Virtual Function
};

#endif