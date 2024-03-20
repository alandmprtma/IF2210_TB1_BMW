#include "Player.hpp"

class Peternak : public Player {
  private:
    static int jumlah_peternak;

  public:
    Peternak();

    void simpanHewanTernak();
    void kasihMakanTernak();
    void ambilHasilTernak();
};