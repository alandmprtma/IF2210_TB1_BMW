
#include "Player.hpp"

int Player::jumlahPlayer = 0;

Player::Player() {
  jumlahPlayer += 1;
  this->IdPlayer = this->jumlahPlayer;
  this->uang = 50;
  this->berat_badan = 40;
  this->peran = "";
  this->data = PetiRahasia(8, 8); /* Untuk Sementara. Default 8 x 8 */
}

Player::Player(string username,int uang, int berat_badan, PetiRahasia data){
  jumlahPlayer ++;
  this->IdPlayer = this->jumlahPlayer;
  this->username = username;
  this->uang = uang;
  this->berat_badan = berat_badan;
  this->data = data;
  this->peran = "";
}

bool Player::isKosong(){
  bool empty = true;
  int i = 0;

  while (i < data.getM() && empty) {
      int j = 0;
      while (j < data.getN() && empty) {
          if (data.getElement(i, j) != 0) {
              empty = false;
          }
          j++;
      }
      i++;
  }
  return empty;
}

void Player::setUsername(string username) {
  this->username = username;
}

void Player::setBeratBadan(int berat_badan) {
  this->berat_badan = berat_badan;
}
string Player::getUsername(){
  return this->username;
}
PetiRahasia &Player::getData(){
  return this->data;
}

int Player::getUang()
{
  return this->uang;
}

void Player::setUang(int uang)
{
  this->uang = uang;
}


string Player::getPeran() {
  return this->peran;
}

int Player::getBeratBadan() {
  return this->berat_badan;
}

int Player::getId(){
  return IdPlayer;
}
PetiRahasia Player::getPetiRahasia() {
  return this->data;
}

void Player::makan(GameObject objek)
{
  cout << "Pilih makanan dari penyimpanan" << endl;

  getPetiRahasia().cetakPeti("Penyimpanan");

  bool validInput = false;

  while (!validInput)
  {
    string Slot;
    cout << "Slot:" << endl;
    cin >> Slot;

    int kolom = ((int)Slot[0] - 'A') + 1;
    int baris = (int)stoi(Slot.substr(1, 2));

    Item* item = getPetiRahasia().getElement(baris - 1, kolom - 1);
    if (item == nullptr)
    {
      std::cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl
                << "Silahkan masukan slot yang berisi makanan." << endl;
    }
    else if (item->getTipe() == "PRODUCT_FRUIT_PLANT" || item->getTipe() == "PRODUCT_ANIMAL")
    {
      validInput = true;
    }
    else
    {
      std::cout << "Apa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!" << endl << "Silahkan masukan slot yang berisi makanan." << endl;
    }
    berat_badan += objek.findProduk(item->getNama()).getBeratTambahan();
  }
}

void Player::printPlayer() {
  cout << "ID Player: " << this->IdPlayer << endl; 
  cout << "Username: " << this->username << endl;
  cout << "Uang: " << this->uang << endl;
  cout << "Berat Badan: " << getBeratBadan() << endl;

}