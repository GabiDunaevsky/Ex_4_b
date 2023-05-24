#pragma once
#include "vector"
#include "string"
#include <exception>
#include <stdexcept>
#include <iostream>


namespace ariel{
     class Point{
        private:
            double xVal;
            double yVal;
            
        public:
            Point();
            Point(double xVal , double yVal);
            // ~Point();
            double distance(const Point& point);
            std::string print();
            Point static moveTowards(const Point& src ,const Point& dest, double distance);
            void setX(double xVal);
            void setY(double yVal);
            double getX();
            double getY();

            // Point(const Point&) = delete;

            // //Delete copy assignment operator
            // Point& operator=(const Point&) = delete;

            // // Delete move constructor
            // Point(Point&&) = delete;

            // // Delete move assignment operator
            // Point& operator=(Point&&) = delete;
    };
}