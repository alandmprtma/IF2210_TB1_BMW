#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP


#include "../Player/Petani.hpp"
#include "../Player/Peternak.hpp"
#include "../Player/Walikota.hpp"
#include <iostream>
#include <map>


class GameStatus{

private:
    std::vector<Player*> playerTurnList;
    std::vector<Petani> petaniList;
    std::vector<Peternak> peternakList;
    Walikota walikota;
    int turn;
    // Toko
    bool endGame;
public:
    GameStatus();
    Walikota getWalikota();
    Petani getPetani(int id);
    Peternak getPeternak(int id);
    
    bool getEndGame();
    void nextTurn();
    void Inisiasi();
    void cetakPenyimpanan();
    void pungutPajak();
    
};

#endif