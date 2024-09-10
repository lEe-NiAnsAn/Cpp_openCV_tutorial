#pragma once
#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
using namespace cv;

#define PI 3.14159265358
class Ngon        //正多边形
{
public:
        Ngon(int n, int len, Point center, double rotate = 0.0);
        Ngon(const Ngon& hg);        
        std::vector<Point> m_v;        //顶点容器
private:
        int m_n;        //边数
        double m_angle;        //内角
        double m_len;        //边长
        double m_rotate;    //旋转角度
        Point m_center;        //中心点
        void fill_v(std::vector<Point>& v);  //填入容器
};