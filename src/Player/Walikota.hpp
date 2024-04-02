#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "Player.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Toko/Toko.hpp"
#include <vector>

class Walikota : public Player, public Toko {
  protected:
    int uangPajak;
    Bangunan bangunan;

  public:
    Walikota();
    void pungutPajak();
    void bangunBangunan();
    void addPetani();
    void addPeternak();

    void jual();
    void beli();
};

#endif