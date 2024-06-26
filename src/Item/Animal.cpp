#include "Animal.hpp"


// Static variable Init
int Animal::jumlahHewan = 0;

// constructor
Animal::Animal(): Item(){
        id_hewan = DEFAULT_ID_HEWAN;
        beratPanen = DEFAULT_BERAT_PANEN;
        harga = DEFAULT_HARGA;
        berat = 0;
}
Animal::Animal(const Animal& other):Item(other.kodeHuruf,other.nama,other.tipe){
        id_hewan = other.id_hewan;
        beratPanen = other.beratPanen;
        harga = other.harga;
        berat = 0;
}
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
        return  this->kodeHuruf == other.kodeHuruf &&
                this->harga == other.harga &&
                this->berat == other.berat &&
                this->nama == other.nama &&
                this->tipe == other.tipe;
}


Animal& Animal::operator=(const Animal& other) {
        this->nama = other.getNama();
        this->tipe = other.getTipe();
        this->kodeHuruf = other.getKodeHuruf();
        this->id_hewan = other.getId_Hewan();
        this->beratPanen = other.getBeratPanen();
        this->harga = other.getHarga();
        return *this;
}