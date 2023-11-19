#include <iostream>
#include <string.h>
#include "Player.hpp"

Player::Player(char* name){
    this->name=(char*)malloc(strlen(name)*sizeof(char));
    strcpy(this->name,name);
}
Player::~Player(){
    std::cout<<"\nPlayer "<<name<<" has died!\n";
    delete[] name;
}
Player::Player(const Player& source){
    name = (char*)malloc(strlen(source.name)*sizeof(char));
    strcpy(source.name, name);
}
Player::Player(Player&& source){
    name=source.name;
    HP=source.HP;
    source.name=nullptr;
    source.HP=0;
}
Player& Player::operator=(const Player& source){
    std::cout<<"Copy assignment operation!\n";
    if (this != &source)
    {
        delete[] name;
        name = (char*)malloc(strlen(source.name)*sizeof(char));
        strcpy(source.name, name);
    }
    return *this;
}
Player& Player::operator=(Player&& source){
    std::cout<<"Move assignment operation!\n";
    if (this != &source)
    {
        delete[] name;
        name = source.name;
        HP=source.HP;
        source.name = nullptr;
        source.HP=0;
    }
    return *this;
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