#include <iostream>
#include "Player.hpp"

class Swordsman : public Player{
    public:
        using Player::Player;
        int attack();
        void giveBroadSword();
    private:
        bool hasBroadSword=false;
};