#include <iostream>
#include <string>
#include "DoubleWrapper.hpp"
using namespace std;

class DataKeeper {       
  private:             
    int key;    
    DoubleWrapper *value;    
    string text;
  public:
    DataKeeper();
    DataKeeper(int key, double value, string text);
    ~DataKeeper();
};