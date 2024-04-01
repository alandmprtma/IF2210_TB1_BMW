#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP


#include "../Player/Penyimpanan.hpp"
#include "../Player/Petani.hpp"
#include "../Player/Peternak.hpp"
#include "../Player/Walikota.hpp"
#include <iostream>
#include <map>


class GameStatus{

private:
    std::map<int,Petani> petaniList;
    std::map<int,Peternak> peternakList;
    Walikota walikota;
public:
    GameStatus();
    std::map<int,Petani> getPetaniList();
    std::map<int,Peternak> getPeternakList();
    Walikota getWalikota();
    Petani getPetani(int id);
    Peternak getPeternak(int id);
    
};

#endif