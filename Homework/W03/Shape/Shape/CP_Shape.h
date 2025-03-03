#pragma once

class CP_Shape
{
public:
	CP_Shape();

public:
	virtual void mb_hintInfo() {};
	virtual void mb_resultInfo() {};

protected:
	virtual void mb_calculate(double side) {};

public:
	static int s_shape_count;
	static double s_total_perimeter;
	static double s_total_area;

protected:
	double m_side;
	double m_perimeter;
	double m_area;
};

// 正三角形
class CP_RegularTriangle :public CP_Shape
{
public:
	virtual void mb_hintInfo();
	virtual void mb_resultInfo();

protected:
	virtual void mb_calculate(double side);
};

// 正方形
class CP_Square :public CP_Shape
{
public:
	virtual void mb_hintInfo();
	virtual void mb_resultInfo();

protected:
	virtual void mb_calculate(double side);
};

// 正五边形
class CP_RegularPentagon :public CP_Shape
{
public:
	virtual void mb_hintInfo();
	virtual void mb_resultInfo();

protected:
	virtual void mb_calculate(double side);
};

// 正六边形
class CP_RegularHexagon :public CP_Shape
{
public:
	virtual void mb_hintInfo();
	virtual void mb_resultInfo();

protected:
	virtual void mb_calculate(double side);
};

// 圆
class CP_Circle :public CP_Shape
{
public:
	virtual void mb_hintInfo();
	virtual void mb_resultInfo();

protected:
	virtual void mb_calculate(double side);
};