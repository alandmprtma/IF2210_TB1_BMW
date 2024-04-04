#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
using namespace std;

#include "../Penyimpanan/PetiRahasia.hpp"
#include "../Item/Item.hpp"

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
    Player();
    void setUsername(string);
    void setBeratBadan(int);
    int getBeratBadan();
    void makan();
    
    virtual void printPlayer();
};

#endif