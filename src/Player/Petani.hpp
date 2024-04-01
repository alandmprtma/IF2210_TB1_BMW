#include "Player.hpp"
#include "../Toko/Toko.hpp"

class Petani : public Player, public Toko {

protected:
  Penyimpanan ladang;
  int jumlahBangunan;

public:
  Petani();

  void cetakLadang();
  void setUmurTanaman();

  // Virtual Function Toko
  void beli();
  void jual();



  int getPajak();

  void tanamTanaman();
  void panenTanaman();
};

// Catatan
// Petani dapat memanen dua kategori tanaman :
// 1. Material Plant
// 2. Fruit Plant