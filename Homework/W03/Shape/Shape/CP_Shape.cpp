#include "pch.h"

#include "CP_Shape.h"

#define PI 3.1415926

int CP_Shape::s_shape_count = 0;
double CP_Shape::s_total_perimeter = 0;
double CP_Shape::s_total_area = 0;

CP_Shape::CP_Shape()
{
	s_shape_count++;
}


void CP_RegularTriangle::mb_hintInfo()
{
	double side = 0;
	cout << "请输入正三角形的边长：";
	cin >> side;

	mb_calculate(side);
}

void CP_RegularTriangle::mb_resultInfo()
{
	cout << "该正三角形的周长：" << m_perimeter << endl;
	cout << "该正三角形的面积：" << m_area << endl;
	cout << endl;
}

void CP_RegularTriangle::mb_calculate(double side)
{
	m_side = side;
	m_perimeter = 3 * side;
	m_area = (pow(3, 0.5) / 4) * pow(side, 2);

	s_total_perimeter += m_perimeter;
	s_total_area += m_area;
}


void CP_Square::mb_hintInfo()
{
	double side = 0;
	cout << "请输入正方形的边长：";
	cin >> side;

	mb_calculate(side);
}

void CP_Square::mb_resultInfo()
{
	cout << "该正方形的周长：" << m_perimeter << endl;
	cout << "该正方形的面积：" << m_area << endl;
	cout << endl;
}

void CP_Square::mb_calculate(double side)
{
	m_side = side;
	m_perimeter = 4 * side;
	m_area = pow(side, 2);

	s_total_perimeter += m_perimeter;
	s_total_area += m_area;
}


void CP_RegularPentagon::mb_hintInfo()
{
	double side = 0;
	cout << "请输入正五边形的边长：";
	cin >> side;

	mb_calculate(side);
}

void CP_RegularPentagon::mb_resultInfo()
{
	cout << "该正五边形的周长：" << m_perimeter << endl;
	cout << "该正五边形的面积：" << m_area << endl;
	cout << endl;
}

void CP_RegularPentagon::mb_calculate(double side)
{
	m_side = side;
	m_perimeter = 5 * side;
	m_area = 5 * pow(side,2) / (4 * tan(36*PI/180));

	s_total_perimeter += m_perimeter;
	s_total_area += m_area;
}


void CP_RegularHexagon::mb_hintInfo()
{
	double side = 0;
	cout << "请输入正六边形的边长：";
	cin >> side;

	mb_calculate(side);
}

void CP_RegularHexagon::mb_resultInfo()
{
	cout << "该正六边形的周长：" << m_perimeter << endl;
	cout << "该正六边形的面积：" << m_area << endl;
	cout << endl;
}

void CP_RegularHexagon::mb_calculate(double side)
{
	m_side = side;
	m_perimeter = 6 * side;
	m_area = 6 * (pow(3, 0.5) / 4) * pow(side, 2);

	s_total_perimeter += m_perimeter;
	s_total_area += m_area;
}


void CP_Circle::mb_hintInfo()
{
	double side = 0;
	cout << "请输入圆的半径：";
	cin >> side;

	mb_calculate(side);
}

void CP_Circle::mb_resultInfo()
{
	cout << "该圆的周长：" << m_perimeter << endl;
	cout << "该圆的面积：" << m_area << endl;
	cout << endl;
}

void CP_Circle::mb_calculate(double side)
{
	m_side = side;
	m_perimeter = 2 * PI * side;
	m_area = PI * pow(side, 2);

	s_total_perimeter += m_perimeter;
	s_total_area += m_area;
}