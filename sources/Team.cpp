#include "exception"
#include "vector"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h>
#include "Team.hpp"

using namespace std;

namespace ariel {
    Team::Team(Character* leader){
        this->leader = leader;
        if(leader->inAteam != 0){
            throw std::runtime_error("Already in a team");
        }
        leader->inAteam = 1;
        if(this->characters.size() == 0){
            this->characters.push_back(leader);
        }
        this->leaderLocation = 0;
        // this->add(leader);
    }
    void Team::add(Character* character){
        if(this->characters.size() >= 10){
             throw std::runtime_error("there are more then 10 characters can't add a new one for this team");
        }
        if(character->inAteam != 0){
            throw std::runtime_error("Already in a team");
        }
        character->inAteam = 1;
        this->characters.push_back(character);
    }
    void Team::attack(Team* team){
        if(team == nullptr){
            throw std::invalid_argument("There is no team");
        }
        if(team->stillAlive() <= 0){
            throw std::runtime_error("everyone are dead");
        }
        if(this->stillAlive() <= 0){
            return;
        }
        if(!(this->characters[this->leaderLocation]->isAlive())){
           this->leaderLocation = findClosest(this,this->characters[this->leaderLocation]->loc);
           this->leader = this->characters[this->leaderLocation];
        }
        // cout << this->leader->print() << endl;
        // cout << this->leader->isAlive() << endl; 
        size_t vicLoc =  findClosest(team,this->characters.at(static_cast<std::vector<int>::size_type>(this->leaderLocation))->loc);
        // if(vicLoc1 == -1){
        //     return;
        // }
        // cout << this->characters.size() << endl;
        // cout << vicLoc1 << endl;
        // std::vector<int>::size_type vicLoc = static_cast<std::vector<int>::size_type>(vicLoc1);
        // cout <<"The enemy is: " << team->characters[vicLoc]->print()<< endl;
        // cout << this->leader->isAlive() << endl;
        Character* vic =  team->characters[vicLoc];
        for (size_t indx = 0; indx < this->characters.size(); indx++)
        {

            if(!(vic->isAlive()) && team->stillAlive() > 0){
                vicLoc = findClosest(team,this->characters.at(static_cast<std::vector<int>::size_type>(this->leaderLocation))->loc);
                vic = team->characters[vicLoc];
            }
            if(!(team->characters.at(vicLoc)->isAlive())){
                break;
            }
            Character* tmp = this->characters.at(indx);
            // cout << indx <<  " attaker is: " << tmp->print() << endl;
            if(!(tmp->isAlive())){
                continue;
            }
            // cout << typeid(*tmp).name() << endl;
            if(typeid(*tmp) == typeid(Cowboy)){
                Cowboy* tmp1 = dynamic_cast<Cowboy*>(tmp);
                if(tmp1->hasboolets()){
                    tmp1->shoot(vic);
                }else{
                    tmp1->reload();
                }
                
            }else{ //Ninja
                // Character* tmp1 = new Ninja();
                if(typeid(*tmp) == typeid(OldNinja)){
                    OldNinja* tmp1 = dynamic_cast<OldNinja*>(tmp);
                    if(tmp1->distance(vic) < 1){
                        tmp1->slash(vic);
                    }else{
                        tmp1->move(vic);
                    }
                    
                }else if(typeid(*tmp) == typeid(YoungNinja)){
                    YoungNinja* tmp1 = dynamic_cast<YoungNinja*>(tmp);
                    if(tmp1->distance(vic) < 1){
                        tmp1->slash(vic);
                    }else{
                        tmp1->move(vic);
                    }
                }else{
                    TrainedNinja* tmp1 = dynamic_cast<TrainedNinja*>(tmp);
                    // tmp = this->characters.at(indx);
                    if(tmp1->distance(vic) < 1){
                        tmp1->slash(vic);
                    }else{
                        tmp1->move(vic);
                    }
                }
            }
        }
    }
    int Team::stillAlive(){
        int counter = 0;
        for(Character* character : this->characters){
            if(character->isAlive()){
                counter++;
            }
        }
        return counter;
    }
    void Team::print(){
        
    }
    size_t Team::findClosest(Team* team, Point& point){
        double minDist = DBL_MAX;
        size_t loc = INT_MAX;
        for (size_t inx = 0; inx < team->characters.size(); inx++)
        {
            // cout << inx << " live: " << team->characters[inx]->isAlive()<< endl;
            // cout << team->characters.at(inx)->loc.distance(point) << endl;
            if(team->characters.at(inx)->isAlive()){
                if(team->characters.at(inx)->loc.distance(point) < minDist){
                    minDist = team->characters.at(inx)->loc.distance(point);
                    loc = inx;

                }
            }
        }
        // if(loc == -1){
        //     throw std::invalid_argument("no players alive");
        // }
        // cout << loc << endl;
        return loc;
    }
    Team::~Team(){
        for(Character* character : this->characters){
            delete character;  
        }
    }
}