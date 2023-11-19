#include <iostream>
#include "Player.hpp"

class Swordsman : public Player{
    public:
        using Player::Player;
        ~Swordsman();
        Swordsman& operator=(const Swordsman& source);
        Swordsman& operator=(Swordsman&& source);
        int attack();
        void giveBroadSword();
    private:
        bool hasBroadSword=false;
};