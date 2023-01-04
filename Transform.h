
/*
* @file Transform.h
* @author Ipek Birinci (152120191020)
* @date 23.12.2022
* @brief Transform header file
*
*/
#pragma once

#include "PointCloud.h"
#include <Eigen/Dense>


class Transform {
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;
public:
	Transform(); //constructor
	~Transform();//destructor
	void setAngles(double, double, double);//aci deðerlerini atayan fonk.
	void setTrans(double, double, double);//transform deðerlerini atayan fonk.
	Eigen::Matrix4d getTransMatrix();
	void setTransMatrix(Eigen::Matrix4d);
	double* getAngles();//acilari getiren fonk.
	double* getTrans();
	list<Point> doTransForm(list<Point>points);
	PointCloud doTransform(const PointCloud pc) const;
	PointCloud doTransform(PointCloud);
	void setRotation(Eigen::Vector3d ang);
	void setTranslation(Eigen::Vector3d tr);
};
