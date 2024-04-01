#include "Petani.hpp"

Petani::Petani() {
  jumlahPlayer++;
  this->peran = "Petani";
  this->IdPlayer = jumlahPlayer;
}

float Petani::getPajak() {}

void Petani::setUmurTanaman() {}

void Petani::tanamTanaman() {
  cout << "Pilih tanaman dari penyimpanan" << endl;

  petiRahasia.cetakPenyimpanan();

  string slot;
  cout << "Slot: ";
  cin >> slot;

  int kolom = ((int) slot[0] - 'A') + 1;
  int baris = (int) stoi(slot.substr(1, 2));

  Plant tanamanPilihan = ladang.getElement(baris, kolom);

  cout << "Kami memilih " << tanamanPilihan.getTanamanNameByID(tanamanPilihan.getIdTanaman()) << "." << endl;

  cout << "Pilih petak tanah yang akan ditanami" <<  endl;
  ladang.cetakPenyimpanan();

  string petakTanah;
  cout << "Petak tanah: ";
  cin >> petakTanah;

  int kolomPetak = ((int) petakTanah[0] - 'A') + 1;
  int barisPetak = (int) stoi(petakTanah.substr(1, 2));

  cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
  cout << tanamanPilihan.getTanamanNameByID(tanamanPilihan.getIdTanaman()) << " berhasil ditanam!" << endl;
}

void Petani::tanamTanaman() {
  
}