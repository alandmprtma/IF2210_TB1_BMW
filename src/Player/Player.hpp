
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../GameObject/GameObject.hpp"
#include "../Penyimpanan/PetiRahasia.hpp"
#include "../Exception/Exception.hpp"
#include <regex>
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
    
    /* Validator */
    bool isKosong();

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


    /* 
    Fungsi Makan. 
    Player dapat memakan dari inventorynya.
    Jumlah berat badan yang ditambahkan bergantung pada makanan yang dimakan.
    */
    void makan(GameObject);
    void isElementNull(int i, int j);
    void isElementNotProduct(int i, int j);
    void isPenyimpananHaveProduct();
    void isIndexValid(int i, int j, int baris, int kolom);
    
    /* Mencetak Data Player */
    virtual void printPlayer();
};

#endif