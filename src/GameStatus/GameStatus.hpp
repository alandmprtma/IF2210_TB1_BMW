#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP


#include "../Player/Petani.hpp"
#include "../Player/Peternak.hpp"
#include "../Player/Walikota.hpp"
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
    Walikota walikota;
    int turn;
    // Toko
    bool endGame;
public:
    GameStatus();
    Walikota getWalikota();
    Petani getPetani(int id);
    Peternak getPeternak(int id);
    
    void muatStatus(string path);
    int stringToInt(string num);


    bool getEndGame();
    void nextTurn();
    void Inisiasi();
    void cetakPenyimpanan();
    void pungutPajak();
    
};

#endif