#include "./src/Item/Item.cpp"
#include "./src/Item/Plant.cpp"
#include "./src/Item/Produk.cpp"
#include "./src/Item/Animal.cpp"
#include "./src/Item/Bangunan.cpp"
#include "src/Player/Player.cpp"
#include "src/Player/Petani.cpp"
#include "src/Player/Peternak.cpp"
#include "src/Player/Walikota.cpp"
#include "src/Bangunan/Bangunan.hpp"
#include "./src/GameObject/GameObject.cpp"
#include "src/GameStatus/GameStatus.cpp"

// #include "src/Player/Player.cpp"

#include <iostream>
using namespace std;
int main (){
    
    GameObject game_object = GameObject();

    game_object.muatTanaman("./config/plant.txt");
    game_object.muatHewan("./config/animal.txt");
    game_object.muatProduk("./config/prduct.txt");
    game_object.muatBangunan("./config/recipe.txt");
    game_object.muatMisc("./config/misc.txt");

    GameStatus game_status = GameStatus();

    game_status.Inisiasi();

    // Game 
    while (! game_status.getEndGame())
    {
        // TODO: List fungsi apa aja
        int opsi;
        cout<<"Pilih Opsi yang ingin digunakan: ";
        cin>>opsi;

        if (opsi==1){
            // Validasi 

            // Panggil fungsi
            game_status.nextTurn();
        }else if (opsi==2){
            // Validasi

            // Panggil fungsi
            game_status.cetakPenyimpanan();
        }else if (opsi==3){
            // Validasi

            // Panggil fungsi
            game_status.pungutPajak();
        }else if (opsi==4){
            
        }

    }
    
    // cout<<muat->getWinGulden()<<endl;
    // cout<<muat->getSizeCrops()[0]<<" "<<muat->getSizeCrops()[1]<<endl;

    // Walikota aland;
    // aland.tambahTeakWood(10);
    // aland.tambahIronWood(10);
    // aland.tambahSandalWood(10);
    // aland.tambahAloeWood(10);
    // aland.bangunBangunan("SMH", "SMALL HOUSE", 40, 5, 5, 5, 5);
    
    // cout<<"Tanaman"<<endl;
    // for (int i=0;i<muat->getPlantList().size();i++){
    //     cout<<"Kode Huruf: "<<muat->getPlantList()[i].getKodeHuruf()<<endl;
    //     cout<<"Nama: "<<muat->getPlantList()[i].getNama()<<endl;}
    // cout<<"Hewan"<<endl;
    // for (int i=0;i<muat->getAnimalList().size();i++){
    //     cout<<"Kode Huruf: "<<muat->getAnimalList()[i].getKodeHuruf()<<endl;
    //     cout<<"Nama: "<<muat->getAnimalList()[i].getNama()<<endl;
    // }
    // cout<<"Produk"<<endl;
    // for (int i=0;i<muat->getProdukList().size();i++){
    //     cout<<"Kode Huruf: "<<muat->getProdukList()[i].getKodeHuruf()<<endl;
    //     cout<<"Nama: "<<muat->getProdukList()[i].getNama()<<endl;
    // }
}