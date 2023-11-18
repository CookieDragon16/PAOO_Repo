#include <iostream>
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
    public:
        virtual int attack() = 0;
        virtual void takeDamage(int dmg) = 0;
};

#endif