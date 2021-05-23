#include "Researcher.hpp"
#include <iostream>

const int NUM_OF_CARDS = 5;

namespace pandemic {
    Player& Researcher::discover_cure(Color c) {
        int counter = 0;
        for (auto runner : this->cards) {
            if (board.cities[runner].color==c) {
                counter++;
            }
        }
        if (counter<NUM_OF_CARDS) {
            string exc = "can't discover cure for " + board(this->city).city;
            throw invalid_argument(exc);
        }
        counter = 0;
        for (auto runner = this->cards.begin(); runner != this->cards.end() && counter < NUM_OF_CARDS; ) {
            if (board.cities[*runner].color==c) {
                runner = this->cards.erase(runner);
                counter++;
            } else {runner++;}
        }
        board.cured[c] = true;
        return *this;
    }
}