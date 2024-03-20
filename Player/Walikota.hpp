#include "Player.hpp"

class Walikota : public Player {
  private:
    static int jumlah_walikota;

  public:
    Walikota();

    void tagihPajak();
    void bangunBangunan();

    void addPetani();
    void addPeternak();
};