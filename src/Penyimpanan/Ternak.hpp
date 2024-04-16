#ifndef TERNAK_HPP
#define TERNAK_HPP

#include "Penyimpanan.hpp"
#include "../Item/Animal.hpp"

class Ternak : public Penyimpanan<Animal*> {
  public:
    /* Default Constructor */
    Ternak() : Penyimpanan<Animal*>() {}
    Ternak(int m, int n) : Penyimpanan<Animal*>(m, n) {}

    /* Cetak Ternak */
    void cetakPenyimpanan();
};

#endif