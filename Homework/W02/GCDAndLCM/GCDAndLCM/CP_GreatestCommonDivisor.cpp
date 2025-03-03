#include "pch.h"

#include "CP_GreatestCommonDivisor.h"

CP_GreatestCommonDivisor::CP_GreatestCommonDivisor(long long a, long long b) : m_a(a), m_b(b)
{

}

CP_GreatestCommonDivisor::~CP_GreatestCommonDivisor()
{

}

long long CP_GreatestCommonDivisor::mb_getGCD() // 辗转相除法求gcd
{
	long long a = m_a > m_b ? m_a : m_b; // a为m_a,m_b中较大的一个
	long long b = m_a > m_b ? m_b : m_a; // b为m_a,m_b中较小的一个
	long long r = a % b;

	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	m_GCD = b; // 余数为0时，b即为所求
	return m_GCD;
}

bool CP_GreatestCommonDivisor::mb_isGCD()
{
	if ((m_a % m_GCD != 0) || (m_b % m_GCD != 0)) // GCD不是两数的因数时
		return false;

	for (int i = 2; ((i * m_GCD <= m_a) && (i * m_GCD <= m_b)); i++) // 判断GCD的倍数是否是两数的公约数
	{
		if ((m_a % (i * m_GCD) == 0) && (m_b % (i * m_GCD) == 0))
			return false;
	}

	return true;
}