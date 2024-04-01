#include "GameObject.hpp"


GameObject::GameObject(){
    this->plantList = std::vector<Plant>();
    this->produkList = std::vector<Produk>();
}

std::vector<Plant> GameObject::getPlantList(){
    return this->plantList;
}
std::vector<Produk> GameObject::getProdukList(){
    return this->produkList;
}
int GameObject::stringToInt(string num){

    int n = 0;
    for (int i=0;i<num.size();i++){

        n *= 10;
        n += num[i] - '0';

    }

    return n;
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