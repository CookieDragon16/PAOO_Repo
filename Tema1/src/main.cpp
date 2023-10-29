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
    DataKeeper obj4(move(obj2));

    delete obj0;
    delete obj1;
    delete obj3;
    return 0;
}
