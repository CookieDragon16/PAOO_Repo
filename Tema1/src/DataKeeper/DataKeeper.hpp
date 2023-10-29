#include <iostream>
#include <string>
#include "DoubleWrapper.hpp"
using namespace std;

class DataKeeper {       
  private:             
    int key;    
    DoubleWrapper *value;    
    string *text;
  public:
    DataKeeper();
    DataKeeper(int key, double value, string text);
    ~DataKeeper();
    DataKeeper(const DataKeeper& object);
    DataKeeper(DataKeeper&& source);
    int getKey();
    void setKey(int newKey);
    DoubleWrapper* getValue();
    void setValue(double newValue);
    string* getText();
    void setText(string* newText);
    string toString() const;
};