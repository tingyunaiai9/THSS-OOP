#include "pch.h"
#include "CBow.h"

CBow::CBow(double x, double y, double r)
	: m_centerPoint(x, y), m_r(r)
{

}

CBow::CBow(const CPoint2D& centerPoint, double r)
	: m_centerPoint(centerPoint), m_r(r)
{

}

CBow::CBow(const CBow& s)
	: m_centerPoint(s.m_centerPoint), m_r(s.m_r)
{

}