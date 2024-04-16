#include "Petani.hpp"

Petani::Petani() : Player(), Toko()
{
    this->peran = "Petani";
    this->dataLadang = Ladang(8, 8); /* Untuk Sementara. Default 8 x 8*/
}

Petani::Petani(string username, int uang, int berat_badan, PetiRahasia data, Ladang dataLadang, int jumlahBangunan) : Player(username, uang, berat_badan, data), Toko()
{
    this->peran = "Petani";
    this->dataLadang = dataLadang;
    this->jumlahBangunan = jumlahBangunan;
}

void Petani::isInventoryFull()
{
    bool isFilled = true;

    for (int i = 0; i < data.getM(); i++)
    {
        for (int j = 0; j < data.getN(); j++)
        {
            if (data.getElementNoException(i, j) == nullptr)
            {
                isFilled = false;
                break;
            }
        }
        if (!isFilled)
            break;
    }
    if (isFilled)
        throw PenyimpananSudahPenuh();
}

void Petani::isElementTanaman(int i, int j)
{
    if (data.getElementNoException(i, j) != nullptr)
    {
        if (data.getElementNoException(i, j)->getTipe() != "MATERIAL_PLANT" && data.getElementNoException(i, j)->getTipe() != "FRUIT_PLANT")
        {
            throw ElementNotPlant();
        }
    }
    else
    {
        throw ElementNotFound();
    }
}

void Petani::isInventoryHavePlant()
{
    bool isHavePlant = false;

    for (int i = 0; i < data.getM(); i++)
    {
        for (int j = 0; j < data.getN(); j++)
        {
            if (data.getElementNoException(i, j) != nullptr)
            {
                if (data.getElementNoException(i, j)->getTipe() == "MATERIAL_PLANT" || data.getElementNoException(i, j)->getTipe() == "FRUIT_PLANT"){
                    isHavePlant = true;
                    break;
                }
            }
        }
        if (isHavePlant)
            break;
    }
    if (!isHavePlant)
        throw PenyimpananDontHavePlant();
}

void Petani::isElementKosong(int i, int j){
    if (dataLadang.getElementNoException(i, j) != nullptr){
        throw SlotSudahTerisi();
    }
}

void Petani::isSlotValid(string slot){
    std::regex slotFormat("[A-Za-z][0-9]{2}");

    if (!std::regex_match(slot, slotFormat)) {
        throw SlotTidakValid();
    }
}

void Petani::tanamTanaman()
{
    try
    {
        isInventoryFull();
        isInventoryHavePlant();
        cout << "Pilih tanaman dari penyimpanan" << endl
             << endl;
        data.cetakPenyimpanan();

        while (true)
        {
            try
            {
                string slot;
                cout << endl
                     << "Slot: ";
                cin >> slot;
                isSlotValid(slot);
                int row = (int)stoi(slot.substr(1, 2)) - 1;
                int col = ((int)slot[0] - 'A');

                isIndexValid(row, col, data.getM(), data.getN());
                isElementTanaman(row, col);
                Item *selectedPlant = data.getElement(row, col);
                data.removeElement(row, col);
                cout << endl
                     << "Kamu memilih " << selectedPlant->getNama() << "." << endl;

                /* Construct tanaman baru */
                Plant newPlant(selectedPlant->getKodeHuruf(), selectedPlant->getNama(), selectedPlant->getTipe(), 0, 0);

                cout << endl
                     << "Pilih petak tanah yang akan ditanami" << endl
                     << endl;
                dataLadang.cetakPenyimpanan();

                /* Memilih area untuk ditanami tanaman */
                string petakTanah;
                cout << endl
                     << "Petak tanah: ";
                cin >> petakTanah;
                isSlotValid(petakTanah);
                int rowPetak = (int)stoi(petakTanah.substr(1, 2)) - 1;
                int colPetak = ((int)petakTanah[0] - 'A');
                isElementKosong(rowPetak, colPetak);
                /* Menanam Tanaman */
                cout << endl
                     << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
                dataLadang.setElement(&newPlant, rowPetak, colPetak);
                cout << newPlant.getNama() << " berhasil ditanam!" << endl;
                data.cetakPenyimpanan();
                dataLadang.cetakPenyimpanan();
                break;
            }
            catch(const SlotTidakValid &e){
                cout << e.what() << endl;
            }
            
            catch(const SlotSudahTerisi &e){
                cout << e.what() << endl;
            }
            catch (const IndexOutOfBound &e)
            {
                cout << e.what() << endl;
            }
            catch (const ElementNotFound &e)
            {
                cout << e.what() << endl;
            }
            catch (const ElementNotPlant &e)
            {
                cout << e.what() << endl;
            }
        }
    }
    catch (const PenyimpananSudahPenuh &e)
    {
        cout << e.what() << endl;
    }
    catch (const PenyimpananDontHavePlant &e)
    {
        cout << e.what() << endl;
    }
}

void Petani::panenTanaman(GameObject objek)
{
    vector<Plant *> tanamanDapatDipanen;
    std::map<std::string, std::pair<int, int>> tanamanSiapPanen;

    dataLadang.cetakPenyimpanan();

    /* Menampilkan tanaman yang tersedia */
    char columnChar = 'A';

    cout << endl;
    for (int i = 0; i < dataLadang.getM(); ++i)
    {
        std::string rowNumber = std::to_string(i + 1);
        if (rowNumber.size() == 1)
        {
            rowNumber = "0" + rowNumber;
        }

        for (int j = 0; j < dataLadang.getN(); ++j)
        {
            if (dataLadang.getElementNoException(i, j) != nullptr)
            {
                std::cout << "- " << columnChar << rowNumber << ": " << dataLadang.getElementNoException(i, j)->getKodeHuruf() << std::endl;
            }
            ++columnChar;
        }
        columnChar = 'A'; // Reset columnChar for the next row
    }

    cout << endl
         << "Pilih tanaman siap panen yang kamu miliki" << endl;

    int index = 1;
    for (int i = 0; i < dataLadang.getM(); ++i)
    {
        std::string rowNumber = std::to_string(i + 1);
        if (rowNumber.size() == 1)
        {
            rowNumber = "0" + rowNumber;
        }

        for (int j = 0; j < dataLadang.getN(); ++j)
        {
            if (dataLadang.getElementNoException(i, j) != nullptr)
            {
                // Memasukkan tanaman ke vector hewan yang dapat dipanen
                if (dataLadang.getElementNoException(i, j)->getUmur() >= dataLadang.getElementNoException(i, j)->getDurasiPanen())
                {
                    tanamanDapatDipanen.push_back(dataLadang.getElementNoException(i, j));
                    // Menambahkan jumlah petak siap panen berdasarkan kode tanaman
                    std::string kodeTanaman = dataLadang.getElementNoException(i, j)->getKodeHuruf();
                    if (tanamanSiapPanen.find(kodeTanaman) == tanamanSiapPanen.end())
                    {
                        // Jika kode tanaman belum ada dalam map, tambahkan entri baru
                        tanamanSiapPanen[kodeTanaman] = std::make_pair(index++, 1);
                    }
                    else
                    {
                        // Jika kode tanaman sudah ada dalam map, tambahkan jumlah petak siap panen
                        tanamanSiapPanen[kodeTanaman].second++;
                    }
                }
            }
            ++columnChar;
        }
        columnChar = 'A';
    }

    /* Menampilkan tanaman yang dapat dipanen dengan jumlah petak siap panen */
    for (const auto &pair : tanamanSiapPanen)
    {
        cout << pair.second.first << ". " << pair.first << " (" << pair.second.second << " petak siap panen)" << endl;
    }

    /* Memilih tanaman dan jumlah petak yang akan dipanen */
    cout << endl
         << "Pilih nomor hewan yang akan dipanen: ";
    cin >> index;

    // Belum Validasi Input Index

    int numPetak;
    cout << endl
         << "Berapa petak yang ingin dipanen: ";
    cin >> numPetak;

    /* Memilih petak yang ingin dipanen */
    cout << endl
         << "Pilih petak yang ingin dipanen" << endl;
    vector<Plant *> tanamanDipanen;
    vector<string> petakDipanen;
    for (int i = 0; i < numPetak; i++)
    {
        string petakTanah;
        cout << "Petak ke-" << i + 1 << " : ";
        cin >> petakTanah;

        int rowPetak = (int)stoi(petakTanah.substr(1, 2)) - 1;
        int colPetak = ((int)petakTanah[0] - 'A');

        tanamanDipanen.push_back(dataLadang.getElement(rowPetak, colPetak));
        getLadang().removeElement(rowPetak, colPetak);
        petakDipanen.push_back(petakTanah);
    }

    // TODO : Ganti index tanamanDipanen menjadi benar
    cout << endl
         << numPetak << " petak tanaman " << tanamanDipanen[0]->getKodeHuruf() << " pada petak ";
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

    for (size_t i = 0; i < tanamanDipanen.size(); i++)
    {
        for (size_t j = 0; j < objek.getProdukList().size(); j++)
        {
            if (objek.getProdukList()[j].getOrisinil() == tanamanDipanen[i]->getNama())
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

void Petani::tambahUmurTanaman(int umurTambahan, int row, int col)
{
    Plant *tanaman = dataLadang.getElement(row, col);
    tanaman->setUmur(tanaman->getUmur() + umurTambahan);
}

Ladang &Petani::getLadang()
{
    return this->dataLadang;
}

float Petani::getPajak()
{
    return 1.00;
}

void Petani::jual() {}

void Petani::beli() {}

void Petani::printPlayer()
{
    cout << "ID Player: " << this->IdPlayer << endl;
    cout << "Username: " << this->username << endl;
    cout << "Uang: " << this->uang << endl;
    cout << "Berat Badan: " << getBeratBadan() << endl;
    cout << "Peran: " << this->peran << endl;
}