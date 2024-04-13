#include "Petani.hpp"

Petani::Petani(): Player(), Toko() {
  this->peran = "Petani";
  this->dataLadang = Ladang(8, 8); /* Untuk Sementara. Default 8 x 8*/
}
Petani::Petani(string username,int uang, int berat_badan, PetiRahasia data, Ladang dataLadang, int jumlahBangunan): Player(username,uang,berat_badan,data), Toko() {
  this->peran = "Petani";
  this->dataLadang = dataLadang;
  this->jumlahBangunan = jumlahBangunan;
}

void Petani::tanamTanaman() {
  // cout << "Pilih tanaman dari penyimpanan" << endl;

  // petiRahasia.cetakPenyimpanan();

  // string slot;
  // cout << "Slot: ";
  // cin >> slot;

  // int kolom = ((int) slot[0] - 'A') + 1;
  // int baris = (int) stoi(slot.substr(1, 2));

  // Plant tanamanPilihan = ladang.getElement(baris, kolom);

  // cout << "Kami memilih " << tanamanPilihan.getTanamanNameByID(tanamanPilihan.getIdTanaman()) << "." << endl;

  // cout << "Pilih petak tanah yang akan ditanami" <<  endl;
  // ladang.cetakPenyimpanan();

  // string petakTanah;
  // cout << "Petak tanah: ";
  // cin >> petakTanah;

  // int kolomPetak = ((int) petakTanah[0] - 'A') + 1;
  // int barisPetak = (int) stoi(petakTanah.substr(1, 2));

  // cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
  // cout << tanamanPilihan.getTanamanNameByID(tanamanPilihan.getIdTanaman()) << " berhasil ditanam!" << endl;
}

void Petani::panenTanaman() {
  // ladang.cetakPenyimpanan();

  // TODO : Menyimpan petak yang memiliki isi; tipe dan jumlahnya

  // cout << "Pilig tanaman siap panen yang kamu miliki" << endl;


  // int NoTanaman;
  // cout << "Nomor tanaman yang ingin dipanen: ";
  // cin >> NoTanaman;

  // int NPetak;
  // cout << "Berapa petak yang ingin dipanen";
  // cin >> NPetak;

  // cout << "Pilih petak yang ingin dipanen:" << endl;
  // vector<Plant> tanamanSiapPanen(NPetak);
  // for (int i = 0; i < NPetak; i++) {
  //   cout << "Petak ke-" << i+1 << ": ";
  //   string pilihanTanaman;
  //   cin >> pilihanTanaman;

  //   int kolom = ((int) pilihanTanaman[0] - 'A') + 1;
  //   int baris = (int) stoi(pilihanTanaman.substr(1, 2));

  //   Plant tanamanPilihan = ladang.getElement(baris, kolom);
  //   tanamanSiapPanen.push_back(tanamanPilihan);
  // }

  // TODO : Cout tanaman yang berhasil dipanen

  // TODO : Masukkan hasil panen ke inventory penyimpanan (petiRahasia)

}

void Petani::setUmurTanaman(int row, int col) {}

Ladang Petani::getLadang() {
  return this->dataLadang;
}

float Petani::getPajak() {
  return 1.00;
}

void Petani::jual() {}

void Petani::beli() {}

void Petani::printPlayer() {
  cout << "ID Player: " << this->IdPlayer << endl;
  cout << "Username: " << this->username << endl;
  cout << "Uang: " << this->uang << endl;
  cout << "Berat Badan: " << getBeratBadan() << endl;
  cout << "Peran: " << this->peran << endl;
}