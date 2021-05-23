#include "GeneSplicer.hpp"
#include <iostream>

const int NUM_OF_CARDS = 5;

namespace pandemic {
    Player& GeneSplicer::discover_cure(Color c) {
        if (!board.cities[this->city].stationExist || this->cards.size()<NUM_OF_CARDS) {
            string exc = "can't discover cure for " + board.cities[this->city].city;
            throw invalid_argument(exc);
        }
        int counter = 0;
        for (auto runner = this->cards.begin(); runner != this->cards.end() && counter < NUM_OF_CARDS; ) {
            runner = this->cards.erase(runner);
            runner++;
            counter++;
        }
        board.cured[c] = true;
        return *this;
    }
}