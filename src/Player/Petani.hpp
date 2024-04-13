#ifndef PETANI_HPP
#define PETANI_HPP

#include "Player.hpp"
#include "../Item/Plant.hpp"
#include "../Toko/Toko.hpp"
#include "../Penyimpanan/Ladang.hpp"

class Petani : public Player, public Toko {
  protected:
    Ladang dataLadang;
    int jumlahBangunan;

  public:
    /* Constructor */
    Petani();
    Petani(string username,int uang, int berat_badan, PetiRahasia data, Ladang dataLadang, int jumlahBangunan);
    
    /* Fungsi Menanam Tanaman */
    void tanamTanaman();

    /* Fungsi Panen Tanaman */
    void panenTanaman();

    /* Setter Umur Tanaman */
    void setUmurTanaman(int, int);

    /* Getter Ladang */
    Ladang getLadang();

    /* Getter Pajak */
    float getPajak();

    /* Mencetak Data Player */
    void printPlayer();

    /* Virtual Function Toko. Fungsi Jual Beli*/
    void beli();
    void jual();
};

#endif