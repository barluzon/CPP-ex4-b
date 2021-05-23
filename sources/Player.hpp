#pragma once
#include <iostream>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic {
    class Player {
    protected:
        pandemic::Board& board;
        string pRole;
        City city;
        set<City> cards = {};
    public:
        Player(Board& b, City c, string pr): board(b), city(c), pRole(pr) {}
        ~Player() {}
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color city);
        virtual Player& treat(City city);
        string role() {return pRole;}
        Player& take_card(City city);
    };
}