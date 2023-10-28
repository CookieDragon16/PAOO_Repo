#include <iostream>
#include <string>
#include "DataKeeper.hpp"

using namespace std;

DataKeeper::DataKeeper(){
  cout<<endl<<"Creating DataKeeper object with default values..."<<endl;
  this->key=0;
  this->value=new DoubleWrapper();
  this->text="";
} 
DataKeeper::DataKeeper(int key, double value, string text){
  cout<<endl<<"Creating DataKeeper object with <"<<to_string(key)<<">; <"<<to_string(value)<<">; <'"<<text<<"'>..."<<endl;
  this->key=key;
  this->value=new DoubleWrapper(value);
  this->text=text;
} 
DataKeeper::~DataKeeper(){
  cout<<endl<<"Destroying DataKeeper object with <"<<to_string(key)<<">; <"<<to_string(value->getValue())<<">; <'"<<text<<"'>..."<<endl;
  delete this->value;
} 

/*
DataKeeper(DataKeeper& obj)
  {
      cout << "The value of x in "
            << "copy constructor: "
            << x << "\n";
  };
  */