#include <iostream>
#include <string.h>
#include "Player.hpp"

Player::Player(char* name){
    this->name=(char*)malloc(strlen(name)*sizeof(char));
    strcpy(this->name,name);
}
Player::~Player(){
    delete[] name;
}
void Player::giveArmor(){
    this->hasArmor = true;
}
void Player::takeDamage(int dmg){
    if(hasArmor){
        if(this->HP<=(dmg-2)){
            this->HP=0;
        }else{
            this->HP-=(dmg-2);
        }
    }else{
        if(this->HP<=dmg){
            this->HP=0;
        }else{
            this->HP-=dmg;
        }
    }
}
void Player::sayHello(){
    std::cout<<"\nHello, my name is "<<this->name<<" and I have "<<this->HP<<"HP left!\n";
}