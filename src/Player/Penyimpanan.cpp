#include "Penyimpanan.hpp"

template <class T>
Penyimpanan<T>::Penyimpanan() : m(0), n(0) {}

template <class T>
Penyimpanan<T>::Penyimpanan(int m, int n) : m(m), n(n) {
  data.resize(m * n);
}

template <class T>
T Penyimpanan<T>::getElement(int i, int j) {
  return data[row][col];
}

template <class T>
void Penyimpanan<T>::cetakPenyimpanan() {
  cout << " ";
  for (int i = 0; i < n; i++) {
    cout << "     " << (char) ('A' + i) << " ";
  }
  cout << endl;
  
  cout << "     +";
  for (int i = 0; i < n; i++) {
    cout << "-----+";
  }
  cout << endl;
  
  for (int i = 0; i < m; i++) {
    cout << "  " << setw(2) << setfill('0') << i + 1 << " |";
    
    for (int j = 0; j < n; j++) {
      cout << " ";
      
      if (data[i * n + j] == "") {
        cout << "     ";
      } else {
        cout << data[i * n + j] << " ";
      }
      
      cout << "|";
    }

    cout << endl;
    cout << "     +";
    for (int i = 0; i < n; i++) {
      cout << "-----+";
    }
    cout << endl;
  }
}