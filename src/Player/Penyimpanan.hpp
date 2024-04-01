#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;



class Penyimpanan {
  protected:
    vector<string> data;
    int m;
    int n;
    
  public:
    Penyimpanan();
    Penyimpanan(int, int);
    void cetakPenyimpanan();
};

