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

Player::Player(string username,int uang, int berat_badan, PetiRahasia data) {
  jumlahPlayer ++;
  this->IdPlayer = this->jumlahPlayer;
  this->username = username;
  this->uang = uang;
  this->berat_badan = berat_badan;
  this->data = data;
  this->peran = "";
}

bool Player::isKosong() {
  bool empty = true;
  int i = 0;

  while (i < data.getM() && empty) {
      int j = 0;
      while (j < data.getN() && empty) {
          if (data.getElementNoException(i, j) != 0) {
              empty = false;
          }
          j++;
      }
      i++;
  }
  return empty;
}

bool Player::isPenuh(){
  bool full = true;
  int i = 0;

  while (i < data.getM() && full) {
      int j = 0;
      while (j < data.getN() && full) {
          if (data.getElementNoException(i, j) == 0) {
              full = false;
          }
          j++;
      }
      i++;
  }
  return full;
}

void Player::setUsername(string username) {
  this->username = username;
}

void Player::setBeratBadan(int berat_badan) {
  this->berat_badan = berat_badan;
}

string Player::getUsername() {
  return this->username;
}

PetiRahasia& Player::getData() {
  return this->data;
}

int Player::getSisaPenyimpanan(){
  int i = 0;
  int sisa = 0;
  while (i < data.getM()) {
      int j = 0;
      while (j < data.getN()) {
          if (data.getElementNoException(i, j) == 0) {
              sisa++;
          }
          j++;
      }
      i++;
  }
  return sisa;
}

int Player::getUang() {
  return this->uang;
}

void Player::setUang(int uang) {
  this->uang = uang;
}

string Player::getPeran() {
  return this->peran;
}

int Player::getBeratBadan() {
  return this->berat_badan;
}

int Player::getId() {
  return IdPlayer;
}

void Player::isElementNull(int i, int j)
{
  if (getData().getElementNoException(i, j) == nullptr)
  {
    throw ElementNotFound();
  }
}

void Player::isElementNotProduct(int i, int j)
{
  if (getData().getElementNoException(i, j)->getTipe() != "PRODUCT_FRUIT_PLANT" && getData().getElementNoException(i, j)->getTipe() != "PRODUCT_ANIMAL")
  {
    throw ElementNotConsumable();
  }
}

void Player::isIndexValid(int i, int j, int baris, int kolom) {
    if (i < 0 || i > baris || j < 0 || j > kolom) {
      throw IndexOutOfBound();
    }
  }

void Player::isPenyimpananHaveProduct()
{
  bool valid = false;
  int i = 0;
  while (i < getData().getM() && !valid)
  {
    int j = 0;
    while (j < getData().getN() && !valid)
    {
      if (getData().getElementNoException(i, j) != nullptr)
      {
        if (getData().getElementNoException(i, j)->getTipe() == "PRODUCT_FRUIT_PLANT" || getData().getElementNoException(i, j)->getTipe() == "PRODUCT_ANIMAL")
        {
          valid = true;
        }
      }
      j++;
    }
    i++;
  }
  if (!valid)
  {
    throw PenyimpananDontHaveProduct();
  }
}

void Player::makan(GameObject objek)
{
  try
  {
    isPenyimpananHaveProduct();
    cout << "Pilih makanan dari penyimpanan" << endl
         << endl;

    data.cetakPenyimpanan();

    while (true)
    {
      try
      {
        string Slot;
        cout << "Slot: ";
        cin >> Slot;
        cout << endl;

        int kolom = ((int)Slot[0] - 'A') + 1;
        int baris = (int)stoi(Slot.substr(1, 2));

        isIndexValid(baris - 1, kolom - 1, data.getM(), data.getN());

        isElementNull(baris - 1, kolom - 1);
        isElementNotProduct(baris - 1, kolom - 1);

        Item *item = data.getElementNoException(baris - 1, kolom - 1);

        berat_badan += objek.findProduk(item->getNama()).getBeratTambahan();
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
        cout << "Berat badanmu bertambah menjadi " << berat_badan << endl;
        data.removeElement(baris - 1, kolom - 1);
        data.cetakPenyimpanan();
        break;
      }
      catch (IndexOutOfBound &e)
      {
        cout << e.what() << endl
             << endl;
      }
      catch (ElementNotFound &e)
      {
        cout << e.what() << endl
             << endl;
      }
      catch (ElementNotConsumable &e)
      {
        cout << e.what() << endl
             << endl;
      }
    }
  }
  catch (const PenyimpananDontHaveProduct &e)
  {
    cout << e.what() << endl;
  }
}
void Player::printPlayer() {
  cout << "ID Player: " << this->IdPlayer << endl; 
  cout << "Username: " << this->username << endl;
  cout << "Uang: " << this->uang << endl;
  cout << "Berat Badan: " << getBeratBadan() << endl;
}