/*
* @file PointCloud.cpp
* @author Umut Birinci (152120171046)
* @date 18.12.2022
* @brief Source File of PointCloud class.
*/
#include "PointCloud.h"
// Constructor that takes an integer representing the number of points in the point cloud. Allocates memory for an array of Point objects of this size
PointCloud::PointCloud(int pointNumber) : pointNumber(pointNumber) {
    points = new Point[pointNumber];
}
// Copy constructor that creates a deep copy of another PointCloud object.
PointCloud::PointCloud(const PointCloud& pointcloud) {
    pointNumber = pointcloud.pointNumber;
    points = pointcloud.points;
}

// Function that sets the value of the points array.
void PointCloud::setPoints(class Point* points) { this->points = points; }
//Function that returns the value of the points array.
Point* PointCloud::getPoints() const { return points; }
// Function that sets the value of the pointNumber member variable.
void PointCloud::setPointNumber(int pointNumber) { this->pointNumber = pointNumber; }
// Function that returns the value of the pointNumber member variable.
int PointCloud::getPointNumber() const { return pointNumber; }

// Overloads the + operator to allow two PointCloud objects to be concatenated by appending one to the other. Returns a new PointCloud object with the combined points.
PointCloud PointCloud::operator+(const PointCloud& pointcloud) const {
    int newpointNumber = pointNumber + pointcloud.pointNumber;
    Point* points = new Point[newpointNumber];
    copy(this->points, this->points + pointNumber, points);
    copy(pointcloud.points, pointcloud.points + pointcloud.pointNumber, points + pointNumber);
    return PointCloud(newpointNumber);
}
// Overloads the = operator to allow one PointCloud object to be assigned the value of another. Returns a reference to the assigned object.
PointCloud& PointCloud::operator=(const PointCloud& pointcloud) {
    if (this == &pointcloud) return *this;
    PointCloud temp(pointcloud);
    swap(pointNumber, temp.pointNumber);
    swap(points, temp.points);
    return *this;
}


