#include "pch.h"
#include "CPoint2D.h"

CPoint2D::CPoint2D(double newx, double newy)
    : m_x(newx), m_y(newy)
{
}

CPoint2D::CPoint2D(const CPoint2D& p)
    : m_x(p.m_x), m_y(p.m_y)
{
}