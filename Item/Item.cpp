#include "Item.hpp"

Item::Item(string kodeHuruf, string nama, string tipe):kodeHuruf(kodeHuruf),nama(nama),tipe(tipe){}
string Item::getKodeHuruf(){
    return kodeHuruf;
}
string Item::getNama(){
    return nama;
}
string Item::getTipe(){
    return tipe;
}