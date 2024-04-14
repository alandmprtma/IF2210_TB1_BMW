#include "Item.hpp"



Item::Item(){
    kodeHuruf = DEFAULT_KODE_HURUF_ITEM;    
    nama = DEFAULT_NAMA_ITEM;
    tipe = DEFAULT_TIPE_ITEM;

}

Item::Item(string kodeHuruf, string nama, string tipe):kodeHuruf(kodeHuruf),nama(nama),tipe(tipe){

}
string Item::getKodeHuruf() const{
    return kodeHuruf;
}
string Item::getNama() const{
    return nama;
}
string Item::getTipe() const{
    return tipe;
}