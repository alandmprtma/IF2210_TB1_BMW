#include "GameStatus.hpp"


GameStatus::GameStatus(){
    playerTurnList = vector<Player*>();
    petaniList = map<int,Petani>();
    peternakList = map<int,Peternak>();
    walikota = Walikota();
    turn = 0;
    endGame = false;

}

bool GameStatus::isEndGame(){
    return endGame;
}

void GameStatus::nextTurn(){
    // TODO turn ++, umur ladang ++
}

void GameStatus::Inisiasi(){
    // TODO muat state.txt atau muat default
}


int GameStatus::stringToInt(string num){

    int n = 0;
    for (int i=0;i<num.size();i++){

        n *= 10;
        n += num[i] - '0';

    }

    return n;
}

void GameStatus::muat(string path, GameObject objek){

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
                PetiRahasia data;
                int max = stringToInt(line);
                int i = 0;
                int j = 0;
                while (max > 0)
                {
                    if (j==objek.getSizeInventory()[1]){
                        j==0;
                        i++;
                    }
                    
                    j++;
                    max--;
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
void GameStatus::cetakPenyimpanan(){

}
void GameStatus::pungutPajak(){

}
void GameStatus::cetakLadang(){

}
void GameStatus::cetakPeternakan(){

}
void GameStatus::tanam(){

}
void GameStatus::ternak(){

}
void GameStatus::bangunBangunan(){

}
void GameStatus::makan(){

}
void GameStatus::memberiPangan(){

}
void GameStatus::membeli(){

}
void GameStatus::menjual(){

}
void GameStatus::memanen(){

}