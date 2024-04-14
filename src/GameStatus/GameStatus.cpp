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
    turn = (turn + 1) % this->playerTurnList.size();
    for (size_t i=0;i<petaniList.size();i++){
        for (int j=0;j<objek.getSizeFarm()[0];j++){
            for (int k=0;k<objek.getSizeFarm()[1];k++){
                // set umur tiap tanaman = umur + 1, ntar ae dah
            }
        }
    }
}

void GameStatus::Inisiasi(GameObject objek){

    // TODO muat state.txt atau muat default
    
    int opsi;
    do{
        cout<<"Pilihlah cara memuat state permainan ! "<<endl;
        cout<<"1. Default"<<endl;
        cout<<"2. Membaca berkas"<<endl;
        cout<<"Masukkan opsi memulai game yang diinginkan ! "<<endl;
        cout<<"Opsi: ";
        cin>>opsi;
        if (opsi!= 1 && opsi != 2){
            cout<<"Opsi di luar jangkauan !"<<endl;
        }
    }while( opsi <=0 || opsi > 2);

    if (opsi==1){
        Petani petani = Petani("Petani1",50,40,
            PetiRahasia(objek.getSizeInventory()[0],objek.getSizeInventory()[1]),
            Ladang(objek.getSizeCrops()[0],objek.getSizeCrops()[1]),
            0
        );
        Peternak peternak = Peternak("Peternak1",50,40,
            PetiRahasia(objek.getSizeInventory()[0],objek.getSizeInventory()[1]),
            Ternak(objek.getSizeFarm()[0],objek.getSizeFarm()[1]),
            0
        );
        Walikota wal = Walikota("Walikota",50,40,
            PetiRahasia(objek.getSizeInventory()[0],objek.getSizeInventory()[1])
        );

        // store player
        this->walikota = wal;
        this->petaniList[petani.getId()] = petani;
        this->peternakList[peternak.getId()] = peternak;
        this->playerTurnList.push_back(&this->petaniList[petani.getId()]);
        this->playerTurnList.push_back(&this->peternakList[peternak.getId()]);
        this->playerTurnList.push_back(&this->walikota);
        
        // order player turn
        sort(this->playerTurnList.begin(),this->playerTurnList.end());

    }else if (opsi==2){
        // TODO command muat

    }
}

Player* GameStatus::getCurrentPlayer() const{
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
Walikota& GameStatus::getWalikota(){
    return this->walikota;
}


Player* GameStatus::getPlayer(int num){
    return playerTurnList[num];
}

int GameStatus::stringToInt(string num){
    cout<<"num: "<<num<<endl;
    cout<<"num_size: "<<num.size()<<endl;

    int n = 0;
    for (size_t i=0;num[i]>='0' && num[i]<='9';i++){
        n *= 10;
        n += num[i] - '0';
        cout<<n<<endl;

    }

    return n;
}
// A -> 1, B->2
int GameStatus::charToInt(string char1){
    return (int) char1[0] - 'A';
}
int GameStatus::charToInt(char char1){
    return (int) char1 - 'A';
}

void GameStatus::muat(string path, GameObject objek){

    std::ifstream inputFile(path);

    if (!inputFile.is_open()){

        throw FileNotFoundError();
        
    }else{
        
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
            int beratBadan = stringToInt(token);

            std::getline(iss,token,' ');
            int uang = stringToInt(token);

            // inventory
            

            if (tipe=="Petani"){
                cout<<"PETANI!"<<endl;
                std::getline(inputFile,line);
                PetiRahasia data = PetiRahasia(objek.getSizeInventory()[0],objek.getSizeInventory()[1]);
                int max = stringToInt(line);
                int i = 0;
                int j = 0;
                int jumlahBangunan = 0;
                while (max > 0)
                {
                    if (j==objek.getSizeInventory()[1]){
                        j=0;
                        i++;
                    }
                    std::getline(inputFile,line);
                    if (!(objek.findPlant(line)==Plant())){
                        data.setElement(new Plant(objek.findPlant(line)),i,j);
                    }else if (!(objek.findAnimal(line)==Animal())){
                        data.setElement(new Animal(objek.findAnimal(line)),i,j);
                    }else if (!(objek.findProduk(line)==Produk())){
                        data.setElement(new Produk(objek.findProduk(line)),i,j);
                    }else if (!(objek.findBangunan(line)==Bangunan())){
                        data.setElement(new Bangunan(objek.findBangunan(line)),i,j);
                        jumlahBangunan ++;
                    }
                    j++;
                    max--;
                }
                Ladang lad  = Ladang(objek.getSizeCrops()[0],objek.getSizeCrops()[1]);
                std::getline(inputFile,line);
                max = stringToInt(line);
                while (max>0)
                {
                    std::getline(inputFile,line);
                    std::istringstream iss(line);

                    std::getline(iss,token,' ');
                    int col = this->charToInt(token[0]);
                    int row = this->stringToInt(token.substr(1,token.size())) - 1;

                    std::getline(iss,token,' ');
                    lad.setElement(Plant(objek.findPlant(token)),row,col);
                    max--;
                }
                Petani pet = Petani(userName,uang,beratBadan,data,lad,jumlahBangunan);
                petaniList[pet.getId()] = pet;
                
            } else if (tipe=="Peternak"){
                cout<<"PETERNAK"<<endl;
                std::getline(inputFile,line);
                PetiRahasia data = PetiRahasia(objek.getSizeInventory()[0],objek.getSizeInventory()[1]);
                int max = stringToInt(line);
                int i = 0;
                int j = 0;
                int jumlahBangunan = 0;
                Ternak peternakan = Ternak(objek.getSizeFarm()[0],objek.getSizeFarm()[1]);
                while (max > 0)
                {
                    if (j==objek.getSizeInventory()[1]){
                        j=0;
                        i++;
                    }
                    std::getline(inputFile,line);
                    if (!(objek.findPlant(line)==Plant())){
                        data.setElement(new Plant(objek.findPlant(line)),i,j);
                    }else if (!(objek.findAnimal(line)==Animal())){
                        data.setElement(new Animal(objek.findAnimal(line)),i,j);
                    }else if (!(objek.findProduk(line)==Produk())){
                        data.setElement(new Produk(objek.findProduk(line)),i,j);
                    }else if (!(objek.findBangunan(line)==Bangunan())){
                        data.setElement(new Bangunan(objek.findBangunan(line)),i,j);
                        jumlahBangunan ++;
                    }
                    j++;
                    max--;
                }
                std::getline(inputFile,line);
                max = stringToInt(line);
                while (max>0)
                {
                    cout<<"max: "<<max<<endl;
                    std::getline(inputFile,line);
                    std::istringstream iss(line);

                    std::getline(iss,token,' ');
                    int col = this->charToInt(token[0]);
                    int row = this->stringToInt(token.substr(1,token.size())) - 1;
                    cout<<row<<" "<<col<<endl;

                    std::getline(iss,token,' ');
                    peternakan.setElement(Animal(objek.findAnimal(token)),row,col);
                    max--;
                }
                Peternak pet = Peternak(userName,uang,beratBadan,data,peternakan,jumlahBangunan);
                peternakList[pet.getId()] = pet;

            }else if (tipe=="Walikota"){
                cout<<"WALIKOTA"<<endl;
                std::getline(inputFile,line);
                PetiRahasia data = PetiRahasia(objek.getSizeInventory()[0],objek.getSizeInventory()[1]);
                int max = stringToInt(line);
                int i = 0;
                int j = 0;
                int jumlahBangunan = 0;
                Ternak peternakan;

                while (max > 0)
                {
                    if (j==objek.getSizeInventory()[1]){
                        j=0;
                        i++;
                    }
                    std::getline(inputFile,line);
                    if (!(objek.findPlant(line)==Plant())){
                        data.setElement(new Plant(objek.findPlant(line)),i,j);
                    }else if (!(objek.findAnimal(line)==Animal())){
                        data.setElement(new Animal(objek.findAnimal(line)),i,j);
                    }else if (!(objek.findProduk(line)==Produk())){
                        data.setElement(new Produk(objek.findProduk(line)),i,j);
                    }else if (!(objek.findBangunan(line)==Bangunan())){
                        data.setElement(new Bangunan(objek.findBangunan(line)),i,j);
                        jumlahBangunan ++;
                    }
                    j++;
                    max--;
                }
                this->walikota = Walikota(userName,uang,beratBadan,data);
            
            }else{            
                std::getline(inputFile,line);
                int max = stringToInt(line);
                string token;
                while (max > 0)
                {
                    std::getline(inputFile,line);
                    std::istringstream iss(line);

                    std::getline(iss,token,' ');
                    string nama = token;

                    std::getline(iss,token,' ');
                    int jumlah = stringToInt(token);

                    this->toko.getStok()[nama] = jumlah;
                    max--;
                }
            }
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
void GameStatus::bangunBangunan(string kodeHuruf, string namaBangunan, int price, int teak, int sandalwood, int aloe, int ironwood){
    int TeakWood = 0;
    int SandalWood = 0;
    int AloeWood = 0;
    int IronWood = 0;
    for(int i = 0; i < this->getCurrentPlayer()->getData().getM(); i++){
        for(int j = 0; j < this->getCurrentPlayer()->getData().getN(); j++){
            if(this->getCurrentPlayer()->getData().getElement(i,j)->getNama() == "TEAK_WOOD"){
                TeakWood++;
            }
            if(this->getCurrentPlayer()->getData().getElement(i,j)->getNama() == "SANDAL_WOOD"){
                SandalWood++;
            }
            if(this->getCurrentPlayer()->getData().getElement(i,j)->getNama() == "SANDAL_WOOD"){
                AloeWood++;
            }
            if(this->getCurrentPlayer()->getData().getElement(i,j)->getNama() == "SANDAL_WOOD"){
                IronWood++;
            }
        }
    }
    this->getWalikota().setTeakWood(TeakWood);
    this->getWalikota().setSandalWood(SandalWood);
    this->getWalikota().setAloeWood(AloeWood);
    this->getWalikota().setIronWood(IronWood);
    this->getWalikota().bangunBangunan(kodeHuruf, namaBangunan, price, teak, sandalwood, aloe, ironwood);
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