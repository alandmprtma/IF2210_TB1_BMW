#include "GameStatus.hpp"

GameStatus::GameStatus()
{
    playerTurnList = vector<Player *>();
    petaniList = vector<Petani>();
    peternakList = vector<Peternak>();
    walikota = Walikota();
    turn = 0;
    endGame = false;
}

bool GameStatus::isEndGame(GameObject objek)
{
    for (size_t i = 0; i < playerTurnList.size() && !endGame; i++)
    {
        if (playerTurnList[i]->getUang() >= objek.getWinGulden() &&
            playerTurnList[i]->getBeratBadan() >= objek.getWinWeight())
        {
            endGame = true;
            cout << playerTurnList[i]->getUsername() << " berhasil memenangkan permainan !" << endl;
        }
    }
    return endGame;
}
void GameStatus::lexicographicSort() {
    // Selection Sort
    int n = this->playerTurnList.size();
    for (int i = 0; i < n-1; ++i) {
        int min = i;
        int j = min;
        while (j < n)
        {
            if (playerTurnList[min]->getUsername() > playerTurnList[j]->getUsername()){
                min = j;
            }

            j++;
        }
        // Swap
        Player* temp = playerTurnList[i];
        playerTurnList[i] = playerTurnList[min];
        cout<<"min: "<<min<<" "<<playerTurnList[min]->getUsername()<<endl;
        playerTurnList[min] = temp;
        cout<<"temp: "<<temp->getUsername()<<endl;

        cout<<playerTurnList[i]->getUsername()<<endl;
    }
    cout<<playerTurnList.size()<<endl;
    for (size_t i = 0;i<playerTurnList.size();i++){
        cout<<playerTurnList[i]->getUsername()<<endl;
    }
}
void GameStatus::nextTurn(GameObject objek){
    // TODO turn ++, umur ladang ++
    turn = (turn + 1) % this->playerTurnList.size();
    for (size_t i = 0; i < petaniList.size(); i++)
    {
        for (int j = 0; j < objek.getSizeCrops()[0]; j++)
        {
            for (int k = 0; k < objek.getSizeCrops()[1]; k++)
            {
                // set umur tiap tanaman = umur + 1, ntar ae dah
                if (this->petaniList[i].getLadang().getElementNoException(j, k) != nullptr)
                {
                    if (!(*this->petaniList[i].getLadang().getElementNoException(j, k) == Plant()))
                    {
                        this->petaniList[i].getLadang().getElementNoException(j, k)->setUmur(
                            this->petaniList[i].getLadang().getElementNoException(j, k)->getUmur() + 1);
                    }
                }
            }
        }
    }
    cout << "Sekarang Giliran " << getCurrentPlayer()->getUsername() << " untuk Jalan!" << endl;
}

void GameStatus::Inisiasi(GameObject objek)
{

    // TODO muat state.txt atau muat default

    int opsi;
    do
    {
        cout << "Pilihlah cara memuat state permainan ! " << endl;
        cout << "1. Default" << endl;
        cout << "2. Membaca berkas" << endl;
        cout << endl << "Masukkan opsi memulai game yang diinginkan ! " << endl;
        cout << "Opsi: ";
        cin >> opsi;
        cout << endl;
        if (opsi != 1 && opsi != 2)
        {
            cout << "Opsi di luar jangkauan !" << endl;
        }
    } while (opsi <= 0 || opsi > 2);

    if (opsi == 1)
    {
        Petani petani = Petani("Petani1", 50, 40,
                               PetiRahasia(objek.getSizeInventory()[0], objek.getSizeInventory()[1]),
                               Ladang(objek.getSizeCrops()[0], objek.getSizeCrops()[1]),
                               0);
        Peternak peternak = Peternak("Peternak1", 50, 40,
                                     PetiRahasia(objek.getSizeInventory()[0], objek.getSizeInventory()[1]),
                                     Ternak(objek.getSizeFarm()[0], objek.getSizeFarm()[1]),
                                     0);
        Walikota wal = Walikota("Walikota", 50, 40,
                                PetiRahasia(8, 8));

        // store player
        this->walikota = wal;
        this->petaniList.push_back(petani);
        this->peternakList.push_back(peternak);
        this->playerTurnList.push_back(&this->petaniList[0]);
        this->playerTurnList.push_back(&this->peternakList[0]);
        this->playerTurnList.push_back(&this->walikota);

        // order player turn
        this->lexicographicSort();

    }else if (opsi==2){
        // TODO command muat
        this->muat("./Config/coba.txt", objek);

        // store player
        for (size_t i = 0; i < peternakList.size(); i++)
        {
            this->playerTurnList.push_back(&this->peternakList[i]);
        }
        for (size_t i = 0; i < petaniList.size(); i++)
        {
            this->playerTurnList.push_back(&this->petaniList[i]);
        }
        this->playerTurnList.push_back(&this->walikota);

        // sort player turn order
        this->lexicographicSort();

        // for (size_t i = 0;i < peternakList.size();i++){
        //     cout<<peternakList[i].getUsername()<<endl;
        //     peternakList[i].getData().cetakPenyimpanan();
        //     peternakList[i].getTernak().cetakPenyimpanan();
        // }
        // for (size_t i = 0;i<this->petaniList.size();i++){
        //     cout<<petaniList[i].getUsername()<<endl;
        //     petaniList[i].getData().cetakPenyimpanan();
        //     petaniList[i].getLadang().cetakPenyimpanan();
        // }
        // cout<<walikota.getUsername()<<endl;
        // walikota.getData().cetakPenyimpanan();

        // cout<<"TOKO CHINA"<<endl;
        // for (const auto& pair : toko.getStok()){
        //     cout<<pair.first<<" "<<pair.second<<endl;
        // }

        // cout<<walikota.getUang()<<" "<<walikota.getBeratBadan()<<endl;
    }
}

Player *GameStatus::getCurrentPlayer() const
{
    if (this->playerTurnList.empty())
    {
        throw NoPLayerException();
    }
    return playerTurnList[turn];
}

Petani GameStatus::getPetani(string username)
{
    if (this->petaniList.empty())
    {
        throw NoPetaniException();
    }
    for (size_t i = 0; i < petaniList.size(); i++)
    {
        if (petaniList[i].getUsername() == username)
        {
            return petaniList[i];
        }
    }
    return Petani();
}

Peternak GameStatus::getPeternak(string username)
{
    if (this->peternakList.empty())
    {
        throw NoPeternakException();
    }
    for (size_t i = 0; i < peternakList.size(); i++)
    {
        if (peternakList[i].getUsername() == username)
        {
            return peternakList[i];
        }
    }
    return Peternak();
}

Walikota &GameStatus::getWalikota()
{
    return this->walikota;
}

Toko GameStatus::getToko()
{
    return this->toko;
}

Player *GameStatus::getPlayer(int num)
{
    return playerTurnList[num];
}

int GameStatus::stringToInt(string num)
{
    int n = 0;
    for (size_t i = 0; num[i] >= '0' && num[i] <= '9'; i++)
    {
        n *= 10;
        n += num[i] - '0';
    }

    return n;
}
// A -> 1, B->2
int GameStatus::charToInt(string char1)
{
    return (int)char1[0] - 'A';
}

int GameStatus::charToInt(char char1)
{
    return (int)char1 - 'A';
}

int GameStatus::getNumPlayers()
{
    return playerTurnList.size();
}

void GameStatus::muat(string path, GameObject objek)
{

    std::ifstream inputFile(path);

    if (!inputFile.is_open())
    {

        throw FileNotFoundError();
    }
    else
    {

        std::string line;
        std::getline(inputFile, line);
        int n_player = stringToInt(line);
        for (int i = 0; i < n_player; i++)
        {

            std::getline(inputFile, line);
            std::istringstream iss(line);

            std::string token;
            std::getline(iss, token, ' ');
            std::string userName = token;

            std::getline(iss, token, ' ');
            std::string tipe = token;

            std::getline(iss, token, ' ');
            int beratBadan = stringToInt(token);

            std::getline(iss, token, ' ');
            int uang = stringToInt(token);

            // inventory

            if (tipe == "Petani")
            {
                std::getline(inputFile, line);
                PetiRahasia data = PetiRahasia(objek.getSizeInventory()[0], objek.getSizeInventory()[1]);

                int max = stringToInt(line);
                int i = 0;
                int j = 0;
                int jumlahBangunan = 0;

                while (max > 0)
                {
                    if (j == objek.getSizeInventory()[1])
                    {
                        j = 0;
                        i++;
                    }
                    std::getline(inputFile, line);
                    if (!(objek.findPlant(line) == Plant()))
                    {
                        data.setElement(new Plant(objek.findPlant(line)), i, j);
                    }
                    else if (!(objek.findAnimal(line) == Animal()))
                    {
                        data.setElement(new Animal(objek.findAnimal(line)), i, j);
                    }
                    else if (!(objek.findProduk(line) == Produk()))
                    {
                        data.setElement(new Produk(objek.findProduk(line)), i, j);
                    }
                    else if (!(objek.findBangunan(line) == Bangunan()))
                    {
                        data.setElement(new Bangunan(objek.findBangunan(line)), i, j);
                        jumlahBangunan++;
                    }
                    j++;
                    max--;
                }
                Ladang lad = Ladang(objek.getSizeCrops()[0], objek.getSizeCrops()[1]);
                std::getline(inputFile, line);
                max = stringToInt(line);
                while (max > 0)
                {
                    std::getline(inputFile, line);
                    std::istringstream iss(line);

                    std::getline(iss, token, ' ');
                    int col = this->charToInt(token[0]);
                    int row = this->stringToInt(token.substr(1, token.size())) - 1;

                    std::getline(iss, token, ' ');
                    string name = token;

                    std::getline(iss, token, ' ');
                    int umur = stringToInt(token);

                    lad.setElement(new Plant(objek.findPlant(name)), row, col);
                    lad.getElement(row, col)->setUmur(umur);

                    max--;
                }
                Petani pet = Petani(userName, uang, beratBadan, data, lad, jumlahBangunan);
                petaniList.push_back(pet);
            }
            else if (tipe == "Peternak")
            {
                std::getline(inputFile, line);
                PetiRahasia data = PetiRahasia(objek.getSizeInventory()[0], objek.getSizeInventory()[1]);
                int max = stringToInt(line);
                int i = 0;
                int j = 0;
                int jumlahBangunan = 0;
                Ternak peternakan = Ternak(objek.getSizeFarm()[0], objek.getSizeFarm()[1]);

                while (max > 0)
                {
                    if (j == objek.getSizeInventory()[1])
                    {
                        j = 0;
                        i++;
                    }
                    std::getline(inputFile, line);
                    if (!(objek.findPlant(line) == Plant()))
                    {
                        data.setElement(new Plant(objek.findPlant(line)), i, j);
                    }
                    else if (!(objek.findAnimal(line) == Animal()))
                    {
                        data.setElement(new Animal(objek.findAnimal(line)), i, j);
                    }
                    else if (!(objek.findProduk(line) == Produk()))
                    {
                        data.setElement(new Produk(objek.findProduk(line)), i, j);
                    }
                    else if (!(objek.findBangunan(line) == Bangunan()))
                    {
                        data.setElement(new Bangunan(objek.findBangunan(line)), i, j);
                        jumlahBangunan++;
                    }
                    j++;
                    max--;
                }
                std::getline(inputFile, line);
                max = stringToInt(line);
                while (max > 0)
                {
                    std::getline(inputFile, line);
                    std::istringstream iss(line);

                    std::getline(iss, token, ' ');
                    int col = this->charToInt(token[0]);
                    int row = this->stringToInt(token.substr(1, token.size())) - 1;

                    std::getline(iss, token, ' ');
                    string name = token;

                    std::getline(iss, token, ' ');
                    int berat = stringToInt(token);

                    peternakan.setElement(new Animal(objek.findAnimal(name)), row, col);
                    peternakan.getElement(row, col)->setBerat(berat);

                    max--;
                }
                Peternak pet = Peternak(userName, uang, beratBadan, data, peternakan, jumlahBangunan);
                peternakList.push_back(pet);
            }
            else if (tipe == "Walikota")
            {
                std::getline(inputFile, line);
                PetiRahasia data = PetiRahasia(objek.getSizeInventory()[0], objek.getSizeInventory()[1]);
                int max = stringToInt(line);
                int i = 0;
                int j = 0;
                int jumlahBangunan = 0;
                Ternak peternakan;

                while (max > 0)
                {
                    if (j == objek.getSizeInventory()[1])
                    {
                        j = 0;
                        i++;
                    }
                    std::getline(inputFile, line);
                    if (!(objek.findPlant(line) == Plant()))
                    {
                        data.setElement(new Plant(objek.findPlant(line)), i, j);
                    }
                    else if (!(objek.findAnimal(line) == Animal()))
                    {
                        data.setElement(new Animal(objek.findAnimal(line)), i, j);
                    }
                    else if (!(objek.findProduk(line) == Produk()))
                    {
                        data.setElement(new Produk(objek.findProduk(line)), i, j);
                    }
                    else if (!(objek.findBangunan(line) == Bangunan()))
                    {
                        data.setElement(new Bangunan(objek.findBangunan(line)), i, j);
                        jumlahBangunan++;
                    }
                    j++;
                    max--;
                }
                this->walikota = Walikota(userName, uang, beratBadan, data);
                this->walikota.setUang(uang);
                this->walikota.setBeratBadan(beratBadan);
            }
        }
        std::getline(inputFile, line);
        int max = stringToInt(line);

        string token;
        while (max > 0)
        {
            std::getline(inputFile, line);
            std::istringstream iss(line);

            std::getline(iss, token, ' ');
            string nama = token;

            std::getline(iss, token, ' ');
            int jumlah = stringToInt(token);

            this->toko.getStok()[nama] = jumlah;
            max--;
        }
    }
}

void GameStatus::cetakPenyimpanan()
{
    getCurrentPlayer()->getData().cetakPenyimpanan();
}

void GameStatus::pungutPajak(GameObject& objek)
{   
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << endl;
    
    this->walikota.pungutPajak(objek, playerTurnList);
}

void GameStatus::tanam()
{
}

void GameStatus::ternak()
{
}

void GameStatus::bangunBangunan(string kodeHuruf, string namaBangunan, int price, int teak, int sandalwood, int aloe, int ironwood)
{
    int TeakWood = 0;
    int SandalWood = 0;
    int AloeWood = 0;
    int IronWood = 0;
    for (int i = 0; i < this->getCurrentPlayer()->getData().getM(); i++)
    {
        for (int j = 0; j < this->getCurrentPlayer()->getData().getN(); j++)
        {
            if (this->getCurrentPlayer()->getData().getElement(i, j)->getNama() == "TEAK_WOOD")
            {
                TeakWood++;
            }
            if (this->getCurrentPlayer()->getData().getElement(i, j)->getNama() == "SANDAL_WOOD")
            {
                SandalWood++;
            }
            if (this->getCurrentPlayer()->getData().getElement(i, j)->getNama() == "SANDAL_WOOD")
            {
                AloeWood++;
            }
            if (this->getCurrentPlayer()->getData().getElement(i, j)->getNama() == "SANDAL_WOOD")
            {
                IronWood++;
            }
        }
    }
    this->getWalikota().setTeakWood(TeakWood);
    this->getWalikota().setSandalWood(SandalWood);
    this->getWalikota().setAloeWood(AloeWood);
    this->getWalikota().setIronWood(IronWood);
    this->getWalikota().bangunBangunan(kodeHuruf, namaBangunan, price, teak, sandalwood, aloe, ironwood);
}

void GameStatus::makan()
{
}

void GameStatus::memberiPangan()
{
}

void GameStatus::membeli()
{
}

void GameStatus::menjual()
{
}

void GameStatus::memanen()
{
}

void GameStatus::simpan(string path, GameObject objek)
{
    ofstream outFile(path);

    if (outFile.is_open())
    {
        // Write data to the file
        outFile << playerTurnList.size() << endl;
        for (size_t i = 0; i < peternakList.size(); i++)
        {
            outFile << peternakList[i].getUsername() << " " << peternakList[i].getPeran() << " " << peternakList[i].getBeratBadan() << " " << peternakList[i].getUang() << endl;
            outFile << peternakList[i].getData().getEfektif() << endl;
            for (int j = 0; j < peternakList[i].getData().getM(); j++)
            {
                for (int k = 0; k < peternakList[i].getData().getN(); k++)
                {
                    if (peternakList[i].getData().getElementNoException(j, k) != nullptr)
                    {
                        outFile << peternakList[i].getData().getElement(j, k)->getNama() << endl;
                    }
                }
            }
            outFile << peternakList[i].getTernak().getNEff() << endl;
            for (int j = 0; j < peternakList[i].getTernak().getM(); j++)
            {
                for (int k = 0; k < peternakList[i].getTernak().getN(); k++)
                {
                    if (peternakList[i].getTernak().getElementNoException(j, k) != nullptr)
                    {
                        outFile << peternakList[i].getTernak().getElement(j, k)->getKodeHuruf() << " " << peternakList[i].getTernak().getElement(j, k)->getNama() << " " << peternakList[i].getTernak().getElement(j, k)->getBerat() << endl;
                    }
                }
            }
        }
        for (size_t i = 0; i < petaniList.size(); i++)
        {
            outFile << petaniList[i].getUsername() << " " << petaniList[i].getPeran() << " " << petaniList[i].getBeratBadan() << " " << petaniList[i].getUang() << endl;
            outFile << petaniList[i].getData().getEfektif() << endl;
            for (int j = 0; j < petaniList[i].getData().getM(); j++)
            {
                for (int k = 0; k < petaniList[i].getData().getN(); k++)
                {
                    if (petaniList[i].getData().getElementNoException(j, k) != nullptr)
                    {
                        outFile << petaniList[i].getData().getElement(j, k)->getNama() << endl;
                    }
                }
            }
            outFile << petaniList[i].getLadang().getNEff() << endl;
            for (int j = 0; j < petaniList[i].getLadang().getM(); j++)
            {
                for (int k = 0; k < petaniList[i].getLadang().getN(); k++)
                {
                    if (petaniList[i].getLadang().getElementNoException(j, k) != nullptr)
                    {
                        outFile << petaniList[i].getLadang().getElement(j, k)->getKodeHuruf() << " " << petaniList[i].getLadang().getElement(j, k)->getNama() << " " << petaniList[i].getLadang().getElement(j, k)->getUmur() << endl;
                    }
                }
            }
        }

        outFile << walikota.getUsername() << " " << walikota.getPeran() << " " << walikota.getBeratBadan() << " " << walikota.getUang() << endl;
        outFile << walikota.getData().getEfektif() << endl;
        for (int j = 0; j < walikota.getData().getM(); j++)
        {
            for (int k = 0; k < walikota.getData().getN(); k++)
            {
                if (walikota.getData().getElementNoException(j, k) != nullptr)
                {
                    outFile << walikota.getData().getElement(j, k)->getNama() << endl;
                }
            }
        }
        outFile << toko.getStok().size();
        if (toko.getStok().size() > 0)
        {
            outFile << endl;
        }
        size_t n = 0;
        for (const auto &pair : toko.getStok())
        {
            n++;

            outFile << pair.first << " " << pair.second;
            if (n != toko.getStok().size())
            {
                outFile << endl;
            }
        }
        outFile.close();
        cout << "State berhasil disimpan" << endl;
    }
    else
    {
        cout << "Lokasi berkas tidak valid" << endl;
    }
}
void GameStatus::tambahPemain(GameObject objek)
{
    string jenis;
    string nama;
    cout<<"Masukkan jenis pemain: ";
    cin>> jenis;
    if (jenis != "Peternak" && jenis!="Petani"){
        throw PeranTidakValid();
    }
    cout<<"Masukkan nama pemain: ";
    cin>>nama;
    for (size_t i = 0;i<playerTurnList.size();i++){
        if (nama==playerTurnList[i]->getUsername()){
            throw PlayerAlreadyExist();
        }
    }

    if (jenis=="Peternak"){
        peternakList.push_back(Peternak(nama,50,40,
        PetiRahasia(objek.getSizeInventory()[0],objek.getSizeInventory()[1]),
        Ternak(objek.getSizeFarm()[0],objek.getSizeFarm()[1]),
        0
        ));
       
    }else if (jenis=="Petani"){
        petaniList.push_back(Petani(nama,50,40,
        PetiRahasia(objek.getSizeInventory()[0],objek.getSizeInventory()[1]),
        Ladang(objek.getSizeCrops()[0],objek.getSizeCrops()[1]),
        0
        ));
        for (size_t i =0;i<petaniList.size();i++){
            cout<<petaniList[i].getUsername()<<endl;
        }
    }
    // clear
    this->playerTurnList.clear();
    // store player
    for (size_t i =0 ; i<peternakList.size();i++){
        this->playerTurnList.push_back(&this->peternakList[i]);
    }
    for (size_t i =0 ; i<petaniList.size();i++){
        this->playerTurnList.push_back(&this->petaniList[i]);
    }
    this->playerTurnList.push_back(&this->walikota);

    // sort player turn order
    this->lexicographicSort();
  
    
}