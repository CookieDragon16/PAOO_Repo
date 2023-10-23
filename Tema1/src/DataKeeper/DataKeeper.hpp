#include <iostream>
#include <string>
using namespace std;

class DataKeeper {       
  private:             
    int number;        
    string text;
  public:
    DataKeeper();
    DataKeeper(int number, string text);
    ~DataKeeper();
    void print();
};