#include "Player.hpp"
#include "../Bangunan/Bangunan.hpp"
#include <vector>

class Walikota : public Player {
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