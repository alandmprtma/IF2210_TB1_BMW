#include "./src/Item/Item.cpp"
#include "./src/Item/Plant.cpp"
#include "./src/Item/Produk.cpp"
#include "./src/Item/Animal.cpp"
#include "./src/Player/Player.cpp"
#include "./src/Player/Petani.cpp"
#include "./src/Player/Peternak.cpp"
#include "./src/Player/Walikota.cpp"
#include "./src/Bangunan/Bangunan.cpp"
// #include "./src/SimpanMuat/Muat.cpp"
// #include "./src/Player/Penyimpanan.cpp"
#include "./src/Toko/Toko.cpp"

#include <iostream>
using namespace std;
int main (){
    cout << "# ========= Test Player ========= #" << endl;
    Player P1;
    P1.setUsername("Akmal");
    P1.setBeratBadan(10);
    P1.printPlayer();
    cout << endl;

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
    
    return 0;
}