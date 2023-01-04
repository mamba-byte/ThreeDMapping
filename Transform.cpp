/*
* @file Transform.cpp
* @author Ipek Birinci (152120191020)
* @date 23.12.2022
* @brief Transform class cpp file
*
*/

#include "Transform.h"
#include <cmath>
#include <iostream>
#include <Eigen/Dense>
const double PI = 3.14159265358979323846;
//contructor fonksiyonu
Transform::Transform()
{
}
//destructor fonksiyonu
Transform::~Transform()
{
}
//acýlarý double degisken durunde, angle1,angle2,angle3 degiskenlerine set eden method
void Transform::setAngles(double angle1, double angle2, double angle3)
{
	using namespace Eigen;
	angles(0) = angle1;
	angles(1) = angle2;
	angles(2) = angle3;
}
//donusum degiskenlerini transx,transy,transz olarak set eden method(x-y-z her noktanýn uc boyutlu degisim degeridir)
void Transform::setTrans(double transx, double transy, double transz)
{
	using namespace Eigen;
	trans(0) = transx;
	trans(1) = transy;
	trans(2) = transz;
}
//set edilen acilerin getirildigi method
double* Transform::getAngles()
{
	double* angles = new double[3];
	angles[0] = this->angles(0);
	angles[1] = this->angles(1);
	angles[2] = this->angles(2);

	return angles;
}
//set edilen trans noktalari getiren method
double* Transform::getTrans()
{
	double* trans = new double[3];
	trans[0] = this->trans(0);
	trans[1] = this->trans(1);
	trans[2] = this->trans(2);

	return trans;
}
//textte alinan nokta kadar noktayi transform eden method(for dongusu point kadar doner)

list<Point> Transform::doTransForm(list<Point>points)
{

	Eigen::Vector4d vektor_matris;
	Eigen::Vector4d result_matris;

	auto it = points.begin();

	list<Point>new_points;
	Point p;

	for (it; it != points.end(); it++)
	{
		vektor_matris(0) = (*it).getX();
		vektor_matris(1) = (*it).getY();
		vektor_matris(2) = (*it).getZ();
		vektor_matris(3) = 1;

		result_matris = transMatrix * vektor_matris;

		p.setX(result_matris(0));
		p.setY(result_matris(1));
		p.setZ(result_matris(2));

		new_points.push_back(p);
	}
	return new_points;
}
//PointCloud tipinde degisken donusumu yapan ve txtdeki point kadar donusum yapan method
PointCloud Transform::doTransform(const PointCloud pc)const {
	Point* points = new Point[pc.lengthOfPoints()];
	Point* pSize = pc.getPoints();
	for (int i = 0; i < pc.lengthOfPoints(); i++)
		points[i] = this - doTransform(pSize[i]);
	PointCloud result = PointCloud(points, pc.lengthOfPoints());
	return result;
}
//yeni noktayi set eden ve degerleri ang degiskenine atayan method
void Transform::setRotation(Eigen::Vector3d ang) {

	angles(0) = ang[0];
	angles(1) = ang[1];
	angles(2) = ang[2];

	double gama = angles[0], beta = angles[1], alpha = angles[2];
	gama = (gama * PI / 180.0);
	beta = (beta * PI / 180.0);
	alpha = (alpha * PI / 180.0);

	transMatrix(0, 0) = round(cos(alpha)) * round(cos(beta));
	transMatrix(0, 1) = (round(cos(alpha)) * round(sin(beta)) * round(sin(gama))) - (round(sin(alpha)) * round(cos(gama)));
	transMatrix(0, 2) = (round(cos(alpha)) * round(sin(beta)) * round(cos(gama))) + (round(sin(alpha)) * round(sin(gama)));
	transMatrix(1, 0) = (round(sin(alpha)) * round(cos(beta)));
	transMatrix(1, 1) = (round(sin(alpha)) * round(sin(beta)) * round(sin(gama))) + (round(cos(alpha)) * round(cos(gama)));
	transMatrix(1, 2) = (round(sin(alpha)) * round(sin(beta)) * round(cos(gama))) - (round(cos(alpha)) * round(sin(gama)));
	transMatrix(2, 0) = round(-sin(beta));
	transMatrix(2, 1) = round(cos(beta)) * round(sin(gama));
	transMatrix(2, 2) = round(cos(beta)) * round(cos(gama));
	transMatrix(3, 0) = 0;
	transMatrix(3, 1) = 0;
	transMatrix(3, 2) = 0;
}
//trans vektorune yeni degerleri atayan method
void Transform::setTranslation(Eigen::Vector3d tr) {
	trans << tr[0], tr[1], tr[2];

	double X = trans[0], Y = trans[1], Z = trans[2];

	transMatrix(0, 3) = X;
	transMatrix(1, 3) = Y;
	transMatrix(2, 3) = Z;
	transMatrix(3, 3) = 1;
}