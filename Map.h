#pragma once
#include <string>
#include<fstream>
#include <vector>
#include "PointCloud.h"


using namespace std;

class PointCloud;
class Point;

class Map {
public:
    Map() : data_() {}

	// Set/get functions goes here
	void setMapData(const PointCloud&);
	PointCloud getMapData() const;



    void insertPointCloud(PointCloud& pc);

    void insertPoint(Point& p);

    bool loadMap(const std::string& file_name);

    bool saveMap(const std::string& file_name);

private:
    PointCloud data_;
	// Map data goes here
};