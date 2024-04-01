#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Penyimpanan.hpp"
#include "../Item/Produk.hpp"
#include <iostream>
#include <any>
using namespace std;

class Player {
protected:
  static int jumlahPlayer;

  int IdPlayer;
  string username;
  string peran;
  int uang;
  int berat_badan;
  Penyimpanan<any> petiRahasia;

  public:
  Player();
  void setUsername(string);
  void setBeratBadan(int);
  int getBeratBadan();
  void makan();
};

#endif