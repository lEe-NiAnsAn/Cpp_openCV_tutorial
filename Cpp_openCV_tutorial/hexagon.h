#pragma once
#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
using namespace cv;

#define PI 3.14159265358
class Hexagon	//��������
{
public:
	Hexagon(int len, Point center);	
	Hexagon(const Hexagon& hg);	
	std::vector<Point> m_v;	//��������
private:
	int m_n;	//����
	double m_angle;	//�ڽ�
	double m_len;	//�߳�
	Point m_center;	//���ĵ�
	void fill_v(std::vector<Point>& v);	//��������
};