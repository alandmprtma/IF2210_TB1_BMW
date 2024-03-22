#include "Player.hpp"

class Walikota : public Player {
  private:
    static int jumlahWalikota;

  public:
    Walikota();

    void pungutPajak();
    void bangunBangunan();

    void addPetani();
    void addPeternak();
};