#include "exception"
#include "vector"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h>
#include "Cowboy.hpp"

using namespace std;

namespace ariel {
    Cowboy::Cowboy(string name, Point point) : Character(name, point){
        this->name = name;
        this->loc.setX(point.getX());
        this->loc.setY(point.getY());
        this->bouletAmount = 6;
        this->targetPoints = 110;
    }
    void Cowboy::shoot(Character* enemy){
        if(!(enemy->isAlive())){
            throw std::runtime_error("Cant attack a dead character");
        }
        if(!(this->isAlive())){
            throw std::runtime_error("dead character cant attack");
        }
        if(enemy == this){
            throw std::runtime_error("No self harm");
        }
        if(this->bouletAmount > 0 && this->isAlive()){
            enemy->hit(10);
            this->bouletAmount -= 1;
        }
    }
    bool Cowboy::hasboolets(){
        if(this->bouletAmount > 0){
            return true;
        }
        return false;
    }
    void Cowboy::reload(){
        if(!(this->isAlive())){
            throw std::runtime_error("Cow boy is dead cant reload");
        }
        this->bouletAmount = 6;
    }
    std::string Cowboy::print() {
        std::string name;;
        std::string targetPoints;
        if(this->targetPoints <= 0){
            name = "( " + this->name + ")";
            targetPoints = "";
        }else{
            targetPoints = std::to_string(this->targetPoints);
            name = this->name;
        }
        return "C " + name + ", " + targetPoints +  ", " + this->loc.print();
    }
}