#include <iostream>
#include <string>
#include "../include/DataKeeper.hpp"

using namespace std;

int main() 
{
    DataKeeper obj(1,"first object");
    obj.print();
    return 0;
}