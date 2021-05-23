#include "Virologist.hpp"
#include <iostream>

namespace pandemic {
    Virologist& Virologist::treat(City c) {
        if (board[c] == 0 || (this->city!=c && this->cards.count(c) == 0)) {
            string exc = "can't treat " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        if (this->city!=c) {
            this->cards.erase(c);
        }
        if (board.cured[board.cities[c].color]) {
            board[c] = 0;
        }
        else {board[c]--;}
        return *this;
    }
}