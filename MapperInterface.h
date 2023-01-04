#pragma once
#include <vector>

class PointCloud;
class PointCloudGenerator;
class PointCloudRecorder;
class Map;

class MapperInterface {
public:
	//Constructor 
    MapperInterface(PointCloud* point_cloud, PointCloud* patch)
        : point_cloud_(point_cloud),
        patch_(patch),
        generators_(),
        recorder_(nullptr),
        map_(nullptr) {}

    void addGenerator(PointCloudGenerator* generator);
        

    void setRecorder(PointCloudRecorder* recorder);

    bool generate();


    bool recordPointCloud();

    bool recordMap();
     

    bool insertMap();

	//Destructor
	~MapperInterface()
	{
		
	}

private:
    PointCloud* point_cloud_;
    PointCloud* patch_;
    std::vector<PointCloudGenerator*> generators_;
    PointCloudRecorder* recorder_;
    Map* map_;
};
