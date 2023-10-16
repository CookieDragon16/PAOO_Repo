#include <iostream>
#include <string>
#include "DataKeeper.hpp"
using namespace std;
DataKeeper::DataKeeper(){
  this->number=0;
  this->text="";
} 
DataKeeper::DataKeeper(int number, std::string text){
  this->number=number;
  this->text=text;
} 
DataKeeper::~DataKeeper(){

} 
void DataKeeper::print() {
  cout<<number<<"; "<<text<<"\n";
}
