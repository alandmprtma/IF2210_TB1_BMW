#include "Peternak.hpp"

Peternak::Peternak()
{
    this->peran = "Peternak";
    this->dataTernak = Ternak(8, 8); /* Untuk Sementara. Default 8 x 8*/
}

Peternak::Peternak(string username, int uang, int berat_badan, PetiRahasia data, Ternak dataTernak, int jumlahBangunan) : Player(username, uang, berat_badan, data), Toko()
{
    this->peran = "Peternak";
    this->dataTernak = dataTernak;
    this->jumlahBangunan = jumlahBangunan;
}

void Peternak::simpanTernak()
{
    cout << "Pilih hewan dari penyimpanan" << endl
         << endl;
    this->data.cetakPenyimpanan();

    /* Memilih hewan dari peti rahasia */
    string slot;
    cout << endl
         << "Slot: ";
    cin >> slot;
    int row = (int)stoi(slot.substr(1, 2)) - 1;
    int col = ((int)slot[0] - 'A');

    Item *selectedAnimal = data.getElement(row, col);
    data.removeElement(row, col);
    cout << endl
         << "Kamu memilih " << selectedAnimal->getNama() << "." << endl;

    /* Construct hewan baru */
    Animal newAnimal(selectedAnimal->getKodeHuruf(), selectedAnimal->getNama(), selectedAnimal->getTipe(), 0, 0);

    cout << endl
         << "Pilih petak tanah yang akan ditinggali" << endl
         << endl;
    dataTernak.cetakPenyimpanan();

    /* Memilih area untuk ditinggali hewan */
    string petakTanah;
    cout << endl
         << "Petak tanah: ";
    cin >> petakTanah;
    int rowPetak = (int)stoi(petakTanah.substr(1, 2)) - 1;
    int colPetak = ((int)petakTanah[0] - 'A');

    /* Menyimpan hewan */
    cout << endl
         << "Dengan hati-hati, kamu meletakkan seekor " << newAnimal.getNama() << " di kandang." << endl;
    dataTernak.setElement(&newAnimal, rowPetak, colPetak);
    cout << endl
         << newAnimal.getNama() << " telah menjadi peliharaanmu sekarang!" << endl;
}

void Peternak::beriMakanHewanTernak(GameObject objek)
{
    cout << "Pilih petak kandang yang akan diberi makan" << endl
         << endl;
    dataTernak.cetakPenyimpanan();

    /* Memilih hewan dari ternak*/
    string slot;
    cout << endl
         << "Petak Kandang: ";
    cin >> slot;
    int row = (int)stoi(slot.substr(1, 2)) - 1;
    int col = ((int)slot[0] - 'A');

    Animal selectedAnimal = *dataTernak.getElement(row, col);
    cout << endl
         << "Kamu memilih " << selectedAnimal.getNama() << " untuk diberi makan." << endl;

    /* Memilih pangan */
    cout << "Pilih pangan yang akan diberikan: " << endl
         << endl;
    data.cetakPenyimpanan();

    string petakTanah;
    cout << endl
         << "Slot: ";
    cin >> petakTanah;
    int rowPetak = (int)stoi(petakTanah.substr(1, 2)) - 1;
    int colPetak = ((int)petakTanah[0] - 'A');

    Item *selectedProduct = data.getElement(rowPetak, colPetak);

    /* Construct Produk Baru */
    Produk newProduk = objek.findProduk(selectedProduct->getNama());

    /* Kondisi */
    int addWeight = 0;

    if (selectedAnimal.getTipe() == "HERBIVORE" && newProduk.getTipe() == "PRODUCT_FRUIT_PLANT")
    {
        addWeight = newProduk.getBeratTambahan();
    }
    else if (selectedAnimal.getTipe() == "CARNIVORE" && newProduk.getTipe() == "ANIMAL_FRUIT_PLANT")
    {
        addWeight = newProduk.getBeratTambahan();
    }
    else if (selectedAnimal.getTipe() == "OMNIVORE")
    {
        addWeight = newProduk.getBeratTambahan();
    }

    data.removeElement(rowPetak, colPetak);

    /* Menambahkan berat badan ke hewan ternak */
    int currentWeight = selectedAnimal.getBerat();
    int newWeight = currentWeight + addWeight;
    selectedAnimal.setBerat(newWeight);
    cout << endl
         << selectedAnimal.getNama() << " telah diberi makan dan beratnya menjadi " << selectedAnimal.getBerat() << endl;
}

void Peternak::isSlotValid(string slot)
{
    std::regex slotFormat("[A-Za-z][0-9]{2}");

    if (!std::regex_match(slot, slotFormat))
    {
        throw SlotTidakValid();
    }
}

void Peternak::panenTernak(GameObject objek)
{
    try
    {
        vector<Animal *> hewanDapatDipanen;
        std::map<std::string, std::pair<int, int>> hewanSiapPanen;

        dataTernak.cetakPenyimpanan();

        /* Menampilkan hewan ternak yang tersedia */
        char columnChar = 'A';

        cout << endl;
        for (int i = 0; i < dataTernak.getM(); ++i)
        {
            std::string rowNumber = std::to_string(i + 1);
            if (rowNumber.size() == 1)
            {
                rowNumber = "0" + rowNumber;
            }

            for (int j = 0; j < dataTernak.getN(); ++j)
            {
                if (dataTernak.getElementNoException(i, j) != nullptr)
                {
                    std::cout << "- " << columnChar << rowNumber << ": " << dataTernak.getElementNoException(i, j)->getKodeHuruf() << std::endl;
                }
                ++columnChar;
            }
            columnChar = 'A'; // Reset columnChar for the next row
        }

        cout << endl
             << "Pilih hewan siap panen yang kamu miliki" << endl;

        size_t index = 1;
        for (int i = 0; i < dataTernak.getM(); ++i)
        {
            std::string rowNumber = std::to_string(i + 1);
            if (rowNumber.size() == 1)
            {
                rowNumber = "0" + rowNumber;
            }

            for (int j = 0; j < dataTernak.getN(); ++j)
            {
                if (dataTernak.getElementNoException(i, j) != nullptr)
                {
                    // Memasukkan hewan ke vector hewan yang dapat dipanen
                    if (dataTernak.getElementNoException(i, j)->getBerat() >= dataTernak.getElementNoException(i, j)->getBeratPanen())
                    {
                        hewanDapatDipanen.push_back(dataTernak.getElementNoException(i, j));
                        // Menambahkan jumlah petak siap panen berdasarkan kode hewan
                        std::string kodeHewan = dataTernak.getElementNoException(i, j)->getKodeHuruf();
                        if (hewanSiapPanen.find(kodeHewan) == hewanSiapPanen.end())
                        {
                            // Jika kode hewan belum ada dalam map, tambahkan entri baru
                            hewanSiapPanen[kodeHewan] = std::make_pair(index++, 1);
                        }
                        else
                        {
                            // Jika kode hewan sudah ada dalam map, tambahkan jumlah petak siap panen
                            hewanSiapPanen[kodeHewan].second++;
                        }
                    }
                }
                ++columnChar;
            }
            columnChar = 'A';
        }

        if (hewanSiapPanen.empty())
        {
            throw LadangDontHaveAnimal();
        }

        /* Menampilkan hewan yang dapat dipanen dengan jumlah petak siap panen */
        for (const auto& pair : hewanSiapPanen) {
            cout << pair.second.first << ". " << pair.first << " (" << pair.second.second << " petak siap panen)" << endl;
        }

        /* Memilih hewan dan jumlah petak yang akan dipanen */
        while (true)
        {
            cout << endl
                 << "Pilih nomor hewan yang akan dipanen: ";
            if (!(cin >> index))
            {
                cout << "Input tidak valid!" << endl;

                cin.clear();

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (index < 1 || index > hewanDapatDipanen.size())
            {
                cout << "Nomor hewan yang dipilih tidak valid!" << endl;
            }
            else
            {
                break;
            }
        }
        int numPetak;
        while (true)
        {
            cout << "Berapa petak yang ingin dipanen: ";
            if (!(cin >> numPetak))
            {
                cout << "Input tidak valid!" << endl;

                cin.clear();

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (numPetak > hewanSiapPanen[hewanDapatDipanen[index - 1]->getKodeHuruf()].second)
            {
                cout << "Jumlah petak yang ingin dipanen melebihi jumlah petak yang siap panen!" << endl;
            }
            else if (numPetak <= 0)
            {
                cout << "Jumlah petak yang ingin dipanen tidak boleh kurang dari atau sama dengan 0!" << endl;
            }
            else
            {
                break;
            }
        }

        /* Memilih petak yang ingin dipanen */
        cout << endl
             << "Pilih petak yang ingin dipanen" << endl;
        vector<Animal *> hewanDipanen;
        vector<string> petakDipanen;
        for (int i = 0; i < numPetak; i++)
        {
            while (true)
            {
                string petakTanah;
                cout << "Petak ke-" << i + 1 << " : ";
                cin >> petakTanah;
                isSlotValid(petakTanah);

                int rowPetak = (int)stoi(petakTanah.substr(1, 2)) - 1;
                int colPetak = ((int)petakTanah[0] - 'A');
                if (dataTernak.getElementNoException(rowPetak, colPetak) != nullptr)
                {
                    if (dataTernak.getElementNoException(rowPetak, colPetak)->getId_Hewan() == hewanDapatDipanen[index - 1]->getId_Hewan())
                    {
                        hewanDipanen.push_back(dataTernak.getElement(rowPetak, colPetak));
                        getTernak().removeElement(rowPetak, colPetak);
                        petakDipanen.push_back(petakTanah);
                        break;
                    }
                }
                cout << endl << "Hewan yang dipilih tidak sesuai dengan petak yang dipilih" << endl;
                cin.clear();

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        // TODO : Ganti index tanamanDipanen menjadi benar
        cout << endl
             << numPetak << " petak tanaman " << hewanDipanen[0]->getKodeHuruf() << " pada petak ";
        for (size_t i = 0; i < petakDipanen.size(); i++)
        {
            cout << petakDipanen[i];
            if (i != petakDipanen.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << " telah dipanen!" << endl;

        /* Memasukkan ke inventory sebagai produk */
        // int row = 0;
        // int col = 0;

        for (size_t i = 0; i < hewanDipanen.size(); i++)
        {
            for (size_t j = 0; j < objek.getProdukList().size(); j++)
            {
                if (objek.getProdukList()[j].getOrisinil() == hewanDipanen[i]->getNama())
                {
                    Produk newProduk = objek.getProdukList()[j];

                    data = data + new Produk(newProduk);
                    /* Mencari petak kosong pada penyimpanan */
                    // while (data.getElementNoException(row, col) != nullptr) {
                    //     col++;
                    //     if (col == data.getN()) {
                    //         col = 0;
                    //         row++;
                    //     }
                    // }

                    // data.setElement(new Produk(newProduk), row, col);
                }
            }
        }
    }
    catch (LadangDontHaveAnimal &e) {
        cout << e.what() << endl;
    }
    catch (SlotTidakValid &e)
    {
        cout << e.what() << endl;
    }
}

Ternak &Peternak::getTernak()
{
    return this->dataTernak;
}

float Peternak::getPajak()
{
    return 1.00;
}

void Peternak::beli() {}

void Peternak::jual() {}

void Peternak::printPlayer()
{
    cout << "ID Player: " << this->IdPlayer << endl;
    cout << "Username: " << this->username << endl;
    cout << "Berat Badan: " << this->getBeratBadan() << endl;
    cout << "Peran: " << this->peran << endl;
}