#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H
#include "Character.hpp"

class Player : public Character{
    public:
        Player(char* name);
        ~Player();
        void sayHello();
        void takeDamage(int dmg);
        virtual int attack() = 0;
        void giveArmor();
    protected:
        char* name;
        int HP=20;
        bool hasArmor=false;
};
#endif