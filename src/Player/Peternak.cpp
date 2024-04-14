#include "Peternak.hpp"

Peternak::Peternak() {
    this->peran = "Peternak";
    this->dataTernak = Ternak(8, 8); /* Untuk Sementara. Default 8 x 8*/
}

Peternak::Peternak(string username,int uang, int berat_badan, PetiRahasia data,Ternak dataTernak, int jumlahBangunan) :Player(username,uang,berat_badan,data), Toko() {
    this->peran = "Peternak";
    this->dataTernak = dataTernak;
    this->jumlahBangunan = jumlahBangunan;
}

void Peternak::simpanTernak() {
    cout << "Pilih hewan dari penyimpanan" << endl << endl;
    this->data.cetakPeti("Peti Rahasia");

    /* Memilih hewan dari peti rahasia */
    string slot;
    cout << endl << "Slot: ";
    cin >> slot;
    int row = (int) stoi(slot.substr(1, 2)) - 1;
    int col = ((int) slot[0] - 'A');

    Item* selectedAnimal = data.getElement(row, col);
    data.removeElement(row, col);
    cout << endl << "Kamu memilih " << selectedAnimal->getNama() << "." << endl;

    /* Construct hewan baru */
    Animal newAnimal(selectedAnimal->getKodeHuruf(), selectedAnimal->getNama(), selectedAnimal->getTipe(), 0, 0);

    cout << endl << "Pilih petak tanah yang akan ditinggali" << endl << endl;
    dataTernak.cetakTernak("Ternak");

    /* Memilih area untuk ditinggali hewan */
    string petakTanah;
    cout << endl << "Petak tanah: ";
    cin >> petakTanah;
    int rowPetak = (int) stoi(petakTanah.substr(1, 2)) - 1;
    int colPetak = ((int) petakTanah[0] - 'A');

    /* Menyimpan hewan */
    cout << endl << "Dengan hati-hati, kamu meletakkan seekor " << newAnimal.getNama() << " di kandang."<< endl;
    dataTernak.setElement(newAnimal, rowPetak, colPetak);
    cout << endl << newAnimal.getNama() << " telah menjadi peliharaanmu sekarang!" << endl;
}

void Peternak::beriMakanHewanTernak() {}

void Peternak::panenTernak() {}

Ternak Peternak::getTernak() {
    return this->dataTernak;
}

float Peternak::getPajak() {
    return 1.00;
}

void Peternak::beli() {}

void Peternak::jual() {}

void Peternak::printPlayer() {
    cout << "ID Player: " << this->IdPlayer << endl;
    cout << "Username: " << this->username << endl;
    cout << "Berat Badan: " << this->getBeratBadan() << endl;
    cout << "Peran: " << this->peran << endl;
}