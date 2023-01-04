#include<iostream>
#include<vector>
#include"MapperInterface.h"
#include"PointCloudGenerator.h"
#include"Pointcloud.h"

using namespace std;


PointCloud PointCloudGenerator::capture() {
	PointCloud pointcloud(100);
	return pointcloud;
}

PointCloud PointCloudGenerator::captureFor(int duration) {
	PointCloud pointcloud(100);
	return pointcloud;
}
