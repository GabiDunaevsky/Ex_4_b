#include "exception"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "YoungNinja.hpp"

using namespace std;

namespace ariel {
    YoungNinja::YoungNinja(std::string name, Point point): Ninja(name, point){
        this->name = name;
        this->loc.setX(point.getX());
        this->loc.setY(point.getY());
        this->speed = 14;
        this->targetPoints = 100;
    }
}