#include "GameStatus.hpp"


GameStatus::GameStatus(){
    playerTurnList = vector<Player*>();
    petaniList = vector<Petani>();
    peternakList = vector<Peternak>();
    walikota = Walikota();
    turn = 0;
    endGame = false;

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

bool GameStatus::getEndGame(){
    return endGame;
}

void GameStatus::nextTurn(){
    // TODO turn ++, umur ladang ++
}

void GameStatus::Inisiasi(){

    // TODO muat state.txt atau muat default
}

void GameStatus::cetakPenyimpanan(){
    
}

void GameStatus::pungutPajak(){

}