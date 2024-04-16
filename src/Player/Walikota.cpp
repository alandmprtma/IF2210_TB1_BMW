#include "Walikota.hpp"

Walikota::Walikota() : Player()
{
  this->username = "Walikota";
  this->peran = "Walikota";
  this->berat_badan = DEFAULT_BERAT_BADAN;
  this->uang = DEFAULT_GULDEN;
  this->TeakWood = DEFAULT_TEAK_WOOD;
  this->SandalWood = DEFAULT_SANDAL_WOOD;
  this->AloeWood = DEFAULT_ALOE_WOOD;
  this->IronWood = DEFAULT_IRONWOOD;
}

Walikota::Walikota(string username, int uang, int berat_badan, PetiRahasia data) :

                                                                                   Player(username, uang, berat_badan, data)
{
  bangunan = vector<Bangunan>();
  this->peran = "Walikota";
  this->berat_badan = DEFAULT_BERAT_BADAN;
  this->uang = DEFAULT_GULDEN;
  this->TeakWood = DEFAULT_TEAK_WOOD;
  this->SandalWood = DEFAULT_SANDAL_WOOD;
  this->AloeWood = DEFAULT_ALOE_WOOD;
  this->IronWood = DEFAULT_IRONWOOD;
}

void Walikota::pungutPajak(GameObject &objek, vector<Player *> &players)
{
  int indeks = 1;
  int pemasukan = 0;
  cout << "Berikut adalah detil dari pemungutan pajak: " << endl;
  // iterasi per player
  for (size_t h = 0; h < players.size(); h++)
  {
    int totalKekayaan = 0;
    int pajak = 0;
    int pajakAkhir = 0;
    if (players[h]->getPeran() == "Walikota")
    {
      continue;
    }
    // iterasi inventory player
    for (int i = 0; i < players[h]->getData().getM(); i++)
    {
      for (int j = 0; j < players[h]->getData().getN(); j++)
      {
        if (players[h]->getData().getElementNoException(i, j) != nullptr)
        {
          // cek tipe inventory
          Item* item = players[h]->getData().getElementNoException(i, j);
          if (item->getTipe() == "Bangunan")
          {
            totalKekayaan += objek.findBangunan(item->getNama()).getPrice();
          }
          else if (item->getTipe() == "HERBIVORE" || item->getTipe() == "OMNIVORE" || item->getTipe() == "CARNIVORE")
          {
            totalKekayaan += objek.findAnimal(item->getNama()).getHarga();
          }
          else if (item->getTipe() == "FRUIT_PLANT" || item->getTipe() == "MATERIAL_PLANT")
          {
            totalKekayaan += objek.findPlant(item->getNama()).getHarga();
          }
          else if (item->getTipe() == "PRODUCT_MATERIAL_PLANT" || item->getTipe() == "PRODUCT_FRUIT_PLANT" || item->getTipe() == "PRODUCT_ANIMAL")
          {
            totalKekayaan += objek.findProduk(item->getNama()).getHarga();
          }
        }
      }
    }
    // pengurangan dengan KTKP
    if (players[h]->getPeran() == "Petani")
    {
      totalKekayaan -= 13;
    }
    else if (players[h]->getPeran() == "Peternak")
    {
      totalKekayaan -= 11;
    }
    // hitung pajak
    totalKekayaan += players[h]->getUang();
    

    if (totalKekayaan > 0)
    {
      if (totalKekayaan <= 6)
      {
        pajak = std::roundf(totalKekayaan * 0.05);
      }
      else if (totalKekayaan > 6 && totalKekayaan <= 25)
      {
        pajak = std::roundf(totalKekayaan * 0.15);
      }
      else if (totalKekayaan > 25 && totalKekayaan <= 50)
      {
        pajak = std::roundf(totalKekayaan * 0.25);
      }
      else if (totalKekayaan > 50 && totalKekayaan <= 500)
      {
        pajak = std::roundf(totalKekayaan * 0.30);
      }
      else if (totalKekayaan > 500)
      {
        pajak = std::roundf(totalKekayaan * 0.35);
      }

      if (pajak < players[h]->getUang())
      {
        players[h]->setUang(players[h]->getUang() - pajak);
        Walikota::setUang(Walikota::getUang() + pajak);
        pajakAkhir = pajak;
      }
      else
      {
        players[h]->setUang(0);
        Walikota::setUang(Walikota::getUang() + players[h]->getUang());
        pajakAkhir = players[h]->getUang();
      }
      pemasukan += pajakAkhir;
    }
    cout << "  " << indeks << ". " << players[h]->getUsername() << " - " << players[h]->getPeran() << ": " << pajakAkhir << endl;
    indeks++;
  }
  cout << endl
       << "Negara mendapatkan pemasukan sebesar " << pemasukan << " gulden." << endl;
  cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

void Walikota::bangunBangunan(string kodeHuruf, string namaBangunan, int price, int TeakTree, int SandalwoodTree, int AloeTree, int IronwoodTree)
{
  try
  {
    pakaiMaterial(price, TeakTree, SandalwoodTree, AloeTree, IronwoodTree);
    Bangunan b(kodeHuruf, namaBangunan, price);
    this->bangunan.push_back(b);
    cout << namaBangunan << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
  }
  catch (const MaterialTidakCukupException &e)
  {
    cout << e.what();
    cout << " Masih memerlukan ";
    if (this->uang < price)
    {
      cout << price - this->uang << " gulden";
    }
    if (this->TeakWood < TeakTree)
    {
      cout << ", " << TeakTree - this->TeakWood << " teak wood";
    }
    if (this->AloeWood < AloeTree)
    {
      cout << ", " << AloeTree - this->AloeWood << " aloe wood";
    }
    if (this->IronWood < IronwoodTree)
    {
      cout << ", " << IronwoodTree - this->IronWood << " ironwood wood";
    }
    if (this->SandalWood < SandalwoodTree)
    {
      cout << ", " << SandalwoodTree - this->SandalWood << " sandal wood";
    }
    cout << "!" << endl;
  }
}

void Walikota::pakaiMaterial(int price, int TeakTree, int SandalwoodTree, int AloeTree, int IronwoodTree)
{
  if (this->uang < price || this->TeakWood < TeakTree || this->SandalWood < SandalwoodTree || this->IronWood < IronwoodTree)
  {
    throw MaterialTidakCukupException();
  }
  this->uang -= price;
  this->TeakWood -= TeakTree;
  this->SandalWood -= SandalwoodTree;
  this->AloeWood -= AloeTree;
  this->IronWood -= IronwoodTree;
}

void Walikota::tambahGulden(int num)
{
  this->uang += num;
}

void Walikota::tambahTeakWood(int num)
{
  this->TeakWood += num;
}

void Walikota::tambahSandalWood(int num)
{
  this->SandalWood += num;
}

void Walikota::tambahAloeWood(int num)
{
  this->AloeWood += num;
}

void Walikota::tambahIronWood(int num)
{
  this->IronWood += num;
}

void Walikota::setTeakWood(int num)
{
  this->TeakWood = num;
}

void Walikota::setSandalWood(int num)
{
  this->SandalWood = num;
}

void Walikota::setAloeWood(int num)
{
  this->AloeWood = num;
}

void Walikota::setIronWood(int num)
{
  this->IronWood = num;
}

void Walikota::addPetani() {}

void Walikota::addPeternak() {}

void Walikota::jual() {}

void Walikota::beli() {}