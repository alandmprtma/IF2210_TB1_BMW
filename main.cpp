#include "./src/Item/Item.cpp"
#include "./src/Item/Plant.cpp"
#include "./src/Item/Produk.cpp"
#include "./src/Item/Animal.cpp"
// #include "Player/Petani.hpp"
// #include "Player/Peternak.hpp"
// #include "Player/Walikota.hpp"
// #include "Bangunan/Bangunan.hpp"
#include "./src/SimpanMuat/Muat.cpp"

#include <iostream>
using namespace std;
int main (){
    Muat *muat = new Muat();
    muat->muatProduk("./Config/product.txt");
    muat->muatTanaman("./Config/plant.txt");
    muat->muatHewan("./Config/animal.txt");

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