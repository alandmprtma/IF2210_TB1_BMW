#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP


#include "../Penyimpanan/Penyimpanan.hpp"
#include "../Player/Petani.hpp"
#include "../Player/Peternak.hpp"
#include "../Player/Walikota.hpp"
#include "../Toko/Toko.hpp"
#include "../GameObject/GameObject.hpp"
#include "../Exception/Exception.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>


class GameStatus{

private:
    std::vector<Player*> playerTurnList;
    std::map<int,Petani> petaniList;
    std::map<int,Peternak> peternakList;
    Toko toko;
    Walikota walikota;
    int turn;
    // Toko
    bool endGame;
public:
    GameStatus();
    
    int stringToInt(string num);
    int charToInt(string char1);
    int charToInt(char char1);

    Player* getCurrentPlayer() const;
    Player* getPlayer(int);
    Petani getPetani(string username);
    Peternak getPeternak(string username);
    Walikota& getWalikota();


    bool isEndGame();
    void nextTurn(GameObject objek);
    void Inisiasi(GameObject);
    void cetakPenyimpanan();
    void pungutPajak();
    void cetakLadang();
    void cetakPeternakan();
    void tanam();
    void ternak();
     void bangunBangunan(string kodeHuruf, string namaBangunan, int price, int teak, int sandalwood, int aloe, int ironwood);
    void makan();
    void memberiPangan();
    void membeli();
    void menjual();
    void memanen();
    void muat(string path,GameObject objek);
    void simpan(string path, GameObject objek);
    void tambahPemain();
    
};

#endif