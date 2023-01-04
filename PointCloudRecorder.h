
/*
* @file PointCloudRecorder.h
* @author Ipek Birinci (152120191020)
* @date 23.12.2022
* @brief PointCloudRecorder header file
*
*/

#pragma once
#include "PointCloud.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class PointCloudRecorder {


private:
    string fileName;
public:
    PointCloudRecorder(const string&);
    void setFileName(const string&);
    string getFileName() const;
    bool save(const PointCloud&);
};

