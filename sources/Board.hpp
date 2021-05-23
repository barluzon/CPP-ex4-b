#pragma once
#include <iostream>
#include <set>
#include <unordered_map>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic {
    struct cityInfo{
        string city;
        Color color;
        set<City> neighbors;
        bool stationExist = false;
    };

    class Board {
    public:
        unordered_map<City,cityInfo> cities;
        unordered_map<City,int> diseaseLevel {};
        unordered_map<Color,bool> cured;
        int stationsNum = 0;
        int medicinesNum = 0;
        Board();
        ~Board() {}
        int &operator[](City city) {
            return this->diseaseLevel[city];
        };
        void remove_cures();
        bool is_clean();
        string get_color(Color color);
        cityInfo &operator()(City city) {
            return cities.at(city);
        };
        friend ostream &operator<<(ostream& out, Board& b);

    };
}