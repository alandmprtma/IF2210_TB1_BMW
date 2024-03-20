#include "Player.hpp"

class Petani : public Player {
  private:
    static int jumlah_petani;

  public:
    Petani();

    void tanamTanaman();
    void panenTanaman();
};