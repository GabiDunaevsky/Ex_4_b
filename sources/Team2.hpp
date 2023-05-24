#pragma once
#include "vector"
#include "string"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "Team.hpp"


namespace ariel{
     class Team2 : public Team {
        public:
            Team2(Character* leader);
    };
}