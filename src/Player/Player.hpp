#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Penyimpanan.hpp"
#include "../Item/Produk.hpp"
#include <iostream>

using namespace std;

#define DEFAULT_GULDEN 50
#define DEFAULT_BERAT_BADAN 40

class Player {
  protected:
    static int jumlahPlayer;

    int IdPlayer;
    string username;
    string peran;
    int uang;
    int berat_badan;
    // Penyimpanan<any> petiRahasia;

  public:
    Player();
    void setUsername(string);
    void setBeratBadan(int);
    int getBeratBadan();
    void makan();
    
    virtual void printPlayer();
};

#endif