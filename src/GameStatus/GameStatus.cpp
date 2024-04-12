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

void GameStatus::nextTurn(GameObject objek){
    // TODO turn ++, umur ladang ++
    turn ++;
    for (size_t i=0;i<petaniList.size();i++){
        for (int j=0;j<objek.getSizeFarm()[0];j++){
            for (int k=0;k<objek.getSizeFarm()[1];k++){
                // set umur tiap tanaman = umur + 1, ntar ae dah
            }
        }
    }
}

void GameStatus::Inisiasi(){
    // TODO muat state.txt atau muat default
}

Player* GameStatus::getCurrentPlayer(){
    if (this->playerTurnList.empty()){
        throw NoPLayerException();
    }
    return playerTurnList[turn];
}
Petani GameStatus::getPetani(string username){
    if (this->petaniList.empty()){
        throw NoPetaniException();
    }
    for (size_t i=0;i<petaniList.size();i++){
        if (petaniList[i].getUsername()==username){
            return petaniList[i];
        }
    }
    return Petani();
}
Peternak GameStatus::getPeternak(string username){
    if (this->peternakList.empty()){
        throw NoPeternakException();
    }
    for (size_t i=0;i<peternakList.size();i++){
        if (peternakList[i].getUsername()==username){
            return peternakList[i];
        }
    }
    return Peternak();
}
Walikota GameStatus::getWalikota(){
    return this->walikota;
}

int GameStatus::stringToInt(string num){

    int n = 0;
    for (size_t i=0;i<num.size();i++){

        n *= 10;
        n += num[i] - '0';

    }

    return n;
}
// A -> 1, B->2
int GameStatus::charToInt(string char1){
    return char1[0] - 64;
}
int GameStatus::charToInt(char char1){
    return char1 - 64;
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
                        j=0;
                        i++;
                    }
                    std::getline(inputFile,line);
                    if (!(objek.findPlant(line)==Plant())){
                        pet.getData().setElement(&Plant(objek.findPlant(line)),i,j);
                    }else if (!(objek.findAnimal(line)==Animal())){
                        pet.getData().setElement(&Animal(objek.findAnimal(line)),i,j);
                    }else if (!(objek.findProduk(line)==Produk())){
                        pet.getData().setElement(&Produk(objek.findProduk(line)),i,j);
                    }
                    j++;
                    max--;
                }
                std::getline(inputFile,line);
                max = stringToInt(line);
                while (max>0)
                {
                    std::getline(inputFile,line);
                    std::istringstream iss(line);

                    std::getline(iss,token,' ');
                    int col = this->charToInt(token[0]) - 1;
                    int row = this->stringToInt(token.substr(1,token.size())) - 1;

                    std::getline(iss,token,' ');
                    pet.getLadang().setElement(Plant(objek.findPlant(token)),row,col);
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

void GameStatus::simpan(string path, GameObject objek){

}
void GameStatus::tambahPemain(){
    
}