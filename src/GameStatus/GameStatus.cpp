#include "GameStatus.hpp"


GameStatus::GameStatus(){
    playerTurnList = vector<Player*>();
    petaniList = map<int,Petani>();
    peternakList = map<int,Peternak>();
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

int GameStatus::stringToInt(string num){

    int n = 0;
    for (int i=0;i<num.size();i++){

        n *= 10;
        n += num[i] - '0';

    }

    return n;
}

void GameStatus::muatStatus(string path){

    std::ifstream inputFile(path);

    if (!inputFile.is_open()){

        throw FileNotFoundError();
        
    }else{
        
        std::vector<Plant> plantList = std::vector<Plant>();
        std::string line;

        std::getline(inputFile,line);
        for (int i=0;i<stringToInt(line);i++){

            std::getline(inputFile,line);
            std::istringstream iss(line);

            std::string token;
            std::getline(iss,token,' ');
            std::string userName = token;

            std::getline(iss,token,' ');
            std::string tipe = token;

            std::getline(iss,token,' ');
            std::string beratBadan = token;

            std::getline(iss,token,' ');
            std::string uang = token;

            // inventory
            

            if (tipe=="Petani"){
                Petani pet = Petani();
                std::getline(inputFile,line);
                
                for (int j=0;j<stringToInt(line);j++){
                    
                }


            }

        }
        while (std::getline(inputFile,line))
        {   

            std::istringstream iss(line);
            // parse string dipisah spasi
            
            // skip id
            std::string token;
            std::getline(iss,token,' ');
            
            std::getline(iss,token,' ');
            if (token.empty()){
                throw UndefinedSymbolError();
            }
            std::string kodeHuruf = token;

            std::getline(iss,token,' ');
            std::string nama = token;


        }
        
    }
}