#include "pch.h"
#include "CDrawPattern.h"

void gb_drawCuboid(CDC& d, const CCuboid& p, int penStyle,
    COLORREF rgb1, COLORREF rgb2)
{
    CPen pen(penStyle, 5, rgb1);
    CPen* oldPen = d.SelectObject(&pen);
    CBrush brush(rgb2);
    CBrush* oldBrush = d.SelectObject(&brush);

    for (int i = 0; i < p.m_thickness; i += 4)
    {
        d.Rectangle((int)(p.m_point1.m_x + i + 0.5), (int)(p.m_point1.m_y + i + 0.5),
            (int)(p.m_point2.m_x + i + 0.5), (int)(p.m_point2.m_y + i + 0.5));
    }

    d.SelectObject(oldPen);
    d.SelectObject(oldBrush);
}

void gb_drawParallelogram(CDC& d, const CParallelogram& p, int penStyle,
    COLORREF rgb)
{
    CPen pen(penStyle, 1, rgb);
    CPen* oldPen = d.SelectObject(&pen);

    for (int i = 0; i < p.m_point3.m_x - p.m_point1.m_x; i++)
    {
        d.MoveTo((int)(p.m_point1.m_x + i + 0.5), (int)(p.m_point1.m_y + i * (p.m_point3.m_y - p.m_point1.m_y) / (p.m_point3.m_x - p.m_point1.m_x)));
        d.LineTo((int)(p.m_point2.m_x + i + 0.5), (int)(p.m_point2.m_y + i * (p.m_point3.m_y - p.m_point1.m_y) / (p.m_point3.m_x - p.m_point1.m_x)));
    }

    d.SelectObject(oldPen);
}

extern void gb_drawBow(CDC& d, const CBow& p, int penStyle,
    COLORREF rgb)
{
    CPen pen(penStyle, 1, rgb);
    CPen* oldPen = d.SelectObject(&pen);

    int x1, x2, y1, y2;
    float pi, a, e;
    pi = 3.1415926f;
    for (a = 0; a <= 2 * pi; a += pi / 360)
    {
        e = p.m_r * (1 + 0.25 * sin(4 * a)) * 0.25;
        e = e * (1 + sin(8 * a));
        x1 = int(p.m_centerPoint.m_x + e * cos(a));
        x2 = int(p.m_centerPoint.m_x + e * cos(a + pi / 8));
        y1 = int(p.m_centerPoint.m_y + e * sin(a));
        y2 = int(p.m_centerPoint.m_y + e * sin(a + pi / 8));
        d.MoveTo(x1, y1);
        d.LineTo(x2, y2);
    }

    for (a = 0; a <= 2 * pi; a += pi / 360)
    {
        e = p.m_r * (1 + 0.25 * sin(4 * a)) * 0.15;
        e = e * (1 + sin(8 * a));
        x1 = int(p.m_centerPoint.m_x + e * cos(a));
        x2 = int(p.m_centerPoint.m_x + e * cos(a + pi / 8));
        y1 = int(p.m_centerPoint.m_y + e * sin(a));
        y2 = int(p.m_centerPoint.m_y + e * sin(a + pi / 8));
        d.MoveTo(x1, y1);
        d.LineTo(x2, y2);
    }

    d.SelectObject(oldPen);
}

void gb_drawGift(CDC& d, int penStyle,
    const CPoint2D point1, const CPoint2D point2, double thickness,
    int colorStyle)
{
    CCuboid cuboid(point1, point2, thickness);

    CPoint2D pointp11(point1.m_x, (point1.m_y + point2.m_y) / 2 - 15);
    CPoint2D pointp12(point1.m_x, (point1.m_y + point2.m_y) / 2 + 15);
    CPoint2D pointp13(point1.m_x + thickness, (point1.m_y + point2.m_y) / 2 - 15 + thickness);
    CParallelogram parallelogram1(pointp11, pointp12, pointp13);

    CPoint2D pointp21(point1.m_x + thickness / 2 - 7, point1.m_y + thickness / 2 - 7);
    CPoint2D pointp22(point1.m_x + thickness / 2 - 7, point2.m_y + thickness / 2 - 7);
    CPoint2D pointp23(point1.m_x + thickness / 2 + 7, point1.m_y + thickness / 2 + 7);
    CParallelogram parallelogram2(pointp21, pointp22, pointp23);

    CPoint2D pointp33(point2.m_x + thickness / 2 - 7, point1.m_y + thickness / 2 - 7);
    CParallelogram parallelogram3(pointp21, pointp23, pointp33);

    CPoint2D pointp41((point1.m_x + point2.m_x) / 2 - 15, point1.m_y);
    CPoint2D pointp42((point1.m_x + point2.m_x) / 2 +thickness - 15, point1.m_y+thickness);
    CPoint2D pointp43((point1.m_x + point2.m_x) / 2 + 15, point1.m_y);
    CParallelogram parallelogram4(pointp41, pointp42, pointp43);

    CPoint2D centerPoint((point1.m_x + point2.m_x) / 2 + thickness, (point1.m_y + point2.m_y) / 2 + thickness);
    CBow bow(centerPoint, (point1.m_x + point2.m_x)*0.8);

    colorStyle %= 4;

    if (colorStyle == 0)
    {
        gb_drawCuboid(d, cuboid, penStyle, RGB(124, 171, 177), RGB(147, 213, 220));
        gb_drawParallelogram(d, parallelogram1, penStyle, RGB(16, 174, 94));
        gb_drawParallelogram(d, parallelogram2, penStyle, RGB(16, 174, 94));
        gb_drawParallelogram(d, parallelogram3, penStyle, RGB(16, 174, 94));
        gb_drawParallelogram(d, parallelogram4, penStyle, RGB(16, 174, 94));

        CPen pen(penStyle, 1, RGB(16, 174, 94));
        CPen* oldPen = d.SelectObject(&pen);
        CBrush brush(RGB(16, 174, 94));
        CBrush* oldBrush = d.SelectObject(&brush);
        d.Rectangle(point1.m_x + thickness, (point1.m_y + point2.m_y) / 2 - 15 + thickness,
            point2.m_x + thickness, (point1.m_y + point2.m_y) / 2 + 15 + thickness);
        d.Rectangle((point1.m_x + point2.m_x) / 2 + thickness - 15, point1.m_y + thickness,
            (point1.m_x + point2.m_x) / 2 + thickness + 15, point2.m_y + thickness);
        d.SelectObject(oldPen);
        d.SelectObject(oldBrush);

        gb_drawBow(d, bow, penStyle, RGB(23, 129, 181));
    }
    else if (colorStyle == 1)
    {
        gb_drawCuboid(d, cuboid, penStyle, RGB(19, 17, 36), RGB(48, 47, 75));
        gb_drawParallelogram(d, parallelogram1, penStyle, RGB(116, 117, 155));
        gb_drawParallelogram(d, parallelogram2, penStyle, RGB(116, 117, 155));
        gb_drawParallelogram(d, parallelogram3, penStyle, RGB(116, 117, 155));
        gb_drawParallelogram(d, parallelogram4, penStyle, RGB(116, 117, 155));

        CPen pen(penStyle, 1, RGB(116, 117, 155));
        CPen* oldPen = d.SelectObject(&pen);
        CBrush brush(RGB(116, 117, 155));
        CBrush* oldBrush = d.SelectObject(&brush);
        d.Rectangle(point1.m_x + thickness, (point1.m_y + point2.m_y) / 2 - 15 + thickness,
            point2.m_x + thickness, (point1.m_y + point2.m_y) / 2 + 15 + thickness);
        d.Rectangle((point1.m_x + point2.m_x) / 2 + thickness - 15, point1.m_y + thickness,
            (point1.m_x + point2.m_x) / 2 + thickness + 15, point2.m_y + thickness);
        d.SelectObject(oldPen);
        d.SelectObject(oldBrush);

        gb_drawBow(d, bow, penStyle, RGB(204, 204, 214));
    }
    else if (colorStyle == 2)
    {
        gb_drawCuboid(d, cuboid, penStyle, RGB(93, 101, 95), RGB(110, 139, 116));
        gb_drawParallelogram(d, parallelogram1, penStyle, RGB(198, 223, 200));
        gb_drawParallelogram(d, parallelogram2, penStyle, RGB(198, 223, 200));
        gb_drawParallelogram(d, parallelogram3, penStyle, RGB(198, 223, 200));
        gb_drawParallelogram(d, parallelogram4, penStyle, RGB(198, 223, 200));

        CPen pen(penStyle, 1, RGB(198, 223, 200));
        CPen* oldPen = d.SelectObject(&pen);
        CBrush brush(RGB(198, 223, 200));
        CBrush* oldBrush = d.SelectObject(&brush);
        d.Rectangle(point1.m_x + thickness, (point1.m_y + point2.m_y) / 2 - 15 + thickness,
            point2.m_x + thickness, (point1.m_y + point2.m_y) / 2 + 15 + thickness);
        d.Rectangle((point1.m_x + point2.m_x) / 2 + thickness - 15, point1.m_y + thickness,
            (point1.m_x + point2.m_x) / 2 + thickness + 15, point2.m_y + thickness);
        d.SelectObject(oldPen);
        d.SelectObject(oldBrush);

        gb_drawBow(d, bow, penStyle, RGB(185, 222, 201));
    }
    else
    {
        gb_drawCuboid(d, cuboid, penStyle, RGB(239, 175, 173), RGB(242, 202, 201));
        gb_drawParallelogram(d, parallelogram1, penStyle, RGB(249, 223, 205));
        gb_drawParallelogram(d, parallelogram2, penStyle, RGB(249, 223, 205));
        gb_drawParallelogram(d, parallelogram3, penStyle, RGB(249, 223, 205));
        gb_drawParallelogram(d, parallelogram4, penStyle, RGB(249, 223, 205));

        CPen pen(penStyle, 1, RGB(249, 223, 205));
        CPen* oldPen = d.SelectObject(&pen);
        CBrush brush(RGB(249, 223, 205));
        CBrush* oldBrush = d.SelectObject(&brush);
        d.Rectangle(point1.m_x + thickness, (point1.m_y + point2.m_y) / 2 - 15 + thickness,
            point2.m_x + thickness, (point1.m_y + point2.m_y) / 2 + 15 + thickness);
        d.Rectangle((point1.m_x + point2.m_x) / 2 + thickness - 15, point1.m_y + thickness,
            (point1.m_x + point2.m_x) / 2 + thickness + 15, point2.m_y + thickness);
        d.SelectObject(oldPen);
        d.SelectObject(oldBrush);

        gb_drawBow(d, bow, penStyle, RGB(249, 215, 112));
    }
}
