#include "exception"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "OldNinja.hpp"

using namespace std;

namespace ariel {
    OldNinja::OldNinja(std::string name, Point point) : Ninja(name, point){
        this->name = name;
        this->loc.setX(point.getX());
        this->loc.setY(point.getY());
        this->speed = 8;
        this->targetPoints = 150;
    }
}