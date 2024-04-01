#include "Animal.hpp"

// Static variable Init
int Animal::jumlahHewan = 0;

// constructor
Animal::Animal(string kodeHuruf, string nama, string tipe,int beratPanen,int harga):Item(kodeHuruf,nama,tipe),beratPanen(beratPanen), harga(harga){ 
        jumlahHewan += 1;
        id_hewan = jumlahHewan;
}