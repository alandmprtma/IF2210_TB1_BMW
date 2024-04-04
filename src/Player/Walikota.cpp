#include "Walikota.hpp"

Walikota::Walikota() {
  jumlahPlayer += 1;
  this->IdPlayer = jumlahPlayer;
  this->username = "Walikota";
  this->peran = "Walikota";
  this->berat_badan = DEFAULT_BERAT_BADAN;
  this->uang = DEFAULT_GULDEN;
  this->TeakWood = DEFAULT_TEAK_WOOD;
  this->SandalWood = DEFAULT_SANDAL_WOOD;
  this->AloeWood = DEFAULT_ALOE_WOOD;
  this->IronWood = DEFAULT_IRONWOOD;
}

void Walikota::pungutPajak() {}

void Walikota::bangunBangunan(string kodeHuruf, string namaBangunan, int price, int TeakTree, int SandalwoodTree, int AloeTree, int IronwoodTree) {
  try{
    pakaiMaterial(price,TeakTree, SandalwoodTree, AloeTree, IronwoodTree);
    Bangunan b(kodeHuruf,namaBangunan,price);
    this->bangunan.push_back(b);
    cout << namaBangunan << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
  }catch(MaterialTidakCukupException e){
    cout << e.what();
    cout << " Masih memerlukan ";
    if (this->uang < price){
      cout << price - this->uang << " gulden";
    }
    if (this->TeakWood < TeakTree){
      cout <<", "<< TeakTree - this->TeakWood << " teak wood";
    }
    if (this->AloeWood < AloeTree){
      cout <<", "<< AloeTree - this->AloeWood << " aloe wood";
    }
    if (this->IronWood < IronwoodTree){
      cout <<", "<< IronwoodTree - this->IronWood << " ironwood wood";
    }
    if (this->SandalWood < SandalwoodTree){
      cout <<", "<< SandalwoodTree - this->SandalWood << " sandal wood";
    }
    cout << "!" << endl;
  }
  
}

void Walikota::pakaiMaterial (int price, int TeakTree, int SandalwoodTree, int AloeTree, int IronwoodTree){
  if(this->uang < price || this->TeakWood < TeakTree || this->SandalWood < SandalwoodTree || this->IronWood < IronwoodTree){
    throw MaterialTidakCukupException();
  }
  this->uang -= price;
  this->TeakWood -= TeakTree;
  this->SandalWood -= SandalwoodTree;
  this->AloeWood -= AloeTree;
  this->IronWood -= IronwoodTree;
}

void Walikota::tambahGulden(int num){
  this->uang += num;
}

void Walikota::tambahTeakWood(int num){
  this->TeakWood += num;
}

void Walikota::tambahSandalWood(int num){
  this->SandalWood += num;
}

void Walikota::tambahAloeWood(int num){
  this->AloeWood += num;
}

void Walikota::tambahIronWood(int num){
  this->IronWood += num;
}

void Walikota::addPetani() {}

void Walikota::addPeternak() {}

void Walikota::jual() {}

void Walikota::beli() {}