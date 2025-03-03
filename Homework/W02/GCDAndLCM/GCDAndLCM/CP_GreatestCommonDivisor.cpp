#include "pch.h"

#include "CP_GreatestCommonDivisor.h"

CP_GreatestCommonDivisor::CP_GreatestCommonDivisor(long long a, long long b) : m_a(a), m_b(b)
{

}

CP_GreatestCommonDivisor::~CP_GreatestCommonDivisor()
{

}

long long CP_GreatestCommonDivisor::mb_getGCD() // շת�������gcd
{
	long long a = m_a > m_b ? m_a : m_b; // aΪm_a,m_b�нϴ��һ��
	long long b = m_a > m_b ? m_b : m_a; // bΪm_a,m_b�н�С��һ��
	long long r = a % b;

	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	m_GCD = b; // ����Ϊ0ʱ��b��Ϊ����
	return m_GCD;
}

bool CP_GreatestCommonDivisor::mb_isGCD()
{
	if ((m_a % m_GCD != 0) || (m_b % m_GCD != 0)) // GCD��������������ʱ
		return false;

	for (int i = 2; ((i * m_GCD <= m_a) && (i * m_GCD <= m_b)); i++) // �ж�GCD�ı����Ƿ��������Ĺ�Լ��
	{
		if ((m_a % (i * m_GCD) == 0) && (m_b % (i * m_GCD) == 0))
			return false;
	}

	return true;
}