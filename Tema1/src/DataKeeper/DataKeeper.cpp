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
  key=object.key;
  value=new DoubleWrapper(object.value->getValue());
  text=new string(object.text->c_str());
}

DataKeeper::DataKeeper(DataKeeper&& source): key(source.key), value(source.value), text(source.text){
    cout<<endl<<"Moving DataKeeper object with "<<source.toString()<<endl;   
    source.deReff();
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
string* DataKeeper::getText(){
  return this->text;
}
void DataKeeper::setText(string* newText){
  this->text=newText;
}
string DataKeeper::toString() const{
  return "<" + to_string(key) + ">; <" + to_string(value->getValue()) + ">; <'"+ text->c_str() + "'>";
}
void DataKeeper::deReff(){
  this->key=0;
  this->value=nullptr;
  this->text=nullptr;
}
