#include <iostream>
#include <string>
#include "DataKeeper.hpp"

using namespace std;

int main() 
{
    DataKeeper* obj0 = new DataKeeper(); 
    DataKeeper* obj1 = new DataKeeper(1, 1.3,"first object");
    DataKeeper obj2(2, 6.8, "second object");
    delete obj0;
    delete obj1;
    //obj.print();
    return 0;
}