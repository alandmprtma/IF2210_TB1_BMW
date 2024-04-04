#include "Animal.hpp"

Animal::Animal(): Item(){
        id_hewan = DEFAULT_ID_HEWAN;
        beratPanen = DEFAULT_BERAT_PANEN;
        harga = DEFAULT_HARGA;
}

// Static variable Init
int Animal::jumlahHewan = 0;

// constructor
Animal::Animal(string kodeHuruf, string nama, string tipe,int beratPanen,int harga):Item(kodeHuruf,nama,tipe),
        beratPanen(beratPanen), harga(harga),berat(0){ 

        jumlahHewan += 1;
        id_hewan = jumlahHewan;
}

int Animal::getHarga()const{
        return harga;
}
int Animal::getBeratPanen()const{
        return beratPanen;
}

int Animal::getId_Hewan()const{
        return id_hewan;
}

int Animal::getBerat()const{
        return berat;
}

void Animal::setBerat(int x){
        berat = x;
}

bool Animal::operator==(const Animal& other){
        return (this->getNama() == other.getNama());
}

Animal& Animal::operator=(const Animal& other){
        this->nama = other.getNama();
        this->tipe = other.getTipe();
        this->kodeHuruf = other.getKodeHuruf();
        this->id_hewan = other.getId_Hewan();
        this->beratPanen = other.getBeratPanen();
        this->harga = other.getHarga();
        return *this;
}