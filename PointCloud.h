/*
* @file PointClass.h
* @author Umut Birinci (152120171046)
* @date 18.12.2022
* @brief Header of PointCloud class.
*/
#pragma once
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include "Point.h"
#include <list>
#include <vector>
#include<fstream>
#include<string>

using namespace std;

class PointCloud {
    // Friend Class Definitions
    friend class PointCloudRecorder;
    friend class DepthCamera;
    friend class Transform;
    friend class ThreeDGridMap;

private:

    int pointNumber; // Number of points
    list<PointCloud> points; // The list of points

public:
    //Constructor Functions
    PointCloud(int);
    PointCloud(const PointCloud&);
    //Setter-Getter Functions
    void setPoints(Point*);
    Point* getPoints() const;
    void setPointNumber(int);
    int getPointNumber() const;
    //Addition Operator Overload Function
    PointCloud operator+(const PointCloud&) const;
    //Copy Operator Overload Function
    PointCloud& operator=(const PointCloud&);


};

