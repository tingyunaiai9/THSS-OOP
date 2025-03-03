#pragma once

#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline void SAFE_DELETE(T*& t)
{
	if (t)
	{
		delete t;
	}
	t = NULL;
}
