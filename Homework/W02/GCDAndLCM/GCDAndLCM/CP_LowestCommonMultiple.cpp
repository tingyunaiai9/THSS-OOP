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
	m_LCM = m_a * (m_b / GCD); // ��С������ = �����˻�/���Լ��

	return m_LCM;
}

bool CP_LowestCommonMultiple::mb_isLCM()
{
	if ((m_LCM % m_a != 0) || (m_LCM % m_b != 0)) // ���ǹ�����
		return false;

	long long tmp = m_a > m_b ? m_a : m_b; // tmpΪm_a��m_b�нϴ���
	for (int i = 1; i * tmp < m_LCM; i++)
	{
		if (((i * tmp) % m_a == 0) && ((i * tmp) % m_b == 0)) // ���ڱ�m_LCM��С�Ĺ�����
			return false;
	}

	return true;
}