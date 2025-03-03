#pragma once
class CInt
{
public:
	CInt(int num);
	CInt(const CInt& other);

	int m_num;

public:
	int mb_getNum() const;

public:
	CInt operator - () const;

	friend CInt operator + (const CInt& a, const CInt& b);
	friend CInt operator - (const CInt& a, const CInt& b);
	friend CInt operator * (const CInt& a, const CInt& b);
	friend CInt operator / (const CInt& a, const CInt& b);

	friend bool operator < (const CInt& a, const CInt& b);
	friend bool operator > (const CInt& a, const CInt& b);
	friend bool operator == (const CInt& a, const CInt& b);
};
