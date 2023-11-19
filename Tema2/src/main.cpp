#include <iostream>
#include "Swordsman.hpp"
#include "Archer.hpp"
#include "Enemy.hpp"

int main(){
    char p1_name[]="Ionut", p2_name[]="Maria", p3_name[]="Solomon";
    Player* p1 = new Swordsman(p1_name);
    Player* p2 = new Swordsman(p2_name);
    Player* p3 = new Archer(p3_name);
    p1->sayHello();
    p1 = p2;
    p1->sayHello();
    p2->sayHello();

    p1->giveArmor();
    Enemy* e1 = new Enemy(10,9);
    p1->takeDamage(e1->attack());
    p1->sayHello();
    p2 = std::move(p1);
    p1->sayHello();
    delete e1;
    delete p1;
    //delete p2;
    delete p3;
    return 0;
}