#ifndef PENYIMPANAN_HPP
#define PENYIMPANAN_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include "../Exception/Exception.hpp"

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

  /* Exception Get Element */
  void isIndexValid(int i, int j) {
    if ((i < 0 || i > m) && (j < 0 || j > n)) {
      throw IndexOutOfBound();
    }
  }

  void isElementEmpty(int i, int j) {
    if (data[i][j] == nullptr) {
      throw PenyimpananKosong();
    }
  }
  void isElementNotEmpty(int i, int j){
    if (data[i][j] != nullptr){
      throw PenyimpananSudahTerisi();
    }
  }

  /* Get Element */
  T getElement(int i, int j) {
    try {
      isIndexValid(i, j);
      isElementEmpty(i, j);
      return data[i][j];
    } 
    catch (const Exception& e) 
    {
      cout << e.what() << endl;
    } 
    return nullptr;
  }

  /* Set Element */
  void setElement(T newElement, int i, int j) {
    try 
    {
      isIndexValid(i, j);
      isElementNotEmpty(i,j);
      data[i][j] = newElement;
      NEff++;
  
    } 
    catch(const Exception& e){
        cout<<e.what()<<endl;
    }
  }

  /* Mereturn & Menghapus Element Dari Data */
  void removeElement(int i, int j) {
    try
    {
      isIndexValid(i, j);
      isElementEmpty(i, j);
      data[i][j] = nullptr;
      NEff--;
      
    }
    catch (const Exception& e) 
    {
      cout << e.what() << endl;
    } 
    
  }

  /* Mencetak Data */
  virtual void cetakPenyimpanan()
  {
  }
};

#endif