#include "GameObject.hpp"


GameObject::GameObject(){
    this->plantList = std::vector<Plant>();
    this->produkList = std::vector<Produk>();
    this->animalList = std::vector<Animal>();
    this->bangunanList = std::vector<Bangunan>();
}

std::vector<Plant> GameObject::getPlantList(){
    return this->plantList;
}
std::vector<Produk> GameObject::getProdukList(){
    return this->produkList;
}
std::vector<Animal> GameObject::getAnimalList(){
    return this->animalList;
}

std::vector<int> GameObject::getSizeInventory(){
    return this->sizeInventory;
}
std::vector<int> GameObject::getSizeCrops(){
    return this->sizeCrops;
}
std::vector<int> GameObject::getSizeFarm(){
    return this->sizeFarm;
}

int GameObject::getWinWeight(){
    return this->winWeight;
}
int GameObject::getWinGulden(){
    return this->winGulden;
}


std::vector<Bangunan> GameObject::getBangunanList(){
    return this->bangunanList;
}

int GameObject::stringToInt(string num) {
    int n = 0;
    bool foundDigit = false; // Menandakan apakah angka telah ditemukan dalam string
    for (size_t i = 0; i < num.size(); i++) {
        if (num[i] != ' ' && num[i] != '\n') {
            if (isdigit(num[i])) {
                n *= 10;
                n += num[i] - '0';
                foundDigit = true;
            } else if (foundDigit) {
                // Jika sudah menemukan angka dan karakter setelahnya bukan angka, berhenti loop
                break;
            }
        }
    }
    return n;
}

Plant GameObject::findPlant(string name){
    for (size_t i=0;i<plantList.size();i++){
        if (plantList[i].getNama() == name){
            return plantList[i];
        }
    }
    return Plant();
}
Animal GameObject::findAnimal(string name){
    for (size_t i=0;i<animalList.size();i++){
        if (animalList[i].getNama() == name){
            return animalList[i];
        }
    }
    return Animal();
}
Produk GameObject::findProduk(string name){
    for (size_t i=0;i<produkList.size();i++){
        if (animalList[i].getNama() == name){
            return produkList[i];
        }
    }
    return Produk();
}

void GameObject::muatTanaman(string pathTanaman){

        std::ifstream inputFile(pathTanaman);

        if (!inputFile.is_open()){

            throw FileNotFoundError();
            
        }else{
            
            std::vector<Plant> plantList = std::vector<Plant>();
            std::string line;

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
    
                std::getline(iss,token,' ');
                std::string tipe = token;

                std::getline(iss,token,' ');
                int durasiPanen = stringToInt(token);

                std::getline(iss,token,' ');
                int harga =  stringToInt(token);
            
                // simpan ke dalam list
                this->plantList.push_back(Plant(
                    kodeHuruf,
                    nama,
                    tipe,
                    durasiPanen,
                    harga
                ));

            }
            
        }

};

void GameObject::muatProduk(string pathProduk){
   std::ifstream inputFile(pathProduk);

        if (!inputFile.is_open()){

            throw FileNotFoundError();
            
        }else{
            
            std::vector<Plant> plantList = std::vector<Plant>();
            std::string line;

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

                std::getline(iss,token,' ');
                std::string tipe = token;

                std::getline(iss,token,' ');
                std::string orisinil = token;

                std::getline(iss,token,' ');
                int beratTambahan =  stringToInt(token);

                std::getline(iss,token,' ');
                int harga =  stringToInt(token);

                // simpan ke dalam list
                this->produkList.push_back(Produk(
                    kodeHuruf,
                    nama,
                    tipe,
                    orisinil,
                    beratTambahan,
                    harga
                ));

            }
            
        }
   
}

void GameObject::muatHewan(string pathHewan){

        std::ifstream inputFile(pathHewan);

        if (!inputFile.is_open()){

            throw FileNotFoundError();
            
        }else{
            
            std::vector<Animal> animalList = std::vector<Animal>();
            std::string line;

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
    
                std::getline(iss,token,' ');
                std::string tipe = token;

                std::getline(iss,token,' ');
                int beratPanen = stringToInt(token);

                std::getline(iss,token,' ');
                int harga =  stringToInt(token);
         
                // simpan ke dalam list
                this->animalList.push_back(Animal(
                    kodeHuruf,
                    nama,
                    tipe,
                    beratPanen,
                    harga
                ));

            }
            
        }

}

void GameObject::muatMisc(string pathMisc){
    std::ifstream inputFile(pathMisc);

        if (!inputFile.is_open()){

            throw FileNotFoundError();
            
        }else{
            std::string line;
            int lineNumber = 0;

            while (std::getline(inputFile, line)) {
                std::istringstream iss(line);
                std::string token;
                std::getline(iss,token,' ');
                if (token.empty()){
                    throw UndefinedSymbolError();
                }
                lineNumber++;
        // Perform different actions based on the line number
                switch(lineNumber) {
                    case 1:
                        this->winGulden = stringToInt(token);
                        // Perform action for line 1
                        break;
                    case 2:
                        this->winWeight = stringToInt(token);
                        // Perform action for line 2
                        break;
                    case 3:
                        this->sizeInventory.push_back(stringToInt(token));
                        std::getline(iss,token,' ');
                        if (token.empty()){
                            throw UndefinedSymbolError();
                        }
                        this->sizeInventory.push_back(stringToInt(token));
                        // Perform action for line 3
                        break;
                    case 4:
                        this->sizeCrops.push_back(stringToInt(token));
                        std::getline(iss,token,' ');
                        if (token.empty()){
                            throw UndefinedSymbolError();
                        }
                        this->sizeCrops.push_back(stringToInt(token));
                        // Perform action for line 4
                        break;
                    case 5:
                        this->sizeFarm.push_back(stringToInt(token));
                        std::getline(iss,token,' ');
                        if (token.empty()){
                            throw UndefinedSymbolError();
                        }
                        this->sizeFarm.push_back(stringToInt(token));
                        // Perform action for line 5
                        break;
                }
            }
        }

}

void GameObject::muatBangunan(string pathBangunan){

        std::ifstream inputFile(pathBangunan);

        if (!inputFile.is_open()){

            throw FileNotFoundError();
            
        }else{
            
            std::vector<Bangunan> bangunanList = std::vector<Bangunan>();
            std::string line;

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
                std::string namaBangunan = token;

                std::getline(iss,token,' ');
                int price = stringToInt(token);
                Bangunan temp(kodeHuruf, namaBangunan, price);
                
                while (true) {
                    std::getline(iss,token,' ');
                    std::string namaMaterial = token;;

                    std::getline(iss,token,' ');
                    int materialQuantity = stringToInt(token);
                    
                    temp.inputMaterial(namaMaterial, materialQuantity);
                    // Baca jumlah material
                    if (iss.peek() == '\n' || iss.peek() == EOF) {
                        break; // Jika berikutnya adalah newline atau akhir file, keluar dari loop
                    }
                }
                // simpan ke dalam list
                this->bangunanList.push_back(temp);
            }
        }

}