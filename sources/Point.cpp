#include "exception"
#include "vector"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h>
#include "Point.hpp"
/*
Sources for this class:
https://www.geeksforgeeks.org/program-calculate-distance-two-points/

*/

using namespace std;

namespace ariel {
    Point::Point(double xVal, double yVal){
        this->xVal = xVal;
        this->yVal = yVal;
    }

    double Point::distance(const Point& point){
        return sqrt(pow(this->xVal - point.xVal, 2) + pow(this->yVal - point.yVal, 2) * 1.0);
    }
    string Point::print(){
        string str = "(" + std::to_string(this->xVal) + "," + std::to_string(this->yVal) + ")";
        // cout << str << endl;
        return str;
    }
    Point Point::moveTowards(const Point& src ,const Point& dest, double distance){
        if(distance < 0){
            throw std::invalid_argument("Disatane cant be negative");
        }
        double dist = sqrt(pow(src.xVal - dest.xVal, 2) + pow(src.yVal - dest.yVal, 2) * 1.0);
        if(distance >= dist){
            return dest;
        }else{
            // I took this part from gpt
            double ratio = distance / dist;
            // Calculate the coordinates of the point
            double newX = src.xVal + (dest.xVal - src.xVal) * ratio;
            double newY = src.yVal + (dest.yVal - src.yVal) * ratio;
            // Create and return the new point
            Point newPo(newX,newY);
            return newPo;
        }

        return src;
    }
    void Point::setX(double xVal){
        this->xVal = xVal;
    }
    void Point::setY(double yVal){
        this->yVal = yVal;
    }
    double Point::getX(){
        return this->xVal;
    }
    double Point::getY(){
        return this->yVal;
    }
    // Point::~Point(){

    // }

}