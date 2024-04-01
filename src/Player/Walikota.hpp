#include "Player.hpp"
#include "../Bangunan/Bangunan.hpp"
#include <vector>

class Walikota : public Player {
  private:
    int uangPajak;
    Bangunan bangunan;

  public:
    Walikota();

    void tagihPajak(int);
    void bangunBangunan();

    void addPetani();
    void addPeternak();
};