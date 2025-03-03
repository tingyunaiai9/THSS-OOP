#pragma once

#include "CPoint2D.h"

class CCuboid
{
public:
	CPoint2D m_point1, m_point2; // m_point1:left+top m_point2:right+bottom
	double m_thickness;

public:
	CCuboid(double x1 = 0.0, double y1 = 0.0,
		double x2 = 1.0, double y2 = 0.0, double thickness = 0.0);
	CCuboid(const CPoint2D& point1, const CPoint2D& point2, double thickness);
	CCuboid(const CCuboid& s);
};

