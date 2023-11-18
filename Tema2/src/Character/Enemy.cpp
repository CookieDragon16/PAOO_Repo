#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int HP, int attackDmg){
    this->HP = HP;
    this->attackDmg = attackDmg;
    std::cout<<"\nNew enemy has appeared!\n";
}
Enemy::~Enemy(){
    std::cout<<"\nAn enemy has died!\n";
}
void Enemy::takeDamage(int dmg){
    if(this->HP<=dmg){
        this->HP=0;
        delete this;
    }else{
        this->HP-=dmg;
    }
}
int Enemy::attack(){
    return this->attackDmg;
}