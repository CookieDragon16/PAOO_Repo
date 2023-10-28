#include <iostream>
#include <string>
#include <vector>
#include "DataKeeper.hpp"

using namespace std;


int main() 
{
    DataKeeper* obj0 = new DataKeeper(); 
    DataKeeper* obj1 = new DataKeeper(1, 1.3,"first object");
    DataKeeper obj2(2, 6.8, "second object");
    DataKeeper* obj3=new DataKeeper(obj2);
    obj3->setKey(3);
    obj3->setText(new string("third object"));
    //TO DO: still causes seg fault upon Move constructor call...
    /*
    vector<DataKeeper> vectorOfKeepers;
    vectorOfKeepers.push_back(DataKeeper(4, 1.1,"fourth object"));
    vectorOfKeepers.push_back(DataKeeper(5, 9.6,"fifth object"));
    */
    delete obj0;
    delete obj1;
    delete obj3;
    return 0;
}