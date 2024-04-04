#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>

using namespace std;

class Item{
private:
    string kodeHuruf;
    string nama;
    string tipe;
public:
    Item();
    Item(string,string,string);
    string getKodeHuruf();
    string getNama();
    string getTipe();
};

#endif