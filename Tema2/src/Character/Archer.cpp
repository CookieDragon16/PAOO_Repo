#include <iostream>
#include "Archer.hpp"

Archer& Archer::operator=(const Archer &source) {
   Player::operator=(source);
   return *this;
}
Archer& Archer::operator=(Archer &&source) {
   Player::operator=(std::move(source));
   return *this;
}
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