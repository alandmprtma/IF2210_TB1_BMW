#include "Player.hpp"

class Petani : public Player
{
private:
  static int jumlahPetani; // ID Petani
  // AreaInventory ladang;

protected:
  int jumlahBangunan;

public:
  Petani();
  int getPajak();

  void tanamTanaman();
  void panenTanaman();
  void cetakLadang();
};