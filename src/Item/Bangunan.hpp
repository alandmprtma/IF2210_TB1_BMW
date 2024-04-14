#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "Item.hpp"

#include <string>
#include <map>

#define TIPE_BANGUNAN "Bangunan"
#define DEFAULT_HARGA_BANGUNAN -1

using namespace std;

class Bangunan : public Item {
    public:
        /*
            Membuat objek Bangunan dengan nama "Bangunan Kosong"
        */
        static int jumlahBangunan;
        /*
            Membuat objek Bangunan 
        */
        Bangunan(string kodeHuruf, string namaBangunan, int Price);

        Bangunan();
        /*
            Input map Material
        */        
        void inputMaterial(string namaMaterial, int quantity);
        /*
            Mendapatkan ID Bangunan
        */
        int getIDBangunan();
        /*
            Mendapatkan Kode Huruf
        */
        string getKodeHuruf();
        /*
            Mendapatkan nama Bangunan
        */
        string getNamaBangunan();
        /*
            Mendapatkan biaya Bangunan
        */
        int getPrice();
        /*
        Mendapatkan Jumlah Material
        */
        int getMaterialQuantity(string material);       

        bool operator==(const Bangunan&);
        
    private:
        int idBangunan;
        string kodeHuruf;
        string namaBangunan;
        int price;
        map<string,int> material;
};

#endif