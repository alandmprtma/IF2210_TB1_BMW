#ifndef PETANI_HPP
#define PETANI_HPP

#include "Player.hpp"
#include "../Item/Plant.hpp"
#include "../Toko/Toko.hpp"
#include "../Penyimpanan/Ladang.hpp"
#include "../Item/Produk.hpp"
#include "../GameObject/GameObject.hpp"

class Petani : public Player, public Toko {
  protected:
    int jumlahBangunan;

  public:
    Ladang dataLadang;

    /* Constructor */
    Petani();
    Petani(string username,int uang, int berat_badan, PetiRahasia data, Ladang dataLadang, int jumlahBangunan);
    
    /* Fungsi Menanam Tanaman */
    void tanamTanaman();

    /* Fungsi Panen Tanaman */
    void panenTanaman(GameObject);

    /* Setter Umur Tanaman */
    void tambahUmurTanaman(int, int, int);

    /* Getter Ladang */
    Ladang &getLadang();

    /* Getter Pajak */
    float getPajak();

    /* Mencetak Data Player */
    void printPlayer();

    /* Virtual Function Toko. Fungsi Jual Beli*/
    void beli();
    void jual();
};

#endif