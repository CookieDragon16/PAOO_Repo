#include <iostream>
#include "DoubleWrapper.hpp"

using namespace std;

DoubleWrapper::DoubleWrapper(){
    cout<<endl<<"Creating default DoubleWrapper object..."<<endl;
}
DoubleWrapper::DoubleWrapper(double value) : value(value){
    cout<<endl<<"Creating DoubleWrapper object with "<<to_string(value)<<"..."<<endl;
}
DoubleWrapper::~DoubleWrapper(){}
double DoubleWrapper::getValue(){
    return value;
}
void DoubleWrapper::setValue(double newValue){
    this->value=newValue;
}