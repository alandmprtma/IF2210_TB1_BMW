#ifndef PENYIMPANAN_HPP
#define PENYIMPANAN_HPP

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template <class T>
class Penyimpanan {
  protected:
    vector<vector<T>> data;
    int m; /* Baris */ 
    int n; /* Kolom */
    
  public:
    Penyimpanan();
    Penyimpanan(int, int);
    int getSize();
    void setElement(T, int, int);
    T getElement(int, int);
    void removeElement(int, int);
    void cetakPenyimpanan();
};

#endif
