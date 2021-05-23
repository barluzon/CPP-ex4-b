#include "Board.hpp"
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    Board::Board() {
        cured = {
                {Color::Black,false},
                {Color::Yellow,false},
                {Color::Blue,false},
                {Color::Red,false}
        };
        cities = {
            {City::Algiers,(cityInfo){"Algiers",Color::Black,{City::Madrid, City::Paris, City::Istanbul, City::Cairo}}},
            {City::Atlanta,(cityInfo){"Atlanta",Color::Blue,{City::Chicago, City::Miami, City::Washington}}},
            {City::Baghdad,(cityInfo){"Baghdad",Color::Black,{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}}},
            {City::Bangkok,(cityInfo){"Bangkok",Color::Red,{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}}},
            {City::Beijing,(cityInfo){"Beijing",Color::Red,{City::Shanghai, City::Seoul}}},
            {City::Bogota,(cityInfo){"Bogota",Color::Yellow,{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}}},
            {City::BuenosAires,(cityInfo){"BuenosAires",Color::Yellow,{City::Bogota, City::SaoPaulo}}},
            {City::Cairo,(cityInfo){"Cairo",Color::Black,{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}}},
            {City::Chennai,(cityInfo){"Chennai",Color::Black,{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}}},
            {City::Chicago,(cityInfo){"Chicago",Color::Blue,{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}}},
            {City::Delhi,(cityInfo){"Delhi",Color::Black,{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}}},
            {City::Essen,(cityInfo){"Essen",Color::Blue,{City::London, City::Paris, City::Milan, City::StPetersburg}}},
            {City::HoChiMinhCity,(cityInfo){"HoChiMinhCity",Color::Red,{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}}},
            {City::HongKong,(cityInfo){"HongKong",Color::Red,{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}}},
            {City::Istanbul,(cityInfo){"Istanbul",Color::Black,{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}}},
            {City::Jakarta,(cityInfo){"Jakarta",Color::Red,{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}}},
            {City::Johannesburg,(cityInfo){"Johannesburg",Color::Yellow,{City::Kinshasa, City::Khartoum}}},
            {City::Karachi,(cityInfo){"Karachi",Color::Black,{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}}},
            {City::Khartoum,(cityInfo){"Khartoum",Color::Yellow,{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}}},
            {City::Kinshasa,(cityInfo){"Kinshasa",Color::Yellow,{City::Lagos, City::Khartoum, City::Johannesburg}}},
            {City::Kolkata,(cityInfo){"Kolkata",Color::Black,{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}}},
            {City::Lagos,(cityInfo){"Lagos",Color::Yellow,{City::SaoPaulo, City::Khartoum, City::Kinshasa}}},
            {City::Lima,(cityInfo){"Lima",Color::Yellow,{City::MexicoCity, City::Bogota, City::Santiago}}},
            {City::London,(cityInfo){"London",Color::Blue,{City::NewYork, City::Madrid, City::Essen, City::Paris}}},
            {City::LosAngeles,(cityInfo){"LosAngeles",Color::Yellow,{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}}},
            {City::Madrid,(cityInfo){"Madrid",Color::Blue,{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}}},
            {City::Manila,(cityInfo){"Manila",Color::Red,{City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}}},
            {City::MexicoCity,(cityInfo){"MexicoCity",Color::Yellow,{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}}},
            {City::Miami,(cityInfo){"Miami",Color::Yellow,{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}}},
            {City::Milan,(cityInfo){"Milan",Color::Blue,{City::Essen, City::Paris, City::Istanbul}}},
            {City::Montreal,(cityInfo){"Montreal",Color::Blue,{City::Chicago, City::Washington, City::NewYork}}},
            {City::Moscow,(cityInfo){"Moscow",Color::Black,{City::StPetersburg, City::Istanbul, City::Tehran}}},
            {City::Mumbai,(cityInfo){"Mumbai",Color::Black,{City::Karachi, City::Delhi, City::Chennai}}},
            {City::NewYork,(cityInfo){"NewYork",Color::Blue,{City::Montreal, City::Washington, City::London, City::Madrid}}},
            {City::Osaka,(cityInfo){"Osaka",Color::Red,{City::Taipei, City::Tokyo}}},
            {City::Paris,(cityInfo){"Paris",Color::Blue,{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}}},
            {City::Riyadh,(cityInfo){"Riyadh",Color::Black,{City::Baghdad, City::Cairo, City::Karachi}}},
            {City::SanFrancisco,(cityInfo){"SanFrancisco",Color::Blue,{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}}},
            {City::Santiago,(cityInfo){"Santiago",Color::Yellow,{City::Lima}}},
            {City::SaoPaulo,(cityInfo){"SaoPaulo",Color::Yellow,{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}}},
            {City::Seoul,(cityInfo){"Seoul",Color::Red,{City::Beijing, City::Shanghai, City::Tokyo}}},
            {City::Shanghai,(cityInfo){"Shanghai",Color::Red,{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}}},
            {City::StPetersburg,(cityInfo){"StPetersburg",Color::Blue,{City::Essen, City::Istanbul, City::Moscow}}},
            {City::Sydney,(cityInfo){"Sydney",Color::Red,{City::Jakarta, City::Manila, City::LosAngeles}}},
            {City::Taipei,(cityInfo){"Taipei",Color::Red,{City::Shanghai, City::HongKong, City::Osaka, City::Manila}}},
            {City::Tehran,(cityInfo){"Tehran",Color::Black,{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}}},
            {City::Tokyo,(cityInfo){"Tokyo",Color::Red,{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}}},
            {City::Washington,(cityInfo){"Washington",Color::Blue,{City::Atlanta, City::NewYork, City::Montreal, City::Miami}}}
        };
    }
    void Board::remove_cures() {
        for (auto &runner : cured){
            runner.second = false;}
    }
    string get_color(Color color) {
        if (color==Color::Black) {return "Black";}
        if (color==Color::Yellow) {return "Yellow";}
        if (color==Color::Blue) {return "Blue";}
        return "Red";
    }

    bool Board::is_clean() {
        for (auto &runner : cities) {
                if (diseaseLevel.count(runner.first)!=0 && diseaseLevel[runner.first]>0) {
                    return false;}
        }
        return true;
    }

    ostream &operator<<(ostream& out, Board& board) {
        return out;
    };
}