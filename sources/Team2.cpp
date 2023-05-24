#include "exception"
#include "vector"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h>
#include "Team2.hpp"

using namespace std;

namespace ariel {
    Team2::Team2(Character* leader) : Team(leader){
        this->leader = leader;
        if(this->characters.size() == 0){
            this->characters.push_back(leader);
        }
        // this->add(leader);
    }
}