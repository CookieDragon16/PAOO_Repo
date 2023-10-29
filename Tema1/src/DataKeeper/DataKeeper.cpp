#include <iostream>
#include <string.h>
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
  if(this->value!=nullptr){
    delete this->value;
  }
  if(this->text!=nullptr){
    this->text->clear();
  }
} 

DataKeeper::DataKeeper(const DataKeeper& object){
  cout<<endl<<"Copying DataKeeper object with "<<object.toString()<<endl;
  key=object.key;
  value=new DoubleWrapper();
  value->setValue(object.value->getValue());
  text=new string();
  *text=object.text->c_str();
}

DataKeeper::DataKeeper(DataKeeper&& source): key(source.key), value(source.value), text(source.text){
  source.key=0;
  source.value=nullptr;
  source.text=nullptr;
  cout<<endl<<"Moving DataKeeper object with "<<this->toString()<<endl;  
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

