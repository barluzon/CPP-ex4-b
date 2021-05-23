#include "OperationsExpert.hpp"
#include <iostream>

namespace pandemic {
    Player& OperationsExpert::build() {
        if (!board.cities[this->city].stationExist) {
            this->board.stationsNum++;
            board.cities[this->city].stationExist = true;
        }
        return *this;
    }
}