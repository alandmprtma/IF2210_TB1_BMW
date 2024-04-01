#include "Penyimpanan.hpp"

Penyimpanan::Penyimpanan(int m, int n) : m(m), n(n) {
  data.resize(m * n);
}

void Penyimpanan::printPenyimpanan() {
  cout << " ";
  for (int i = 0; i < n; i++) {
    cout << "     " << static_cast<char>('A' + i) << " ";
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