#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../GameObject/GameObject.hpp"
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

  public:
    PetiRahasia data;
    
    /* Constructor */
    Player();
    Player(string username,int uang, int berat_badan, PetiRahasia data);
    
    /* Setter Username */
    void setUsername(string);
    string getUsername();
    PetiRahasia& getData();
    int getUang();
    void setUang(int);

    int getId();

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