#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Player.hpp"
#include "../Item/Animal.hpp"
#include "../Toko/Toko.hpp"
#include "../Penyimpanan/Ternak.hpp"

class Peternak : public Player, public Toko {
  protected:
    Ternak dataTernak;
    int jumlahBangunan;

  public:
    Peternak();
    Peternak(string username,int uang, int berat_badan, PetiRahasia data,Ternak dataTernak, int jumlahBangunan);
    float getPajak();
    void simpanHewanTernak();
    void kasihMakanHewanTernak();
    void panenTernak();

    void printPlayer();

    void jual();
    void beli();
};

#endif