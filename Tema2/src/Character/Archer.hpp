#include <iostream>
#include "Player.hpp"

class Archer : public Player{
    public:
        using Player::Player;
        ~Archer();
        Archer& operator=(const Archer& source);
        Archer& operator=(Archer&& source);
        int attack();
        void giveLongBow();
    private:
        bool hasLongBow=false;
};