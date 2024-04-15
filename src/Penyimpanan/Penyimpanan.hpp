#ifndef PENYIMPANAN_HPP
#define PENYIMPANAN_HPP

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template <class T>
class Penyimpanan
{
protected:
  vector<vector<T>> data;
  int m; /* Baris */
  int n; /* Kolom */

  int NEff; /* Elemen Efektif, Tidak Kosong */
public:
  /* Default Constructor */
  Penyimpanan()
  {
    m = 0;
    n = 0;
    NEff = 0;
  }

  Penyimpanan(int m, int n) : m(m), n(n), NEff(0)
  {
    data.resize(m, vector<T>(n));
  }

  /* Mendapatkan Size Data */
  int getSize()
  {
    return m * n;
  }

  /* Mendapatkan Size Baris */
  int getM()
  {
    return m;
  }

  /* Mendapatkan Size Kolom */
  int getN()
  {
    return n;
  }
  /*Mendapatkan Neff*/
  int getNEff()
  {
    return NEff;
  }
  /* Mendapatkan Elemen Efektif */
  int getEfektif()
  {
    int efektif = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (data[i][j] != nullptr)
        {
          efektif++;
        }
      }
    }
    return efektif;
  }

  /* Get Element */
  T getElement(int i, int j) {
    if (i >= 0 && i < m && j >= 0 && j < n) {
      if (data[i][j]==nullptr or data[i][j]==T()){
          return nullptr;
      }
      return data[i][j];
      
    } else {
      cout << "Indeks di luar batas!" << endl;
      return T();
    }
  }

  /* Set Element */
  // Asumsi input sudah benar
  void setElement(T newElement, int i, int j) {
    if (i >= 0 && i < m && j >= 0 && j < n) {
      data[i][j] = newElement;
      NEff++;
    } else {
      cout << "Indeks di luar batas!" << endl;
    }
  }

  /* Mereturn & Menghapus Element Dari Data */
  void removeElement(int i, int j) {
    if (i >= 0 && i < m && j >= 0 && j < n) {
      if (data[i][j]==nullptr){
        // do nothing
      }else{
        data[i][j] = nullptr;
        NEff--;
      }
    } else {
      cout << "Indeks di luar batas!" << endl;
    }
  }

  /* Mencetak Data */
  virtual void cetakPenyimpanan()
  {
  }
};

#endif