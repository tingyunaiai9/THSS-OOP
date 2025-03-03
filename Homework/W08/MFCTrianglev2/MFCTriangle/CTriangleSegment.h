#pragma once

class CPoint2D
{
public:
    double m_x, m_y;
public:
    CPoint2D(double newx = 0.0, double newy = 0.0);
    CPoint2D(const CPoint2D& p);
};

class CTriangleSegment
{
public:
    CPoint2D m_point1, m_point2, m_point3;
public:
    CTriangleSegment(double x1 = 0.0, double y1 = 0.0, 
        double x2 = 1.0, double y2 = 0.0, double x3 = 1.0, double y3 = 1.0);
    CTriangleSegment(const CPoint2D& p1, const CPoint2D& p2, const CPoint2D& p3);
    CTriangleSegment(const CTriangleSegment& s);
    virtual~CTriangleSegment() { };
};

