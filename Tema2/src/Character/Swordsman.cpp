#include <iostream>
#include "Swordsman.hpp"

void Swordsman::giveBroadSword(){
    this->hasBroadSword = true;
}
int Swordsman::attack(){
    if(hasBroadSword){
        return 10;
    }else{
        return 6;
    }
}