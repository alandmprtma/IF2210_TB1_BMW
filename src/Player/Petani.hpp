#include "Player.hpp"
#include "../Item/Plant.hpp"
#include "../Toko/Toko.hpp"

class Petani : public Player, public Toko {

protected:
  Penyimpanan<Plant> ladang;
  int jumlahBangunan;

public:
  Petani();
  float getPajak();
  void setUmurTanaman();
  void tanamTanaman();
  void panenTanaman();

  // Virtual Function Toko
  void beli();
  void jual();
};