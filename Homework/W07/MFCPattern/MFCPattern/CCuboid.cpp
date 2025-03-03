#include "pch.h"
#include "CCuboid.h"

CCuboid::CCuboid(double x1, double y1, double x2, double y2, double thickness)
	: m_point1(x1, y1), m_point2(x2, y2), m_thickness(thickness)
{

}

CCuboid::CCuboid(const CPoint2D& point1, const CPoint2D& point2, double thickness)
	: m_point1(point1), m_point2(point2), m_thickness(thickness)
{

}

CCuboid::CCuboid(const CCuboid& s)
	: m_point1(s.m_point1), m_point2(s.m_point2), m_thickness(s.m_thickness)
{

}
