#include <iostream>

using namespace std;

class DoubleWrapper {       
  private:             
    double value {0};
  public:
    DoubleWrapper();
    DoubleWrapper(double value);
    double getValue();
};