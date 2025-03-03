#pragma once

#include "CPoint2D.h"
#include "CCuboid.h"
#include "CParallelogram.h"
#include "CBow.h"

class CDrawPattern
{
};

extern void gb_drawCuboid(CDC& d, const CCuboid& p, int penStyle = PS_SOLID,
	COLORREF rgb1 = RGB(124,171,177), COLORREF rgb2 = RGB(147, 213, 220)); // pen:rgb1 brush:rgb2

extern void gb_drawParallelogram(CDC& d, const CParallelogram& p, int penStyle = PS_SOLID,
	COLORREF rgb = RGB(16, 174, 94));

extern void gb_drawBow(CDC& d, const CBow& p, int penStyle = PS_SOLID,
	COLORREF rgb = RGB(23, 129, 181));

extern void gb_drawGift(CDC& d, int penStyle,
	const CPoint2D point1, const CPoint2D point2, double thickness,
	int colorStyle = 0);