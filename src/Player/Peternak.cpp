#include "Peternak.hpp"

Peternak::Peternak(){
    jumlahPlayer++;
    this->peran = "Peternak";
    this->IdPlayer = jumlahPlayer;
}

float Peternak::getPajak(){
  
}

// Virtual Function Toko
void beli(){}
void jual(){}

void Peternak::simpanHewanTernak(){}
void Peternak::kasihMakanHewanTernak(){}

void Peternak::panenTernak(){}
void Peternak::cetakPeternakan(){}