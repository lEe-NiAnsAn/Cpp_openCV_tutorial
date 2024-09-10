#include "Ngon.h"

Ngon::Ngon(int n, int len, Point center, double rotate)
{
        this->m_n = n;
        this->m_len = len;
        this->m_center = center;
        this->m_angle = 360 / n;
        this->m_rotate = rotate;
        fill_v(this->m_v);
}
Ngon::Ngon(const Ngon& ng)
{
        this->m_n = ng.m_n;
        this->m_len = ng.m_len;
        this->m_center = ng.m_center;
        this->m_angle = ng.m_angle;
        this->m_rotate = ng.m_rotate;
        this->m_v = ng.m_v;
}
void Ngon::fill_v(std::vector<Point>& v)
{
        for (int m = 0; m < this->m_n; m++)
        {
                double angle = (this->m_angle * m) * PI / 180;
                double rotate = this->m_rotate * PI / 180;
                double r = (this->m_len / 2) / sin(PI / this->m_n);
                int x = this->m_center.x + cos(angle + rotate) * r;
                int y = this->m_center.y - sin(angle + rotate) * r;
                v.push_back(Point(x, y));
        }
}