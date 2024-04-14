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
    this->data.cetakPeti("Penyimpanan");

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
    dataTernak.cetakTernak("Peternakan");

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

void Peternak::beriMakanHewanTernak(GameObject objek) {
    cout << "Pilih petak kandang yang akan diberi makan" << endl << endl;
    dataTernak.cetakTernak("Peternakan");

    /* Memilih hewan dari ternak*/
    string slot;
    cout << endl << "Petak Kandang: ";
    cin >> slot;
    int row = (int) stoi(slot.substr(1, 2)) - 1;
    int col = ((int) slot[0] - 'A');

    Animal selectedAnimal = dataTernak.getElement(row, col);
    cout << endl << "Kamu memilih " << selectedAnimal.getNama() << " untuk diberi makan." << endl;

    /* Memilih pangan */
    cout << "Pilih pangan yang akan diberikan: " << endl << endl;
    data.cetakPeti("Penyimpanan");

    string petakTanah;
    cout << endl << "Slot: ";
    cin >> petakTanah;
    int rowPetak = (int) stoi(petakTanah.substr(1, 2)) - 1;
    int colPetak = ((int) petakTanah[0] - 'A');

    Item* selectedProduct = data.getElement(rowPetak, colPetak);

    /* Construct Produk Baru */
    Produk newProduk = objek.findProduk(selectedProduct->getNama());

    /* Kondisi */
    int addWeight = 0;

    if (selectedAnimal.getTipe() == "HERBIVORE" && newProduk.getTipe() == "PRODUCT_FRUIT_PLANT") {
        addWeight = newProduk.getBeratTambahan();
    } else if (selectedAnimal.getTipe() == "CARNIVORE" && newProduk.getTipe() == "ANIMAL_FRUIT_PLANT") {
        addWeight = newProduk.getBeratTambahan();
    } else if (selectedAnimal.getTipe() == "OMNIVORE") {
        addWeight = newProduk.getBeratTambahan();
    }

    data.removeElement(rowPetak, colPetak);

    /* Menambahkan berat badan ke hewan ternak */
    int currentWeight = selectedAnimal.getBerat();
    int newWeight = currentWeight + addWeight;
    selectedAnimal.setBerat(newWeight);
    cout << endl << selectedAnimal.getNama() << " telah diberi makan dan beratnya menjadi " << selectedAnimal.getBerat() << endl;
}

void Peternak::panenTernak() {}

Ternak& Peternak::getTernak() {
    return this->dataTernak;
}

float Peternak::getPajak() {
    return 1.00;
}
Ternak Peternak::getPeternakan(){
    return dataTernak;
}


void Peternak::beli() {}

void Peternak::jual() {}

void Peternak::printPlayer() {
    cout << "ID Player: " << this->IdPlayer << endl;
    cout << "Username: " << this->username << endl;
    cout << "Berat Badan: " << this->getBeratBadan() << endl;
    cout << "Peran: " << this->peran << endl;
}