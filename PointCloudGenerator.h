#pragma once
#include "Transform.h"

class PointCloud;

class PointCloudGenerator {
public:
    PointCloudGenerator(const Transform& transform) : transform_(transform) {}

    PointCloud capture();
    
    PointCloud captureFor(int duration);
    

    
private:

	Transform transform_;
};