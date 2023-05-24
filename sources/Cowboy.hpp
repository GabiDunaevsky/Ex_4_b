#pragma once
#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character{
        int bouletAmount;

        public:
            Cowboy(std::string name, Point point);
            // virtual ~Cowboy();
            void shoot(Character* enemy);
            bool hasboolets();// implement
            void reload(); //implement
            std::string print() override;
        };
}