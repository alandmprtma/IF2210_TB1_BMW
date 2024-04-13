#include "Peternak.hpp"

Peternak::Peternak(){
    this->peran = "Peternak";
}
Peternak::Peternak(string username,int uang, int berat_badan, PetiRahasia data,Ternak dataTernak, int jumlahBangunan)
:Player(username,uang,berat_badan,data),Toko()
{
    this->peran = "Peternak";
    this->dataTernak = dataTernak;
    this->jumlahBangunan = jumlahBangunan;
}
float Peternak::getPajak(){
    return 1.00;
}

void Peternak::simpanHewanTernak(){}
void Peternak::kasihMakanHewanTernak(){}
void Peternak::panenTernak(){}

void Peternak::printPlayer() {
    cout << "ID Player: " << this->IdPlayer << endl;
    cout << "Username: " << this->username << endl;
    cout << "Berat Badan: " << this->getBeratBadan() << endl;
    cout << "Peran: " << this->peran << endl;
}

void Peternak::beli() {}
void Peternak::jual() {}