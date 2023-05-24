#include "exception"
#include "vector"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h>
#include "Ninja.hpp"

using namespace std;

namespace ariel {
    Ninja::Ninja(std::string name, Point point) : Character(name, point){
        this->name = name;
        this->loc.setX(point.getX());
        this->loc.setY(point.getY());
    }
    void Ninja::move(Character* enemy){
        // Point tmp = this->loc.moveTowards(this->loc, enemy->loc,this->speed);
        // this->loc.setX(tmp.getX());
        // this->loc.setY(tmp.getY());
         // I took this part from gpt
        double dist = this->loc.distance(enemy->loc);
        double ratio = this->speed / dist;
        if(speed >= dist){
            this->loc.setX(enemy->loc.getX());
            this->loc.setY(enemy->loc.getY());
            
         }else{
            // Calculate the coordinates of the point
            this->loc.setX(this->loc.getX() + (enemy->loc.getX() - this->loc.getX()) * ratio);
            this->loc.setY(this->loc.getY()  + (enemy->loc.getY() - this->loc.getY()) * ratio);
         }

    }
    void Ninja::slash(Character* enemy){
        if(!(enemy->isAlive())){
            throw std::runtime_error("Cant attack a dead character");
        }
        if(!(this->isAlive())){
            throw std::runtime_error("dead character cant attack");
        }
        if(enemy == this){
            throw std::runtime_error("No self harm");
        }
        if(this->isAlive() && this->distance(enemy) < 1){
            enemy->hit(40);
        }
    }
    std::string Ninja::print() {
        std::string name;;
        std::string targetPoints;
        if(this->targetPoints <= 0){
            name = "( " + this->name + ")";
            targetPoints = "";
        }else{
            targetPoints = std::to_string(this->targetPoints);
            name = this->name;
        }
        return "N " + name + ", " + targetPoints + ", " + this->loc.print();
    }

}