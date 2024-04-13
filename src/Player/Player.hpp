#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../Penyimpanan/PetiRahasia.hpp"
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
    PetiRahasia data;

  public:
    /* Constructor */
    Player();
    Player(string username,int uang, int berat_badan, PetiRahasia data);
    
    /* Setter Username */
    void setUsername(string);

    /* Setter Berat Badan */
    void setBeratBadan(int);

    /* Getter Peran */
    string getPeran();

    /* Getter Berat Badan */
    int getBeratBadan();

    /* Getter Peti Rahasia */
    PetiRahasia getPetiRahasia();

    /* 
    Fungsi Makan. 
    Player dapat memakan dari inventorynya.
    Jumlah berat badan yang ditambahkan bergantung pada makanan yang dimakan.
    */
    void makan();
    
    /* Mencetak Data Player */
    virtual void printPlayer();
};

#endif