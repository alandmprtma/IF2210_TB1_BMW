#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Player.hpp"
#include "../Item/Animal.hpp"
#include "../Toko/Toko.hpp"

class Peternak : public Player, public Toko {
  protected:
    // Penyimpanan<Animal> ternak;
    int jumlahBangunan;

  public:
    Peternak();
    float getPajak();
    void simpanHewanTernak();
    void kasihMakanHewanTernak();
    void panenTernak();

    void printPlayer();

    void jual();
    void beli();
};

#endif