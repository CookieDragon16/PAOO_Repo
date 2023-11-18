#include <iostream>
#include "Archer.hpp"

void Archer::giveLongBow(){
    this->hasLongBow = true;
}
int Archer::attack(){
    if(hasLongBow){
        return 12;
    }else{
        return 4;
    }
}