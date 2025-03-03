#include "pch.h"
#include "CParallelogram.h"

CParallelogram::CParallelogram
	(double x1, double y1, double x2, double y2, double x3, double y3)
	: m_point1(x1, y1), m_point2(x2, y2), m_point3(x3, y3)
{

}

CParallelogram::CParallelogram
	(const CPoint2D& point1, const CPoint2D& point2, const CPoint2D& point3)
	: m_point1(point1), m_point2(point2), m_point3(point3)
{

}

CParallelogram::CParallelogram(const CParallelogram& s)
	: m_point1(s.m_point1), m_point2(s.m_point2), m_point3(s.m_point3)
{

}