#pragma once

union U_DoubleLongLong
{
	double m_double;
	long long m_longLong;

	U_DoubleLongLong(double d) : m_double(d) {}
	U_DoubleLongLong(long long i = 0) : m_longLong(i) {}
	U_DoubleLongLong(U_DoubleLongLong& u) : m_longLong(u.m_longLong) {}
	~U_DoubleLongLong() {}
};

extern void gb_showDoubleLongLongMemory(const U_DoubleLongLong& u);
extern void gb_testDoubleLongLong();
