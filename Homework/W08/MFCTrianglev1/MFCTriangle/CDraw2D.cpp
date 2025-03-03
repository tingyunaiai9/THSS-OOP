#include "pch.h"
#include "CDraw2D.h"

void gb_draw2D(CDC& d, const CTriangleSegment& p,
    int style, int r, int g, int b)
{
    CPen pen(style, 1, RGB(r, g, b));
    CPen* oldPen = d.SelectObject(&pen);
    d.MoveTo((int)(p.m_point1.m_x + 0.5),
        (int)(p.m_point1.m_y + 0.5));
    d.LineTo((int)(p.m_point2.m_x + 0.5),
        (int)(p.m_point2.m_y + 0.5));
    d.LineTo((int)(p.m_point3.m_x + 0.5),
        (int)(p.m_point3.m_y + 0.5));
    d.LineTo((int)(p.m_point1.m_x + 0.5),
        (int)(p.m_point1.m_y + 0.5));
    d.SelectObject(oldPen); // 恢复原有画笔
} // 函数gb_draw2D定义结束

