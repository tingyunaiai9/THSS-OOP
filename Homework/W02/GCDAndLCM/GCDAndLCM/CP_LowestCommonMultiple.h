#pragma once

class CP_LowestCommonMultiple
{
public:
	CP_LowestCommonMultiple(long long a, long long b);
	~CP_LowestCommonMultiple();

	long long mb_getLCM(long long GCD);
	bool mb_isLCM();

private:
	long long m_a;
	long long m_b;
	long long m_LCM;
};