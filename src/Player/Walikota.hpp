#include "Player.hpp"

class Walikota : public Player {
  private:
    int uangPajak;

  public:
    Walikota();

    void tagihPajak(int);
    void bangunBangunan();

    void addPetani();
    void addPeternak();
};