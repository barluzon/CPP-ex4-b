#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Scientist: public Player {
        int nCards;
    public:
        Scientist(Board& b, City c, int num): Player(b,c,"Scientist") {
            nCards = num;
        }
        ~Scientist() {}
        Player& discover_cure(Color c);
    };
}