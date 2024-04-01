#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Penyimpanan {
  protected:
    vector<string> data; // Change the template parameter to string
    int m;
    int n;
    
  public:
    Penyimpanan(int, int);

    void printPenyimpanan();
};
