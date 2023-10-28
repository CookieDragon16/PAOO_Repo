#include <iostream>
#include <string>
#include "DataKeeper.hpp"

using namespace std;

DataKeeper::DataKeeper(){
  cout<<endl<<"Creating DataKeeper object with default values..."<<endl;
  this->key=0;
  this->value=new DoubleWrapper();
  this->text=new string("");
} 
DataKeeper::DataKeeper(int key, double value, string text){
  this->key=key;
  this->value=new DoubleWrapper(value);
  this->text=new string(text);
  cout<<endl<<"Created DataKeeper object with "<<this->toString()<<endl;
} 
DataKeeper::~DataKeeper(){
  cout<<endl<<"Destroying DataKeeper object with "<<this->toString()<<endl;
  delete this->value;
  delete this->text;
} 

DataKeeper::DataKeeper(DataKeeper& object){
  cout<<endl<<"Copying DataKeeper object with "<<object.toString()<<endl;
  this->key=object.key;
  this->value=new DoubleWrapper(object.value->getValue());
  this->text=object.text;
}

DataKeeper::DataKeeper(DataKeeper&& source): key(0), value(nullptr), text(nullptr) {
    cout<<endl<<"Moving DataKeeper object with "<<source.toString()<<endl;
    this->key=source.getKey();
    this->value = source.getValue();
    this->text = source.getText();    
    source.key=0;
    source.value =nullptr;
    source.text=nullptr;
}
int DataKeeper::getKey(){
  return this->key;
}
void DataKeeper::setKey(int newKey){
  this->key=newKey;
}
DoubleWrapper* DataKeeper::getValue(){
  return this->value;
}
void DataKeeper::setValue(double newValue){
  this->value->setValue(newValue);
}
void DataKeeper::deleteValue(){
  delete this->value;
}
string* DataKeeper::getText(){
  return this->text;
}
void DataKeeper::setText(string* newText){
  this->text=newText;
}
string DataKeeper::toString() const{
  return "<" + to_string(key) + ">; <" + to_string(value->getValue()) + ">; <'"+ text->c_str() + "'>";
}
