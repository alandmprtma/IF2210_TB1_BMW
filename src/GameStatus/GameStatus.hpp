#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP


#include "../Penyimpanan/Penyimpanan.hpp"
#include "../Player/Petani.hpp"
#include "../Player/Peternak.hpp"
#include "../Player/Walikota.hpp"
#include "../Toko/Toko.hpp"
#include "../GameObject/GameObject.hpp"
#include "../Exception/Exception.hpp"
#include <limits>
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
    std::vector<Petani> petaniList;
    std::vector<Peternak> peternakList;
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
    int getNumPlayers();

    Player* getCurrentPlayer() const;
    Player* getPlayer(int);
    Petani& getPetani(string username);
    int getIndeksPetani(string username);
    void setPetani(int indeks, Petani p);
    Peternak& getPeternak(string username);
    int getIndeksPeternak(string username);
    void setPeternak(int indeks, Peternak p);
    Walikota& getWalikota();
    Toko& getToko();
    void lexicographicSort();

    void CurrentPlayerValidation(string);
    bool isEndGame(GameObject objek);
    void nextTurn(GameObject objek);
    void Inisiasi(GameObject);
    void cetakPenyimpanan();
    void pungutPajak(GameObject&);
    void cetakLadang();
    void cetakPeternakan();
    void tanam();
    void ternak();
    void bangunBangunan(string kodeHuruf, string namaBangunan, int price, int teak, int sandalwood, int aloe, int ironwood);
    void makan(GameObject&);
    void memberiPangan();
    void membeli();
    void menjualWalikota(GameObject game_object);
    void menjualPeternak(string nama, GameObject game_object);
    void menjualPetani(string nama, GameObject game_object);
    void memanen(GameObject objek);
    void muat(string path,GameObject objek);
    void simpan(string path, GameObject objek);
    void tambahPemain(GameObject objek);
    void surrend();
};

#endif