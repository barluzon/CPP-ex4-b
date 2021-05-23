#include "FieldDoctor.hpp"
#include <iostream>

namespace pandemic {
    Player& FieldDoctor::treat(City c) {
        bool exist = false;
        if (this->city == c) {exist = true;}
        else {for (auto nei : board.cities[this->city].neighbors) {
                if (nei == c) {
                    exist = true;}
        }}
        if (!exist || board[c] == 0) {
            string exc = "outside area - can't treat " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        if (board.cured[board.cities[c].color]) {
            board[c] = 0;
            return *this;
        }
        board[c]--;
        return *this;
    }
}