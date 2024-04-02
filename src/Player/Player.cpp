#include "Player.hpp"

int Player::jumlahPlayer = 0;

Player::Player() {
  this->IdPlayer = this->jumlahPlayer;
  this->uang = 50;
  this->berat_badan = 40;
  jumlahPlayer += 1;
}

void Player::setUsername(string username) {
  this->username = username;
}

void Player::setBeratBadan(int berat_badan) {
  this->berat_badan = berat_badan;
}

int Player::getBeratBadan() {
  return this->berat_badan;
}

void Player::makan() {
  // cout << "Pilih makanan dari penyimpanan" << endl;

  // petiRahasia.cetakPenyimpanan();

  // bool validInput = false;

  // while (!validInput) {
  //   string Slot;
  //   cout << "Slot:" << endl;
  //   cin >> Slot;

  //   int kolom = ((int) Slot[0] - 'A') + 1;
  //   int baris = (int) stoi(Slot.substr(1, 2));

  //   any elemen = petiRahasia.getElement(baris, kolom);

  //   if (elemen.has_value()) {
  //       if (elemen.type() == typeid(Produk)) {
  //         Produk makanan = any_cast<Produk>(elemen);
          
  //         cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;

  //         int beratBadanTambahan;
  //         setBeratBadan(beratBadanTambahan);

  //         cout << "Alhasil, berat badan kamu naik menjadi " << getBeratBadan() << endl;

  //         validInput = true;
  //       } else {
  //         // cout << "Apa yang kamu lakukan??!! Kamu mencoba memakan itu?!!" << endl;
  //         // cout << "Silahkan masukan slot yang berisi makanan." << endl;
  //       }     
  //   } else {
  //       cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
  //       cout << "Silahkan masukan slot yang berisi makanan." << endl; 
  //   }
  // }
}

void Player::printPlayer() {
  cout << "ID Player: " << this->IdPlayer << endl; 
  cout << "Username: " << this->username << endl;
  cout << "Uang: " << this->uang << endl;
  cout << "Berat Badan: " << getBeratBadan() << endl;
}