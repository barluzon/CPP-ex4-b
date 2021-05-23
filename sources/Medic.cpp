#include "Medic.hpp"
#include <iostream>

namespace pandemic {
    Player& Medic::treat(City c) {
        if (this->city!=c || board[this->city] == 0) {
            string exc = "can't treat " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        board[this->city] = 0;
        return *this;
    }

    Player& Medic::drive(City c) {
        Player::drive(c);
        if (board.cured[board.cities[this->city].color]) {
            board[c] = 0;
        }
        return *this;
    }

    Player& Medic::fly_direct(City c) {
        Player::fly_direct(c);
        if (board.cured[board.cities[this->city].color]) {
            board[c] = 0;
        }
        return *this;
    }

    Player& Medic::fly_charter(City c) {
        Player::fly_charter(c);
        if (board.cured[board.cities[this->city].color]) {
            board[c] = 0;
        }
        return *this;
    }

    Player& Medic::fly_shuttle(City c) {
        Player::fly_shuttle(c);
        if (board.cured[board.cities[this->city].color]) {
            board[c] = 0;
        }
        return *this;
    }
}