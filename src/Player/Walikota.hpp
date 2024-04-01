#include "Player.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Toko/Toko.hpp"
#include <vector>

class Walikota : public Player, public Toko {
  private:
    int uangPajak;
    Bangunan bangunan;

  public:
    Walikota();

    void pungutPajak();
    void bangunBangunan();

    // Virtual Function Toko
    void beli();
    void jual();

    void addPetani();
    void addPeternak();
};