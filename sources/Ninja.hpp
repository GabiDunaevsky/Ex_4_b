#pragma once
#include "Character.hpp"
// #include "YoungNinja.hpp"
// #include "OldNinja.hpp"
// #include "TrainedNinja.hpp"

namespace ariel {
    class Ninja : public Character {
        public:
            int speed;

            Ninja();
            Ninja(std::string name, Point point);
            // virtual ~Ninja();
            void move(Character* enemy);
            void slash(Character* enemy);
            std::string print() override;
    };
}