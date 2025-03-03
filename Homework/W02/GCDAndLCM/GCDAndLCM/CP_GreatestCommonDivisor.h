#pragma once

class CP_GreatestCommonDivisor
{
public:
	CP_GreatestCommonDivisor(long long a, long long b);
	~CP_GreatestCommonDivisor();

	long long mb_getGCD();
	bool mb_isGCD();

private:
	long long m_a;
	long long m_b;
	long long m_GCD;
};