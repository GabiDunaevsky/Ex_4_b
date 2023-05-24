#include "exception"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "TrainedNinja.hpp"

using namespace std;

namespace ariel {
    TrainedNinja::TrainedNinja(std::string name, Point point) : Ninja(name, point){
        this->name = name;
        this->loc.setX(point.getX());
        this->loc.setY(point.getY());
        this->speed = 12;
        this->targetPoints = 120;
    }
}