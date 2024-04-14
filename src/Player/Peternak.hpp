#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Player.hpp"
#include "../Item/Animal.hpp"
#include "../Toko/Toko.hpp"
#include "../Penyimpanan/Ternak.hpp"
#include "../Item/Produk.hpp"
#include "../GameObject/GameObject.hpp"

class Peternak : public Player, public Toko {
  protected:
    int jumlahBangunan;

  public:
    Ternak dataTernak;
    
    /* Constructor */
    Peternak();
    Peternak(string username,int uang, int berat_badan, PetiRahasia data,Ternak dataTernak, int jumlahBangunan);

    /* Fungsi Menyimpan Hewan Ternak */
    void simpanTernak();

    /* Fungsi Memberi Makan Hewan Ternak */
    void beriMakanHewanTernak(GameObject);

    /* Fungsi Panen Ternak */
    void panenTernak();

    /* Getter Ternak */
    Ternak getTernak();

    /* Getter Pajak */
    float getPajak();

    /* Mencetak Data Player */
    void printPlayer();

    /* Virtual Function Toko. Fungsi Jual Beli*/
    void jual();
    void beli();
};

#endif