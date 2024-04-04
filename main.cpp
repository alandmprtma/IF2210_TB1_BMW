#include "./src/Item/Item.cpp"
#include "./src/Item/Plant.cpp"
#include "./src/Item/Produk.cpp"
#include "./src/Item/Animal.cpp"
#include "./src/Item/Bangunan.cpp"
// #include "Player/Petani.hpp"
// #include "Player/Peternak.hpp"
#include "./src/Player/Walikota.hpp"
#include "./src/Player/Walikota.cpp"
// #include "Bangunan/Bangunan.hpp"
#include "./src/GameObject/GameObject.cpp"
#include "src/Player/Player.cpp"

#include <iostream>
using namespace std;
int main (){
    GameObject *muat = new GameObject();
    muat->muatProduk("./Config/product.txt");
    muat->muatTanaman("./Config/plant.txt");
    muat->muatHewan("./Config/animal.txt");
    muat->muatBangunan("./Config/recipe.txt");
    muat->muatMisc("./Config/misc.txt");

    // cout<<muat->getWinGulden()<<endl;
    // cout<<muat->getSizeCrops()[0]<<" "<<muat->getSizeCrops()[1]<<endl;

    Walikota aland;
    aland.tambahTeakWood(10);
    aland.tambahIronWood(10);
    aland.tambahSandalWood(10);
    aland.tambahAloeWood(10);
    aland.bangunBangunan("SMH", "SMALL HOUSE", 40, 5, 5, 5, 5);
    
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