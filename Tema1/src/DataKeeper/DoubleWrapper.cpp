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
DoubleWrapper::DoubleWrapper(DoubleWrapper& object){
    value=object.value;
}
DoubleWrapper::DoubleWrapper(DoubleWrapper&& source){
    value=source.value;
    source.value=0;
}
void DoubleWrapper::setValue(double newValue){
    this->value=newValue;
}