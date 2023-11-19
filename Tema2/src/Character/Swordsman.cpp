#include <iostream>
#include "Swordsman.hpp"

Swordsman& Swordsman::operator=(const Swordsman &source) {
   Player::operator=(source);
   return *this;
}
Swordsman& Swordsman::operator=(Swordsman &&source) {
   Player::operator=(std::move(source));
   return *this;
}
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