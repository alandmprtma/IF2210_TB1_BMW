#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template <class T>
class Penyimpanan {
  protected:
    vector<T> data;
    int m;
    int n;
    
  public:
    Penyimpanan();
    Penyimpanan(int, int);
    int getSize();
    T getElement(int, int);
    void cetakPenyimpanan();
};
