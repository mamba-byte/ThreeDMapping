#include <string>
#include<fstream>
#include <vector>
#include "PointCloud.h"
#include"Map.h"

#include <map>


using namespace std;

void Map::setMapData(const PointCloud& pc) {
	data_ = pc;
}

PointCloud Map::getMapData() const {
	return data_;
}

void Map::insertPointCloud(PointCloud& pc) {
	data_ = data_ + pc;
}

void Map::insertPoint(Point& p) {
	PointCloud pc(1);
	pc.setPoints(&p);
	data_ = data_ + pc;
}

bool Map::loadMap(const std::string& file_name) {
	ifstream file;
	file.open(file_name);
	if (file.is_open()) {
		int pointNumber;
		file >> pointNumber;
		PointCloud pc(pointNumber);
		Point* points = new Point[pointNumber];
		for (int i = 0; i < pointNumber; i++) {
			float x, y, z;
			file >> x >> y >> z;
			Point p(x, y, z);
			points[i] = p;
		}
		pc.setPoints(points);
		data_ = pc;
		return true;
	}
	else {
		return false;
	}
}

bool Map::saveMap(const std::string& file_name) {
	ofstream file;
	file.open(file_name);
	if (file.is_open()) {
		file << data_.getPointNumber() << endl;
		for (int i = 0; i < data_.getPointNumber(); i++) {
			file << data_.getPoints()[i].getX() << " " << data_.getPoints()[i].getY() << " " << data_.getPoints()[i].getZ() << endl;
		}
		return true;
	}
	else {
		return false;
	}
}
