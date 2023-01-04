/*
* @file PointCloudRecorder.cpp
* @author Ipek Birinci (152120191020)
* @date 14.12.2022
* @brief PointCloudRecorder cpp file
*
*/

#include "PointCloudRecorder.h"


PointCloudRecorder::PointCloudRecorder(const string& fileName) : fileName(fileName) {}// file name alan method
//fileName atayan fonksiyon
void PointCloudRecorder::setFileName(const string& fileName) { this->fileName = fileName; }
//fileName get eden fonksiyon
string PointCloudRecorder::getFileName() const { return fileName; }
//file acilirsa bool olarak true ya da false donduren fonksiyon
bool PointCloudRecorder::save(const PointCloud& pointcloud) {
    ofstream out(fileName);
    if (!out.is_open()) {
        return false;
    }

    out << pointcloud.getPointNumber() << '\n';

    out << pointcloud.getPoints();

    return true;
}

