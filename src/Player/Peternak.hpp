#include "Player.hpp"
#include "../Toko/Toko.hpp"

class Peternak : public Player, public Toko
{
private:
  static int jumlahPeternak; // ID Peternak
  // AreaInventory peternakan;

protected:
  Penyimpanan ternak;
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
  void cetakPeternakan();
};
