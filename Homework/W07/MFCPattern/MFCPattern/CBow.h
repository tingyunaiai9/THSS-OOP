#pragma once

#include "CPoint2D.h"

class CBow
{
public:
	CPoint2D m_centerPoint;
	double m_r;
public:
	CBow(double x = 0.0, double y = 0.0, double r = 5.0);
	CBow(const CPoint2D& centerPoint, double r = 5.0);
	CBow(const CBow& s);
};

