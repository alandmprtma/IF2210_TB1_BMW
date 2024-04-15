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

  int NEff; /* Elemen Efektif, Tidak Kosong */
public:
  /* Default Constructor */
  Penyimpanan() {
    m = 0;
    n = 0;
    NEff = 0;
  }
  
  Penyimpanan(int m, int n) : m(m), n(n),NEff(0) {
    data.resize(m, vector<T>(n));
  }

  /* Mendapatkan Size Data */
  int getSize() {
    return m * n;
  }

  /* Mendapatkan Size Baris */
  int getM() {
    return m;
  }

  /* Mendapatkan Size Kolom */
  int getN() {
    return n;
  }
  /*Mendapatkan Neff*/
  int getNEff(){
    return NEff;
  }
  /* Mendapatkan Elemen Efektif */
  int getEfektif() {
    int efektif = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (data[i][j] != nullptr) {
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
          cout << "Petak Kosong!" << endl;
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
          cout<<"Petak Kosong!";
      }else{
        data[i][j] = nullptr;
        NEff--;
      }
    } else {
      cout << "Indeks di luar batas!" << endl;
    }
  }

  /* Mencetak Data */
  void cetakPenyimpanan() {
    cout << "    ";
    /* Garis Judul Belum Dinamis*/
    cout << "================[ Penyimpanan ]=================" << endl
         << endl;

    cout << "    ";
    for (int i = 0; i < n; i++) {
      cout << "   " << (char)('A' + i) << "  ";
    }
    cout << " " << endl;

    cout << "    ";
    for (int i = 0; i < n; i++) {
      cout << "+-----";
    }
    cout << "+" << endl;

    for (int i = 0; i < m; i++) {
      cout << " " << setw(2) << setfill('0') << i + 1 << " ";

      for (int j = 0; j < n; j++) {
        cout << "| ";
        if (data[i][j] == nullptr || data[i][j] == 0) {
          cout << "   "; // Jika elemen kosong, cetak spasi
        } else {
          cout << setw(3) << data[i][j]; // Cetak nilai elemen vektor
        }
        cout << " ";
      }

      cout << "|" << endl;

      cout << "    ";
      for (int i = 0; i < n; i++) {
        cout << "+-----";
      }
      cout << "+" << endl;
    }
  }
};

#endif