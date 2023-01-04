
/*
* @file Point.h
* @author Umut Birinci (152120171046)
* @date 17.12.2022
* @brief Header of Point class.
*/
#pragma once
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

class Point {
    friend class PointCloud;

private:

    double x; // x coordinate of point
    double y; // y coordinate of point
    double z; // z coordinate of point

public:

    //Constructor Function
    Point();
    Point(double, double, double);
    //Setter-Getter Functions
    void setX(double);
    double getX() const;
    void setY(double);
    double getY() const;
    void setZ(double);
    double getZ() const;
    //Equal Operator Overload Function
    bool operator==(const Point&)const;
    //Calculate Distance Func.
    double distance(const Point&)const;
};
