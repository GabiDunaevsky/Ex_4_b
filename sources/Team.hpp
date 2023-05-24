#pragma once
#include "vector"
#include "string"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

//I was using chat gpt in the task

namespace ariel{
     class Team{
        public:


          std::vector<Character*> characters;
          Character* leader;
          size_t leaderLocation;
            
          virtual ~Team();
          Team();

          // Delete copy constructor
          Team(const Team&) = delete;

          // Delete copy assignment operator
          Team& operator=(const Team&) = delete;

          // Delete move constructor
          Team(Team&&) = delete;

          // Delete move assignment operator
          Team& operator=(Team&&) = delete;

          Team(Character* leader);
          void add(Character* character);
          void attack(Team* team);
          int stillAlive();
          void print();
          static size_t findClosest(Team* team, Point& point);

    };
}