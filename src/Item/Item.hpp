#ifndef ITEM_HPP
#define ITEM_HPP
using namespace std;
#include <iostream>


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
    virtual ~Item(){}
    string getKodeHuruf() const;
    string getNama() const;
    string getTipe() const;

};

#endif