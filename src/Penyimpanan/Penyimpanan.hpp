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
    /* Default Constructor */
    Penyimpanan();
    Penyimpanan(int, int);

    /* Mendapatkan Size Data */
    int getSize();

    /* Get Element */
    T getElement(int, int);
    
    /* Set Element */
    void setElement(T, int, int);

    /* Mereturn & Menghapus Element Dari Data */
    void removeElement(int, int);

    /* Mencetak Data */
    virtual void cetakPenyimpanan(string);
};

#endif