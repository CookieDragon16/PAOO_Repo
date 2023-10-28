#include <iostream>
#include "DoubleWrapper.hpp"

using namespace std;

DoubleWrapper::DoubleWrapper(){
    cout<<endl<<"Creating default DoubleWrapper object..."<<endl;
}
DoubleWrapper::DoubleWrapper(double value) : value(value){
    cout<<endl<<"Creating DoubleWrapper object with "<<to_string(value)<<"..."<<endl;
}
double DoubleWrapper::getValue(){
    return value;
}