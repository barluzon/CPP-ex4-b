#include "Scientist.hpp"
#include <iostream>

namespace pandemic {
    Player& Scientist::discover_cure(Color c) {
        int counter = 0;
        for (auto runner : this->cards) {
            if (board.cities[runner].color == c) {
                counter++;
            }
        }
        if (!board.cities[this->city].stationExist || counter < nCards) {
            string exc = "can't discover cure for " + board.cities[this->city].city;
            throw invalid_argument(exc);
        }
        counter = 0;
        for (auto runner = this->cards.begin(); runner != this->cards.end() && counter < nCards; ) {
            if (board.cities[*runner].color == c) {
                runner = this->cards.erase(runner);
                counter++;
            } else {runner++;}
        }
        board.cured[c] = true;
        return *this;
    }
}