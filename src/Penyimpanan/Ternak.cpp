#include "Ternak.hpp"

void Ternak::cetakPenyimpanan() {
  cout << "    ";
  cout << "================[ Ternak ]=================" << endl << endl; 

  cout << "    ";
  for (int i = 0; i < n; i++) {
      cout << "   " << (char) ('A' + i) << "  ";
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
          if (data[i][j] == nullptr) {
              cout << setw(3) << "   ";
          } else {
              cout << setw(3);
              if (data[i][j]->getBerat() >= data[i][j]->getBeratPanen()) {
                cout << "\033[32m" << data[i][j]->getKodeHuruf() << "\033[0m";
              } else {
                cout << "\033[31m" << data[i][j]->getKodeHuruf() << "\033[0m";
              }
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
Penyimpanan<Animal*>& Ternak::operator+(Animal* other){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (this->data[i][j]==nullptr){
                this->data[i][j] = other;
                return *this;
            }
        }
    }
    return *this;
}
void Ternak::operator=(Penyimpanan<Animal*>& other){
    
    this->m = other.getM();
    this->n = other.getN();
        for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            this->data[i][j] = other.getElementNoException(i,j);
        }
        }
    
}