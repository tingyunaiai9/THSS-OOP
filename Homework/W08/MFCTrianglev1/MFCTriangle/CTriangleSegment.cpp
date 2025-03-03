#include "pch.h"
#include "CTriangleSegment.h"

// ////////////////////////////////////////////////////////////////
// 实现类CPoint2D开始
CPoint2D::CPoint2D(double newx, double newy)
    : m_x(newx), m_y(newy)
{
} // 类CPoint2D的构造函数定义结束

CPoint2D::CPoint2D(const CPoint2D& p)
    : m_x(p.m_x), m_y(p.m_y)
{
} // 类CPoint2D的构造函数定义结束
// 实现类CPoint2D结束
// ////////////////////////////////////////////////////////////////


// ////////////////////////////////////////////////////////////////
// 实现类CTriangleSegment开始
CTriangleSegment::CTriangleSegment(
    double x1, double y1, double x2, double y2, double x3, double y3)
    : m_point1(x1, y1), m_point2(x2, y2), m_point3(x3, y3)
{
} // 类CTriangleSegment的构造函数定义结束

CTriangleSegment::CTriangleSegment(
    const CPoint2D& p1, const CPoint2D& p2, const CPoint2D& p3)
    : m_point1(p1), m_point2(p2), m_point3(p3)
{
} // 类CTriangleSegment的构造函数定义结束

CTriangleSegment::CTriangleSegment(const CTriangleSegment& s)
    : m_point1(s.m_point1), m_point2(s.m_point2), m_point3(s.m_point3)
{
} // 类CTriangleSegment的构造函数定义结束
// 实现类CTriangleSegment结束
// ////////////////////////////////////////////////////////////////
