#include "Player.hpp"

class Peternak : public Player
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