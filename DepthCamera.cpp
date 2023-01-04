/*
* @file DepthCamera.cpp
* @author Fethi Guralp Albayram (152120171051)
* @date 17.12.2022
* @brief Source File of DepthCamera class
*
* This file is used to implement depth camera functions.
*/

#include "DepthCamera.h"


DepthCamera::DepthCamera(const string& fileName) : fileName(fileName) {}


void DepthCamera::setFilename(const string& fileName) { this->fileName = fileName; }
string DepthCamera::getFilename() const { return fileName; }



PointCloud DepthCamera::capture() {


    // Open the file specified by fileName in input mode
    ifstream file(fileName);

    file.open(fileName);


    // Read the number of points in the point cloud
    int pnumber;
    file >> pnumber;

    // Initialize a PointCloud object with the specified number of points
    PointCloud pCloud(pnumber);

    Point* rgb = new Point[pCloud.getPointNumber()];
    Point* points = new Point[pCloud.getPointNumber()];
    // Read the points from the file and set them in the PointCloud object
    for (int i = 0; i < pnumber; ++i) {
        double x, y, z, r, g, b;
        file >> x >> y >> z;
        points[i] = Point(x, y, z);
        file >> r >> g >> b;
        rgb[i] = Point(r, g, b);
    }

    pCloud.setPoints(points);

    // Close the file and return the PointCloud object
    file.close();
    return pCloud;



}

