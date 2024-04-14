#ifndef LADANG_HPP
#define LADANG_HPP

#include "Penyimpanan.hpp"
#include "../Item/Plant.hpp"

class Ladang : public Penyimpanan<Plant*> {
  public:
    /* Default Constructor */
    Ladang() : Penyimpanan<Plant*>() {}
    Ladang(int m, int n) : Penyimpanan<Plant*>(m, n) {}

    /* Cetak Ladang */
    void cetakLadang(string);
};

#endif