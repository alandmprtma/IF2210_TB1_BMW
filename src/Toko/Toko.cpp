#include "Toko.hpp"

Toko::Toko() {
    this->stok = map<string,int>();
}

void Toko::welcome(){
    cout << "Selamat datang di Toko Cina!!" << endl;
    cout << "                                 %%###########%%" << endl;
    cout << "                                %#(((((((((((((#%"<< endl;
    cout << "                      %%#%%%%%%#(((((((((((((((((#%%%%%%#%" << endl;
    cout << "                       %#((((((((((((((((((((((((((((((##%" << endl;
    cout << "                          %#((((((((((((((((((((((((#%%" << endl;
    cout << "                            /....,,,........,,,,...,(" << endl;
    cout << "                            /..,/% %/.......(  #*,.,(" << endl;
    cout << "                            (..,,***,.......,*/*,..,(" << endl;
    cout << "                %      %####(((((((((((((((((((((((((###%      %" << endl;
    cout << "               %##(###(((((((((((((((((((((((((((((((((((((###(##" << endl;
    cout << "                  %##(((((((((((((((((((((((((((((((((((((((##%" << endl;
    cout << "                     %(*,,,***,,,,,,,,,**,,,,,,,,,,***,,,*(%" << endl;
    cout << "                      /,.,/% %/,.....,(% #/......*(% %*..*(" << endl;
    cout << "                      /,..,///,.......*//*,......,*///,..*(" << endl;
    cout << "                     %(///////////////////////////////////(%" << endl;
    cout << "            %########(((((((((((((((((((((((((((((((((((((((########%" << endl;
    cout << "              %##(((((((((((((((((((((((((((((((((((((((((((((((##%" << endl;
    cout << "                 %(/*****************************************/#" << endl;
    cout << "                 %(,..*/((((((,...,/(((((((((/,..,*((((((/,..,#" << endl;
    cout << "                 %(,.,(%     %/,.,/%         %*..*(%     #/..,#" << endl;
    cout << "                 %(,..*/#####(,..,/%         %*..,*(#####/,..,#" << endl;
    cout << "                 %(,.............,/%         %*..............,#" << endl;
    cout << "                  %%#############%%           %%#############%" << endl;
}

// Toko::Toko() {
//     this->stok = map<string,int>();

// }

// void Toko::titipJual(Bangunan el){

// }
// /*
// Method untuk melakukan pembelian dengan objek yang memiliki tipe Bangunan
// */
// void Toko::mauBeli(Bangunan el){

// }

void Toko::beli(){

}
void Toko::jual(){

}

map<string,int> Toko::getStok(){
    return this->stok;
}

void Toko::setStok(string Barang){
    if(this->stok.empty()){
        this->stok.insert(make_pair(Barang, 1));
    }
    else{
        auto it = this->stok.find(Barang);

        // Jika kunci sudah ada dalam map, tinggal diincrement
        if (it != this->getStok().end()) {
            this->stok[Barang]++;
        } else {
            // Jika kunci tidak ditemukan, tambahkan kunci baru dengan nilai awal 1
            this->stok.insert(make_pair(Barang, 1));
        }
    }   
}
