#include <iostream>
#include "Player.hpp"

class Archer : public Player{
    public:
        using Player::Player;
        int attack();
        void giveLongBow();
    private:
        bool hasLongBow=false;
};