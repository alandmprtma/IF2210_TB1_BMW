#include "PetiRahasia.hpp"

void PetiRahasia::cetakPenyimpanan()
{
  cout << "    ";
  cout << "================[ Penyimpanan ]=================" << endl
       << endl;
  cout << "    ";

  for (int i = 0; i < n; i++)
  {
    cout << "   " << (char)('A' + i) << "  ";
  }
  cout << " " << endl;

  cout << "    ";
  for (int i = 0; i < n; i++)
  {
    cout << "+-----";
  }
  cout << "+" << endl;

  for (int i = 0; i < m; i++)
  {
    cout << " " << setw(2) << setfill('0') << i + 1 << " ";

    for (int j = 0; j < n; j++)
    {
      cout << "| ";
      if (data[i][j] == nullptr || data[i][j]->getKodeHuruf().empty())
      {
        cout << setw(3) << "   "; // Jika elemen kosong,
      }
      else
      {
        cout << setw(3) << data[i][j]->getKodeHuruf(); // Cetak kodeHuruf
      }
      cout << " ";
    }

    cout << "|" << endl;

    cout << "    ";
    for (int i = 0; i < n; i++)
    {
      cout << "+-----";
    }
    cout << "+" << endl;
  }
}

Penyimpanan<Item*>& PetiRahasia::operator+(Item* other){
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
void PetiRahasia::operator=(Penyimpanan<Item*>& other){
    this->m = other.getM();
    this->n = other.getN();
      for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            this->data[i][j] = other.getElementNoException(i,j);
        }
      }
}