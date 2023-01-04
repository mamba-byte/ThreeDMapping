
#pragma once
#include <fstream>
#include <string>
#include "PointCloud.h"

using namespace std;

class DepthCamera {
private:
    string fileName;

public:
    //Constructor
    DepthCamera(const string&);
    //Set-Get Functions
    void setFilename(const string&);
    string getFilename() const;

    PointCloud capture();
};
