#ifndef PETANI_HPP
#define PETANI_HPP

#include "Player.hpp"
#include "../Item/Plant.hpp"
#include "../Toko/Toko.hpp"
#include "../Penyimpanan/Ladang.hpp"

class Petani : public Player, public Toko {
  protected:
    Ladang dataLadang;
    int jumlahBangunan;

  public:
    Petani();
    Petani(string username,int uang, int berat_badan, PetiRahasia data, Ladang dataLadang, int jumlahBangunan);
    float getPajak();
    void setUmurTanaman();
    void tanamTanaman();
    void panenTanaman();

    void printPlayer();

    void beli();
    void jual();
};

#endif