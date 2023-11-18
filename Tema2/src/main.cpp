#include <iostream>
#include "Swordsman.hpp"
#include "Archer.hpp"
#include "Enemy.hpp"

int main(){
    char p1_name[]="Ionut";
    Player* p1 = new Swordsman(p1_name);
    Enemy* e1 = new Enemy(10,9);
    p1->sayHello();
    p1->takeDamage(e1->attack());
    p1->sayHello();
    delete e1;
    delete p1;
    return 0;
}