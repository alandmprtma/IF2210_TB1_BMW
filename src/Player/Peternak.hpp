#include "Player.hpp"
#include "../Item/Animal.hpp"
#include "../Toko/Toko.hpp"

class Peternak : public Player, public Toko
{
protected:
  Penyimpanan<Animal> ternak;
  int jumlahBangunan;

public:
  Peternak();
  float getPajak();

  // Virtual Function Toko
  void beli();
  void jual();

  void simpanHewanTernak();
  void kasihMakanHewanTernak();

  void panenTernak();
};
