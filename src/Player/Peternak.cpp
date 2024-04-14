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
    dataTernak.setElement(&newAnimal, rowPetak, colPetak);
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

    Animal selectedAnimal = *dataTernak.getElement(row, col);
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

void Peternak::panenTernak(GameObject objek) {
    vector<Animal*> hewanDapatDipanen;
    std::map<std::string, std::pair<int, int>> hewanSiapPanen; 

    dataTernak.cetakTernak("Peternakan");

    /* Menampilkan hewan ternak yang tersedia */
    char columnChar = 'A';

    cout << endl;
    for (int i = 0; i < dataTernak.getM(); ++i) {
        std::string rowNumber = std::to_string(i + 1);
        if (rowNumber.size() == 1) {
            rowNumber = "0" + rowNumber;
        }

        for (int j = 0; j < dataTernak.getN(); ++j) {
            if (dataTernak.getElement(i, j) != nullptr) {
                std::cout << "- " << columnChar << rowNumber << ": " << dataTernak.getElement(i, j)->getKodeHuruf() << std::endl;
            }
            ++columnChar;
        }
        columnChar = 'A'; // Reset columnChar for the next row
    }

    cout << endl << "Pilih hewan siap panen yang kamu miliki" << endl;

    int index = 1;
    for (int i = 0; i < dataTernak.getM(); ++i) {
        std::string rowNumber = std::to_string(i + 1);
        if (rowNumber.size() == 1) {
            rowNumber = "0" + rowNumber;
        }

        for (int j = 0; j < dataTernak.getN(); ++j) {
            if (dataTernak.getElement(i, j) != nullptr) {
                // Memasukkan hewan ke vector hewan yang dapat dipanen
                if (dataTernak.getElement(i, j)->getBerat() >= dataTernak.getElement(i, j)->getBeratPanen()) {
                    hewanDapatDipanen.push_back(dataTernak.getElement(i, j));
                    // Menambahkan jumlah petak siap panen berdasarkan kode hewan
                    std::string kodeHewan = dataTernak.getElement(i, j)->getKodeHuruf();
                    if (hewanSiapPanen.find(kodeHewan) == hewanSiapPanen.end()) {
                        // Jika kode hewan belum ada dalam map, tambahkan entri baru
                        hewanSiapPanen[kodeHewan] = std::make_pair(index++, 1);
                    } else {
                        // Jika kode hewan sudah ada dalam map, tambahkan jumlah petak siap panen
                        hewanSiapPanen[kodeHewan].second++;
                    }
                }
            }
            ++columnChar;
        }
        columnChar = 'A';
    }

    /* Menampilkan hewan yang dapat dipanen dengan jumlah petak siap panen */
    for (const auto& pair : hewanSiapPanen) {
        cout << pair.second.first << ". " << pair.first << " (" << pair.second.second << " petak siap panen)" << endl;
    }

    /* Memilih hewan dan jumlah petak yang akan dipanen */
    int indexAnimal;
    cout << endl << "Pilih nomor hewan yang akan dipanen: ";
    cin >> index;

    // Belum Validasi Input Index 

    int numPetak;
    cout << endl << "Berapa petak yang ingin dipanen: ";
    cin >> numPetak;

    /* Memilih petak yang ingin dipanen */
    cout << endl << "Pilih petak yang ingin dipanen" << endl;
    vector<Animal*> hewanDipanen;
    vector<string> petakDipanen;
    for (int i = 0; i < numPetak; i++) {
        string petakTanah;
        cout << "Petak ke-" << i + 1 << " : ";
        cin >> petakTanah;

        int rowPetak = (int) stoi(petakTanah.substr(1, 2)) - 1;
        int colPetak = ((int) petakTanah[0] - 'A');

        hewanDipanen.push_back(dataTernak.getElement(rowPetak, colPetak));
        dataTernak.removeElement(rowPetak, colPetak);
        petakDipanen.push_back(petakTanah);
    }

    // TODO : Ganti index tanamanDipanen menjadi benar
    cout << endl << numPetak << " petak tanaman " << hewanDipanen[0]->getKodeHuruf() << " pada petak ";
    for (int i = 0; i < petakDipanen.size(); i++) {
        cout << petakDipanen[i];
        if (i != petakDipanen.size() - 1) {
            cout << ", ";
        }
    }
    cout << " telah dipanen!" << endl;

    /* Memasukkan ke inventory sebagai produk */
    int row = 0;
    int col = 0;

    for (int i = 0; i < hewanDipanen.size(); i++) {
        for (int j = 0; j < objek.getProdukList().size(); j++) {
            if (objek.getProdukList()[j].getOrisinil() == hewanDipanen[i]->getNama()) {
                Produk newProduk = objek.getProdukList()[j];

                /* Mencari petak kosong pada penyimpanan */
                while (data.getElement(row, col) != nullptr) {
                    col++;
                    if (col == data.getN()) {
                        col = 0;
                        row++;
                    }
                }

                data.setElement(new Produk(newProduk), row, col);
            }
        }
    }
}

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