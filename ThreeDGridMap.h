
/*
* @file ThreeDGridMap.cpp
* @author Fethi Guralp Albayram (152120171051)
* @date 18.12.2022
* @brief Source File of ThreeDGridMap class
*
* This file is used to implement 3D GridMap functions.
*/


// ThreeDGridMap.h
// This is the header file for the ThreeDGridMap class, which represents a 3D grid map.
// This directive tells the compiler to include this file in the current source code only once, even if it is included multiple times.
#pragma once
#ifndef ThreeDGRIDMAP_H
#define ThreeDGRIDMAP_H


// These preprocessor directives prevent the header file from being included multiple times, which can cause compilation errors.

#include <vector>
#include<fstream>
#include<string>
#include<iostream>
#include<algorithm>
// These headers are included to use various C++ standard library functions and types, such as vector and iostream.

#include "PointCloud.h"
#include "Point.h"
// These headers are included to use the PointCloud and Point classes, which are likely defined in separate header files.

class ThreeDGridMap
{
public:
	// This declares the ThreeDGridMap class and specifies that the following members are public.


	ThreeDGridMap(int depth, float gridSize);
	// This is the constructor for the ThreeDGridMap class, which takes in two arguments: the depth of the grid map and the size of each grid cell.

	void insertPointCloud(PointCloud& pc);
	void insertPoint(Point& p);
	// These are member functions of the ThreeDGridMap class that allow the user to insert a PointCloud or a single Point into the grid map.

	bool getGrid(int x, int y, int z) const;
	// This is a member function that allows the user to retrieve the value of a specific grid cell in the map, given its x, y, and z coordinates. The "const" keyword indicates that this function does not modify the object it is called on.

	bool loadMap(const std::string& fileName);
	bool saveMap(const std::string& fileName);
	// These are member functions that allow the user to load and save the grid map from and to a file, respectively.

	void setGridSize(float size);
	float getGridSize() const;
	// These are member functions that allow the user to set and get the size of each grid cell in the map.

	void setDepth(int depth);
	int getDepth() const;
	// These are member functions that allow the user to set and get the depth of the grid map.
private:
	// This specifies that the following members are private, which means they can only be accessed by other members of the ThreeDGridMap class.

	std::vector<std::vector<std::vector<bool>>> map;
	// This declares a 3D vector of boolean values to represent the grid map.

	float gridSize;
	int depth;
	// These variables store the size of each grid cell and the depth of the grid map, respectively.
};

#endif // ThreeDGRIDMAP_H
// This directive closes the #ifndef block that was opened at the beginning of the header file.