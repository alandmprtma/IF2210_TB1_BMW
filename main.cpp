#include "src/Item/Item.hpp"
#include "src/Item/Plant.hpp"
#include "src/Item/Animal.hpp"
#include "src/Item/Produk.hpp"
#include "src/Item/Bangunan.hpp"
#include "src/Penyimpanan/Penyimpanan.hpp"
#include "src/Penyimpanan/PetiRahasia.hpp"
#include "src/Penyimpanan/Ladang.hpp"
#include "src/Penyimpanan/Ternak.hpp"
#include "src/Player/Player.hpp"
#include "src/Player/Petani.hpp"
#include "src/Player/Peternak.hpp"
#include "src/Player/Walikota.hpp"
#include "src/Toko/Toko.hpp"
#include "src/GameObject/GameObject.hpp"
#include "src/GameStatus/GameStatus.hpp"

// #include "src/Player/Player.cpp"

#include <iostream>
using namespace std;

// ANSI color codes
#define RESET "\033[0m"         // Reset color
#define RED "\033[31m"          // Red color
#define GREEN "\033[32m"        // Green color
#define YELLOW "\033[33m"       // Yellow color
#define BLUE "\033[34m"         // Blue color
#define MAGENTA "\033[35m"      // Magenta color
#define CYAN "\033[36m"         // Cyan color
#define WHITE "\033[37m"        // White color
#define ORANGE "\033[38;5;208m" // Orange color

void printASCII(string filename)
{
    string line = " ";
    ifstream inFile;
    inFile.open(filename);

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "File not found" << endl;
    }
    inFile.close();
}

int main()
{
    GameObject game_object = GameObject();
    try
    {
        game_object.muatTanaman("Config/plant.txt");
        game_object.muatHewan("Config/animal.txt");
        game_object.muatProduk("Config/product.txt");
        game_object.muatBangunan("Config/recipe.txt");
        game_object.muatMisc("Config/misc.txt");
    }
    catch (const FileNotFoundError &e)
    {
        cout << e.what() << endl;
    }

    GameStatus game_status = GameStatus();

    cout << endl;
    cout << "✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦" << endl;
    string filename = "ascii.txt";
    printASCII(filename);
    cout << "✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦ . 　⁺ 　 . ✦" << endl
         << endl;

    game_status.Inisiasi(game_object);

    // game_status.muat("Config/state.txt",game_object);
    // cout<<game_status.getWalikota().getUsername()<<endl;
    // cout<<game_status.getWalikota().getId()<<endl;
    // Bangunan *b = new Bangunan("XYZ", "ShinKanSen", 50);
    // game_status.getWalikota().getData().setElement(b,0,0);
    // cout<<game_status.getWalikota().getData().getElement(0,0)->getNama()<<endl;
    // cout<<game_status.getWalikota().getData().getElement(0,0)->getNama()<<endl;
    // game_status.getToko().welcome();
    // cout<<game_status.getWalikota().getData().getElement(0,1)->getNama()<<endl;
    // Game
    cout << "Sekarang Giliran " << game_status.getCurrentPlayer()->getUsername() << " untuk Jalan!" << endl;

    while (!game_status.isEndGame(game_object))
    {
        // TODO: List fungsi apa aja
        int opsi;
        cout << endl <<"Pilih Opsi yang ingin digunakan: ";
        cin >> opsi;
        cout << endl;
        if (opsi==0){
            // GetIdentitas
            cout<<"   --- Status Pemain ---   "<<endl;
            cout<<"ID: "<<game_status.getCurrentPlayer()->getId()<<endl;
            cout<<"Username: "<<game_status.getCurrentPlayer()->getUsername()<<endl;
            cout<<"Peran: "<<game_status.getCurrentPlayer()->getPeran()<<endl;
            cout<<"Uang: "<<game_status.getCurrentPlayer()->getUang()<<endl;
            cout<<"Berat Badan: "<<game_status.getCurrentPlayer()->getBeratBadan()<<endl;

        }else if (opsi == 1)
        {
            // Panggil fungsi
            game_status.nextTurn(game_object);
        }
        else if (opsi == 2)
        {
            // Panggil fungsi
            game_status.cetakPenyimpanan();
        }
        else if (opsi == 3)
        {
            if (game_status.getCurrentPlayer()->getPeran() == "Walikota")
            {
                game_status.pungutPajak(game_object);
            }
            else{
                cout << "Perintah ini hanya bisa dilakukan oleh walikota! " << endl;
            }
        }
        else if (opsi == 4)
        {
            // Validasi
            if (game_status.getCurrentPlayer()->getPeran() == "Petani")
            {
                game_status.cetakPenyimpanan();
            }
            else
            {
                cout << "Perintah tidak dapat diakses karena peran tidak sesuai ! " << endl;
            }
        }
        else if (opsi == 5)
        {
            if (game_status.getCurrentPlayer()->getPeran() == "Peternak")
            {
                game_status.cetakPenyimpanan();
            }
            else
            {
                cout << "Perintah tidak dapat diakses karena peran tidak sesuai ! " << endl;
            }
        }
        else if (opsi == 6)
        {
            // validasi
            if (game_status.getCurrentPlayer()->getPeran() == "Petani")
            {
                game_status.tanam();
            }
            else
            {
                cout << "Perintah tidak dapat diakses karena peran tidak sesuai ! " << endl;
            }
        }
        else if (opsi == 7)
        {
            // validasi

            if (game_status.getCurrentPlayer()->getPeran() == "Peternak")
            {
                game_status.ternak();
            }
            else
            {
                cout << "Perintah tidak dapat diakses karena peran tidak sesuai ! " << endl;
            }
        }
        else if (opsi == 8)
        {
            // validasi
            // cout<<"11";
            // if(game_status.getCurrentPlayer()->getPeran() == "Walikota"){
            try
            {
                cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
                for (const auto &bangunan : game_object.getBangunanList())
                {
                    cout << bangunan.getNama() << " (" << bangunan.getPrice() << " gulden, ";
                    for (const auto &pair : bangunan.getMaterial())
                    {
                        cout << pair.first << " " << pair.second << ", ";
                    }
                    cout << "\b\b)" << endl;
                }
                cout << "Bangunan yang ingin dibangun: ";
                string nama_bangunan;
                cin >> nama_bangunan;
                bool found = false;
                auto bangunanList = game_object.getBangunanList();
                auto it = bangunanList.begin();
                while (it != bangunanList.end() && found == false)
                {
                    if (it->getNama() == nama_bangunan)
                    {
                        found = true;
                    }
                    ++it;
                }
                if (found == false)
                {
                    throw RecipeNotFoundException();
                }
            }
            catch (const RecipeNotFoundException &e)
            {
                cout << e.what() << endl;
            }
            // }
            // else{
            //     cout<<"Perintah tidak dapat diakses karena peran tidak sesuai ! "<<endl;
            // }

            // game_status.bangunBangunan();
        }
        else if (opsi == 9)
        {
            // validasi

            game_status.makan();
        }
        else if (opsi == 10)
        {
            // validasi
            if (game_status.getCurrentPlayer()->getPeran() == "Peternak")
            {
                game_status.memberiPangan();
            }
        }
        else if (opsi == 11)
        {
            // validasi
            game_status.membeli();
        }
        else if (opsi == 12)
        {
            try
            {
                if (game_status.getWalikota().isKosong())
                {
                    throw PenyimpananKosong();
                }
                game_status.getToko().welcome();
                cout << "Berikut merupakan penyimpanan Anda" << endl;
                cout << game_status.getWalikota().getData().getN();
                // if(game_status.getCurrentPlayer()->getPeran() == "Walikota"){
                game_status.getWalikota().getData().cetakPenyimpanan();
                cout << "Silahkan pilih petak yang ingin anda jual!" << endl;
                string petak;
                cout << "Petak : ";
                cin >> petak;
                // }
            }
            catch (const PenyimpananKosong &e)
            {
                cout << e.what();
                cout << " Anda tidak dapat melakukan penjualan!" << endl;
            }
            // validasi
            // game_status.menjual();
        }
        else if (opsi == 13)
        {
            // validasi
            if (game_status.getCurrentPlayer()->getPeran() == "Walikota")
            {
                cout << "Perintah tidak dapat diakses karena peran tidak sesuai ! " << endl;
            }
            else
            {
                game_status.memanen();
            }
        }
        else if (opsi == 14)
        {
            // validasi
            string pathSimpan;
            cout << "Masukkan path file untuk disimpan: ";
            cin >> pathSimpan;
            game_status.simpan(pathSimpan, game_object);
        }
        else if (opsi == 15)
        {
            // validasi
            // Tambah Pemain
            try{
                if (game_status.getCurrentPlayer()->getPeran()!="Walikota"){
                    throw PeranTidakSesuai();
                }else if (game_status.getCurrentPlayer()->getUang()<50){
                    throw UangTidakCukup();
                }else{
                    game_status.tambahPemain(game_object);
                    cout<<"Pemain berhasil terdaftar!"<<endl;
                }
            }catch(const Exception& e){
                cout<<e.what()<<endl;
                cout<<"Kembali ke program utama"<<endl;
            }
        }else if (opsi==16){
            // Menyerah
            try{
                game_status.surrend();
            }catch(const Exception& e){
                cout<<e.what()<<endl;
            }
        }
        else{
            cout<<OpsiTidakValid().what()<<endl;
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