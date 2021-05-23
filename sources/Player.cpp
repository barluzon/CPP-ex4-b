#include "Player.hpp"
#include <iostream>

const int NUM_OF_CARDS = 5;

namespace pandemic {
    Player& Player::drive(City c) {
        if (this->city==c || board.cities[this->city].neighbors.count(c) == 0) {
            string exc = "outside area - can't drive to " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        this->city = c;
        return *this;
    }

    Player& Player::fly_direct(City c) {
        if (this->city == c || this->cards.count(c) == 0) {
            string exc = "outside area - can't fly direct to " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        this->city = c;
        this->cards.erase(c);
        return *this;
    }

    Player& Player::fly_charter(City c) {
        if (this->city == c || this->cards.count(this->city) == 0) {
            string exc = "outside area - can't fly charter to " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        this->cards.erase(this->city);
        this->city = c;
        return *this;
    }

    Player& Player::fly_shuttle(City c) {
        if (this->city == c || !board.cities[this->city].stationExist || !board.cities[c].stationExist) {
            string exc = "outside area - can't fly shuttle to " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        this->city = c;
        return *this;
    }

    Player& Player::build() {
        if (board.cities[this->city].stationExist) {
            return *this;
        }
        if (this->cards.count(this->city)==0) {
            string exc = "can't build station in " + board.cities[this->city].city;
            throw invalid_argument(exc);
        }
        if (!board.cities[this->city].stationExist) {
            this->cards.erase(this->city);
            this->board.stationsNum++;
            board.cities[this->city].stationExist = true;
        }
        return *this;
    }

    Player& Player::discover_cure(Color c) {
        int counter = 0;
        for (auto runner : this->cards) {
            if (board.cities[runner].color==c) {counter++;}
            if (counter >= NUM_OF_CARDS) {break;}
        }
        if (!board.cities[this->city].stationExist || counter < NUM_OF_CARDS) {
            string exc = "can't discover cure for " + board.cities[this->city].city;
            throw invalid_argument(exc);
        }
        if (board.cured[c]) {return *this;}
        counter = 0;
        for (auto runner = this->cards.begin(); runner != this->cards.end() && counter < NUM_OF_CARDS; ) {
            if (board.cities[*runner].color==c) {
                runner = this->cards.erase(runner);
                counter++;
            } else {runner++;}
        }
        board.cured[c] = true;
        return *this;
    };

    Player& Player::treat(City c) {
        if (this->city!= c || board[this->city] == 0) {
            string exc = "can't treat " + board.cities[c].city;
            throw invalid_argument(exc);
        }
        if (board.cured[board.cities[this->city].color]) {
            board[this->city] = 0;
            return *this;
        }
        board[this->city]--;
        return *this;
    }

    Player& Player::take_card(City c) {
        this->cards.insert(c);
        return *this;
    }
}