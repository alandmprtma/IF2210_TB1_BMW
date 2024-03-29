#include "Player.hpp"

class Peternak : public Player
{
private:
  static int jumlahPeternak; // ID Peternak
  // AreaInventory peternakan;

protected:
  int jumlahBangunan;

public:
  Peternak();
  float getPajak();

  void simpanHewanTernak();
  void kasihMakanHewanTernak();

  void panenTernak();
  void cetakPeternakan();
};