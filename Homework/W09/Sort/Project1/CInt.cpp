#include "CInt.h"

CInt::CInt(int num) : m_num(num)
{

}

CInt::CInt(const CInt& other) : m_num(other.m_num)
{

}

int CInt::mb_getNum() const
{
    return m_num;
}

CInt CInt::operator - () const
{
    return CInt(-m_num);
}

CInt operator + (const CInt& a, const CInt& b)
{
    return CInt(a.m_num + b.m_num);
}

CInt operator - (const CInt& a, const CInt& b)
{
    return CInt(a.m_num - b.m_num);
}

CInt operator * (const CInt& a, const CInt& b)
{
    return CInt(a.m_num * b.m_num);
}

CInt operator / (const CInt& a, const CInt& b)
{
    return CInt(a.m_num / b.m_num);
}

bool operator < (const CInt& a, const CInt& b)
{
    return a.m_num < b.m_num;
}

bool operator > (const CInt& a, const CInt& b)
{
    return a.m_num > b.m_num;
}

bool operator == (const CInt& a, const CInt& b)
{
    return a.m_num == b.m_num;
}
