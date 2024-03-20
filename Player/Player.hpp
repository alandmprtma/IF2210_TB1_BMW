#include <iostream>
using namespace std;

class Player {
  protected:
    string username;
    string peran;
    int uang;
    int berat_badan;
  
  public: 
    Player();
    void setUsername(string);
};