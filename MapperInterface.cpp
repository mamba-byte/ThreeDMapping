#include<iostream>
#include<vector>
#include"MapperInterface.h"
#include"PointCloudGenerator.h"
#include"PointCloud.h"

using namespace std;


void MapperInterface::addGenerator(PointCloudGenerator* generator)
{
	generators_.push_back(generator);
}

void MapperInterface::setRecorder(PointCloudRecorder* recorder)
{
	recorder_ = recorder;
}

bool MapperInterface::generate()
{
	for (PointCloudGenerator* generator : generators_) {
		PointCloud pc = generator->captureFor();
		point_cloud_->insert(pc);
	}
	return true;
}

bool MapperInterface::recordPointCloud()
{
	if (recorder_ == nullptr) {
		return false;
	}
	return recorder_->record(*point_cloud_);
}

bool MapperInterface::recordMap()
{
	if (recorder_ == nullptr) {
		return false;
	}
	return recorder_->record(*map_);
}

bool MapperInterface::insertMap()
{
	map_->insertPointCloud(*point_cloud_);
	return true;
}