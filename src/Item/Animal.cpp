#include "Animal.hpp"

// Static variable Init
int Animal::jumlahHewan = 0;

// constructor
Animal::Animal(string kodeHuruf, string nama, string tipe,int beratPanen,int harga):Item(kodeHuruf,nama,tipe),
        beratPanen(beratPanen), harga(harga),berat(0){ 

        jumlahHewan += 1;
        id_hewan = jumlahHewan;
}

int Animal::getHarga(){
        return harga;
}
int Animal::getBeratPanen(){
        return beratPanen;
}

int Animal::getId_Hewan(){
        return id_hewan;
}

int Animal::getBerat(){
        return berat;
}

void Animal::setBerat(int x){
        berat = x;
}