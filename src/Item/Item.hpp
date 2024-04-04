#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
using namespace std;

#define DEFAULT_KODE_HURUF_ITEM "@#$"
#define DEFAULT_NAMA_ITEM "@#$"
#define DEFAULT_TIPE_ITEM "@#$"
#define NULL_ITEM Item()

class Item{
protected:
    string kodeHuruf;
    string nama;
    string tipe;
public:
    Item();
    Item(string,string,string);
    string getKodeHuruf() const;
    string getNama() const;
    string getTipe() const;
    bool operator==(const Item& other);
    Item& operator=(const Item& other);

};

#endif