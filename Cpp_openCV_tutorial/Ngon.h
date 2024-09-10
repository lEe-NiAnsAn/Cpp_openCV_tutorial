#pragma once
#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
using namespace cv;

#define PI 3.14159265358
class Ngon        //�������
{
public:
        Ngon(int n, int len, Point center, double rotate = 0.0);
        Ngon(const Ngon& hg);        
        std::vector<Point> m_v;        //��������
private:
        int m_n;        //����
        double m_angle;        //�ڽ�
        double m_len;        //�߳�
        double m_rotate;    //��ת�Ƕ�
        Point m_center;        //���ĵ�
        void fill_v(std::vector<Point>& v);  //��������
};