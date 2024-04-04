#include "Plant.hpp"

// Static variable Init
int Plant::jumlahTanaman = 0;

// constructor

Plant::Plant():Item(){
        this->id_tanaman = DEFAULT_ID_TANAMAN;
        this->durasiPanen = DEFAULT_DURASI_PANEN;
        this->harga = DEFAULT_HARGA;
        this->umur = DEFAULT_UMUR;
}
Plant::Plant(const Plant& other):Item(other.kodeHuruf,other.nama,other.tipe){
        jumlahTanaman += 1;
        id_tanaman = jumlahTanaman;
        durasiPanen = other.durasiPanen;
        harga = other.harga;
        umur = other.umur;
}

Plant::Plant(string kodeHuruf, string nama, string tipe,int durasiPanen,int harga):Item(kodeHuruf,nama,tipe),
        durasiPanen(durasiPanen), harga(harga),umur(0){
                
        jumlahTanaman +=1 ;
        id_tanaman = jumlahTanaman;
}
int Plant::getIdTanaman() const{

        return id_tanaman;}
int Plant::getHarga() const{
        return harga;
}
int Plant::getDurasiPanen() const{
        return durasiPanen;
}
int Plant::getUmur() const{
        return umur;
}
void Plant::setUmur(int x){
        umur = x;
}

bool Plant::operator==(const Plant& other){
        return  this->kodeHuruf == other.kodeHuruf &&
                this->harga == other.harga &&
                this->durasiPanen == other.durasiPanen &&
                this->nama == other.nama &&
                this->tipe == other.tipe;
}

Plant& Plant::operator=(const Plant& other){
        this->kodeHuruf = other.kodeHuruf;
        this->harga = other.harga;
        this->durasiPanen = other.durasiPanen;
        this->nama = other.nama;
        this->kodeHuruf = other.kodeHuruf;
        this->tipe = other.tipe;
}

