#pragma once
#include "vector"
#include "string"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "Point.hpp"
// #include "Cowboy.hpp"
// #include "Ninja.hpp"

namespace ariel{
     class Character{
        public:
            std::string name;
            Point loc;
            int targetPoints;
            int inAteam;
            
        
            Character();
            Character(std::string name , Point loc);
            // Character(Character&  other);
            virtual ~Character();
            bool isAlive();
            double distance(Character*);
            void hit(int hitPower);
            std::string getName();
            Point getLocation();
            virtual std::string print();
            // Character& operator=(const Character& other) = delete;  // Delete copy assignment operator
            // Character(Character&& other) noexcept = delete;
            // Character& operator=(Character&& other) noexcept = delete;
            // Delete copy constructor
            Character(const Character&) = delete;

            // Delete copy assignment operator
            Character& operator=(const Character&) = delete;

            // Delete move constructor
            Character(Character&&) = delete;

            // Delete move assignment operator
            Character& operator=(Character&&) = delete;
    };
}