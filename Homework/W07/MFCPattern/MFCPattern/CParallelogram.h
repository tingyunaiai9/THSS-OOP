#pragma once

#include "CPoint2D.h"

class CParallelogram
{
public:
	CPoint2D m_point1, m_point2, m_point3; // 1вСио 2вСоб 3срио
public:
	CParallelogram(double x1 = 0.0, double y1 = 0.0,
		double x2 = 1.0, double y2 = 1.0,
		double x3 = 1.0, double y3 = 0.0);
	CParallelogram(const CPoint2D& point1, const CPoint2D& point2, const CPoint2D& point3);
	CParallelogram(const CParallelogram& s);
};

