#include "Player.hpp"
#include "Penyimpanan.hpp"
#include "../Toko/Toko.hpp"

class Petani : public Player, public Toko {

protected:
  Penyimpanan ladang;
  int jumlahBangunan;

public:
  Petani();
  float getPajak();

  void cetakLadang();
  void setUmurTanaman();

  // Virtual Function Toko
  void beli();
  void jual();

  void tanamTanaman();
  void panenTanaman();
};

// Catatan
// Petani dapat memanen dua kategori tanaman :
// 1. Material Plant
// 2. Fruit Plant