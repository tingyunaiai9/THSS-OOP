#pragma once
class CPoint2D
{
public:
    double m_x, m_y;
public:
    CPoint2D(double newx = 0.0, double newy = 0.0);
    CPoint2D(const CPoint2D& p);
};

