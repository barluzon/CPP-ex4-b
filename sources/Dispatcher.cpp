#include "Dispatcher.hpp"
#include <iostream>

namespace pandemic {
    Player& Dispatcher::fly_direct(City c) {
        if (this->city == c || (this->cards.count(c)==0 && !board.cities[this->city].stationExist)) {
            string exc = "outside area - can't fly direct to " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        if (!board.cities[this->city].stationExist) {
            this->cards.erase(c);
        }
        this->city = c;
        return *this;
    }
}