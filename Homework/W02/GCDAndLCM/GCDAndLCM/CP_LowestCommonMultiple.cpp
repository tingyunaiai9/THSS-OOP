#include "pch.h"

#include "CP_LowestCommonMultiple.h"

CP_LowestCommonMultiple::CP_LowestCommonMultiple(long long a, long long b) : m_a(a), m_b(b)
{

}

CP_LowestCommonMultiple::~CP_LowestCommonMultiple()
{

}

long long CP_LowestCommonMultiple::mb_getLCM(long long GCD)
{
	m_LCM = m_a * (m_b / GCD); // 最小公倍数 = 两数乘积/最大公约数

	return m_LCM;
}

bool CP_LowestCommonMultiple::mb_isLCM()
{
	if ((m_LCM % m_a != 0) || (m_LCM % m_b != 0)) // 不是公倍数
		return false;

	long long tmp = m_a > m_b ? m_a : m_b; // tmp为m_a，m_b中较大数
	for (int i = 1; i * tmp < m_LCM; i++)
	{
		if (((i * tmp) % m_a == 0) && ((i * tmp) % m_b == 0)) // 存在比m_LCM更小的公倍数
			return false;
	}

	return true;
}