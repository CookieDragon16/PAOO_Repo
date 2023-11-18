#include <iostream>
#include "Character.hpp"

class Enemy : public Character{
    public:
        Enemy(int HP, int dmg);
        ~Enemy();
        void takeDamage(int dmg);
        int attack();
    private:
        int HP;
        int attackDmg;
};