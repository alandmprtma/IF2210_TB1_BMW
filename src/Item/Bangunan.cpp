#include "Bangunan.hpp"

int Bangunan::jumlahBangunan = 0;

Bangunan::Bangunan(string kodeHuruf, string namaBangunan, int price): Item(kodeHuruf, namaBangunan, "Bangunan"), price(price) {
    jumlahBangunan += 1;
    idBangunan = jumlahBangunan;
}

void Bangunan::inputMaterial(string namaMaterial, int quantity){
    material[namaMaterial] = quantity;
}

int Bangunan::getIDBangunan(){
    return idBangunan;
}

string Bangunan::getKodeHuruf(){
    return kodeHuruf;
}

string Bangunan::getNamaBangunan(){
    return namaBangunan;
}

int Bangunan::getPrice(){
    return price;
}

int Bangunan::getMaterialQuantity(string namaMaterial){
    auto it = material.find(namaMaterial);
    return it->second;
}
bool Bangunan::operator==(const Bangunan& other){
    return this->kodeHuruf == other.kodeHuruf &&
        this->nama == other.nama &&
        this->tipe == other.tipe &&
        this->price == other.price
        ;
}


