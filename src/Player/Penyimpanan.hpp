#ifndef PENYIMPANAN_HPP
#define PENYIMPANAN_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <any>
using namespace std;

template <class T>
class Penyimpanan {
  protected:
    vector<vector<T>> data;
    int m;
    int n;
    
  public:
    Penyimpanan();
    Penyimpanan(int, int);
    T getElement(int, int);
    void setElement(int, int, T);
    int getSize();
    void cetakPenyimpanan();
};

#endif