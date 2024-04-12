#include "./src/Item/Item.hpp"
#include "./src/Item/Plant.hpp"
#include "./src/Item/Animal.hpp"
#include "./src/Item/Produk.hpp"
#include "./src/Item/Bangunan.cpp"
#include "./src/Penyimpanan/Penyimpanan.hpp"
#include "./src/Penyimpanan/PetiRahasia.hpp"
#include "./src/Penyimpanan/Ladang.hpp"
#include "./src/Penyimpanan/Ternak.hpp"
#include "src/Player/Player.hpp"
#include "src/Player/Petani.hpp"
#include "src/Player/Peternak.hpp"
#include "src/Player/Walikota.hpp"
#include "src/Toko/Toko.hpp"
#include "./src/GameObject/GameObject.hpp"
#include "src/GameStatus/GameStatus.hpp"

// #include "src/Player/Player.cpp"

#include <iostream>
using namespace std;
int main (){
    
    GameObject game_object = GameObject();

    game_object.muatTanaman("./Config/plant.txt");
    game_object.muatHewan("./Config/animal.txt");
    game_object.muatProduk("./Config/product.txt");
    game_object.muatBangunan("./Config/recipe.txt");
    game_object.muatMisc("./Config/misc.txt");

    GameStatus game_status = GameStatus();

    // game_status.Inisiasi();

    // Game 
    while (! game_status.isEndGame())
    {
        // TODO: List fungsi apa aja
        int opsi;
        cout<<"Pilih Opsi yang ingin digunakan: ";
        cin>>opsi;

        if (opsi==1){
            // Validasi 

            // Panggil fungsi
            game_status.nextTurn(game_object);
        }else if (opsi==2){
            // Validasi

            // Panggil fungsi
            game_status.cetakPenyimpanan();
        }else if (opsi==3){
            // Validasi

            // Panggil fungsi
            game_status.pungutPajak();
        }else if (opsi==4){
            // Validasi
            if (game_status.getCurrentPlayer()->getPeran()=="Petani"){
                game_status.cetakPeternakan();
            }
            else{
                cout<<"Perintah tidak dapat diakses karena peran tidak sesuai ! "<<endl;
            }

        }else if (opsi==5){
            if (game_status.getCurrentPlayer()->getPeran()=="Peternak"){
                game_status.cetakLadang();
            } else{
                cout<<"Perintah tidak dapat diakses karena peran tidak sesuai ! "<<endl;
            }
        }
        else if (opsi==6){
            // validasi
            if (game_status.getCurrentPlayer()->getPeran()=="Petani"){
                game_status.tanam();
            }else{
                cout<<"Perintah tidak dapat diakses karena peran tidak sesuai ! "<<endl;
            }
        }else if (opsi==7){
            // validasi

            if (game_status.getCurrentPlayer()->getPeran()=="Peternak"){
                game_status.ternak();
            } else{
                cout<<"Perintah tidak dapat diakses karena peran tidak sesuai ! "<<endl;
            }

        }else if (opsi==8){
            // validasi 

            game_status.bangunBangunan();
        }else if (opsi==9){
            // validasi

            game_status.makan();
        }else if (opsi==10){
            // validasi
            if (game_status.getCurrentPlayer()->getPeran()=="Peternak"){
                game_status.memberiPangan();
            }
            
        }else if (opsi==11){
            // validasi
            game_status.membeli();
        }else if (opsi==12){
            // validasi
            game_status.menjual();
        }else if (opsi==13){
            // validasi
            if (game_status.getCurrentPlayer()->getPeran()=="Walikota"){
                cout<<"Perintah tidak dapat diakses karena peran tidak sesuai ! "<<endl;
            }else{
                game_status.memanen();
            }
        }else if (opsi==14){
            // validasi
            string pathMuat;
            cout<<"Masukkan path file untuk dimuat: ";
            cin>>pathMuat;
            game_status.muat(pathMuat,game_object);
        }else if (opsi==15){
            // validasi
            string pathSimpan;
            cout<<"Masukkan path file untuk disimpan: ";
            cin>>pathSimpan;
            game_status.simpan(pathSimpan,game_object);
        }else if (opsi==16){
            // validasi
            if (game_status.getCurrentPlayer()->getPeran()=="Walikota"){
                game_status.tambahPemain();
            }else{
                cout<<"Perintah tidak dapat diakses karena peran tidak sesuai ! "<<endl;
            }
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
    return 0;
}