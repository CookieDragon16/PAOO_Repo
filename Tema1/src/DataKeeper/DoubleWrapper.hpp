#include <iostream>

using namespace std;

class DoubleWrapper {       
  private:             
    double value {0};
  public:
    DoubleWrapper();
    DoubleWrapper(double value);
    ~DoubleWrapper();
    DoubleWrapper(DoubleWrapper& object);
    DoubleWrapper(DoubleWrapper&& source);
    double getValue();
    void setValue(double newValue);
    
};