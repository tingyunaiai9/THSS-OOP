#include <iostream>

#include "PrintBinary.h"

void gb_printBinary(long long num)
{
	for (int i = 63; i >= 0; i--)
	{
		std::cout << ((num >> i) & 1);
		if(i % 8 == 0)
			std::cout << " ";
	}
}