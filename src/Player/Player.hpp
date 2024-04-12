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
    Player();
    Player(string username,int uang, int berat_badan, PetiRahasia data);
    void setUsername(string);
    void setBeratBadan(int);
    int getBeratBadan();
    string getPeran();
    void makan();
    
    virtual void printPlayer();
};

#endif