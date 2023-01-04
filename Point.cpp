/*
* @file Point.cpp
* @author Umut Birinci (152120171046)
* @date 17.12.2022
* @brief Source File of Point class.
*/
#include "Point.h"
// Constructor that takes three double values for the x, y, and z coordinates and sets the member variables to these values.
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}
// Default constructor that sets the member variables to 0.
Point::Point() : x(0), y(0), z(0) {}
// Function that sets the value of the x coordinate.
void Point::setX(double x) { this->x = x; }
// Function that returns the value of the x coordinate.
double Point::getX() const { return x; }
// Function that sets the value of the y coordinate.
void Point::setY(double y) { this->y = y; }
// Function that returns the value of the y coordinate.
double Point::getY() const { return y; }
// Function that sets the value of the z coordinate.
void Point::setZ(double z) { this->z = z; }
// Function that returns the value of the y coordinate.
double Point::getZ() const { return z; }
// Overloads the == operator to allow two points to be compared for equality by comparing their x, y, and z coordinates.
bool Point::operator==(const Point& point)const {
    return x == point.x && y == point.y && z == point.z;
}
// Calculates the Euclidean distance between two points using the formula.
double Point::distance(const Point& point) const {
    double dx = x - point.x;
    double dy = y - point.y;
    double dz = z - point.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}


