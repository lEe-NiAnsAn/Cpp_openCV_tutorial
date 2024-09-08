#pragma once
#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
using namespace cv;

#define PI 3.14159265358
class Hexagon	//正六边形
{
public:
	Hexagon(int len, Point center);	
	Hexagon(const Hexagon& hg);	
	std::vector<Point> m_v;	//顶点容器
private:
	int m_n;	//边数
	double m_angle;	//内角
	double m_len;	//边长
	Point m_center;	//中心点
	void fill_v(std::vector<Point>& v);	//填入容器
};