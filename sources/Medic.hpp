#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
    class Medic: public Player {
    public:
        Medic(Board& b, City c): Player(b,c,"Medic") { }
        ~Medic() {}
        Player& drive(City c);
        Player& fly_direct(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        Player& treat(City c);
    };
}