#include "./src/Item/Item.cpp"
#include "./src/Item/Plant.cpp"
#include "./src/Item/Produk.cpp"
#include "./src/Item/Animal.cpp"
#include "./src/Player/Player.cpp"
#include "./src/Player/Petani.cpp"
#include "./src/Player/Peternak.cpp"
#include "./src/Player/Walikota.cpp"
#include "./src/Bangunan/Bangunan.cpp"
#include "./src/Player/Penyimpanan.cpp"
#include "./src/Toko/Toko.cpp"
// #include "./src/SimpanMuat/Muat.cpp"
#include "./src/Item/Bangunan.cpp"
// #include "Player/Petani.hpp"
// #include "Player/Peternak.hpp"
// #include "Player/Walikota.hpp"
// #include "Bangunan/Bangunan.hpp"
#include "./src/GameObject/GameObject.cpp"

#include <iostream>
using namespace std;
int main (){
    cout << "# ========= Test Player ========= #" << endl;
    Player P1;
    P1.setUsername("Akmal");
    P1.setBeratBadan(10);
    P1.printPlayer();
    cout << endl;
    GameObject *muat = new GameObject();
    muat->muatProduk("./Config/product.txt");
    muat->muatTanaman("./Config/plant.txt");
    muat->muatHewan("./Config/animal.txt");
    muat->muatBangunan("./Config/recipe.txt");
    muat->muatMisc("./Config/misc.txt");

    cout<<muat->getWinGulden()<<endl;
    cout<<muat->getSizeCrops()[0]<<" "<<muat->getSizeCrops()[1]<<endl;
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

    


    cout << "# ========= Test Petani ========= #" << endl;
    Petani P2;
    P2.setUsername("Albert");
    P2.setBeratBadan(20);
    P2.printPlayer();
    cout << endl;

    cout << "# ========= Test Peternak ========= #" << endl;
    Peternak P3;
    P3.setUsername("Reela");
    P3.setBeratBadan(30);
    P3.printPlayer();
    cout << endl;

    cout << "# ========= Test Walikota ========= #" << endl;
    Walikota P4;
    P4.setUsername("Aland");
    P4.setBeratBadan(40);
    P4.printPlayer();
    cout << endl;

    cout << "# ========= Test Penyimpanan ======== #" << endl << endl;
    Penyimpanan<int> Kotak(8, 8);
    cout << "Size dari Kotak: " << Kotak.getSize() << endl;
    Kotak.cetakPenyimpanan();
    Kotak.setElement(1, 5, 5);
    Kotak.setElement(2, 5, 6);
    Kotak.cetakPenyimpanan();

    cout << endl;
    return 0;
}