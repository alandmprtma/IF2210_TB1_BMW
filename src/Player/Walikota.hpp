#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "Player.hpp"
#include "../Item/Bangunan.hpp"
// #include "../Toko/Toko.hpp"
#include "../Exception/Exception.hpp"
#include <vector>

#define DEFAULT_TEAK_WOOD 0
#define DEFAULT_SANDAL_WOOD 0
#define DEFAULT_ALOE_WOOD 0
#define DEFAULT_IRONWOOD 0

class Walikota : public Player{
  protected:
    vector<Bangunan> bangunan;
    int TeakWood;
    int SandalWood;
    int AloeWood;
    int IronWood;

  public:
    Walikota();
    void pungutPajak();
    void bangunBangunan(string kodeHuruf,string namaBangunan, int price, int TeakTree, int SandalwoodTree, int AloeTree, int IronwoodTree);
    void pakaiMaterial (int, int, int, int, int);
    void tambahGulden(int num);
    void tambahTeakWood(int num);
    void tambahSandalWood(int num);
    void tambahAloeWood(int num);
    void tambahIronWood(int num);
    void addPetani();
    void addPeternak();
    void jual();
    void beli();
};

#endif