#include "hexagon.h"

Hexagon::Hexagon(int len, Point center)
{
	this->m_n = 6;
	this->m_len = len;
	this->m_center = center;
	this->m_angle = 60.0;
	fill_v(this->m_v);
}
Hexagon::Hexagon(const Hexagon& hg)
{
	this->m_n = hg.m_n;
	this->m_len = hg.m_len;
	this->m_center = hg.m_center;
	this->m_angle = hg.m_angle;
	this->m_v = hg.m_v;
}
void Hexagon::fill_v(std::vector<Point>& v)
{
	for (int m = 1; m <= this->m_n; m++)
	{
		double angle = (this->m_angle * (m - 1)) * PI / 180;
		int x = this->m_center.x + cos(angle) * this->m_len;
		int y = this->m_center.y - sin(angle) * this->m_len;
		v.push_back(Point(x, y));
	}
}
