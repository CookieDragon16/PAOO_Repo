#include <iostream>
#include <string>

class DataKeeper {       
  private:             
    int number;        
    std::string text;
  public:
    DataKeeper();
    DataKeeper(int number, std::string text);
    ~DataKeeper();
    void print();
};