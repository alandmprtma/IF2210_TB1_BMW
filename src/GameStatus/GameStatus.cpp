#include "GameStatus.hpp"


GameStatus::GameStatus(){
    petaniList = map<int,Petani>();
    peternakList = map<int,Peternak>();
    walikota = Walikota();
    endGame = false;

}

void GameStatus::turn(){
    
}
std::map<int,Petani> GameStatus::getPetaniList(){
    return petaniList;
}
std::map<int,Peternak> GameStatus::getPeternakList(){
    return peternakList;
}
Walikota GameStatus::getWalikota(){
    return walikota;
}
Petani GameStatus::getPetani(int id){
    return petaniList[id];
}
Peternak GameStatus::getPeternak(int id){
    return peternakList[id];
}
