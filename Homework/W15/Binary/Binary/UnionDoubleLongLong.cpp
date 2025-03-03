#include <iostream>
#include <limits>

#include "UnionDoubleLongLong.h"
#include "PrintBinary.h"

using namespace std;

void gb_showDoubleLongLongMemory(const U_DoubleLongLong& u)
{
	cout << u.m_double << " :" << endl;
	gb_printBinary(u.m_longLong);
	cout << endl << endl;
}

void gb_testDoubleLongLong()
{
	double num;
	cout << "Enter a double number: ";
	cin >> num;

	U_DoubleLongLong u(num);
	gb_showDoubleLongLongMemory(u);

	//while (1)
	//{
	//	cout << "Enter a double number: ";
	//	cin >> num;

	//	U_DoubleLongLong u(num);
	//	gb_showDoubleLongLongMemory(u);
	//}

	// NaN
	//U_DoubleLongLong u(0.0);
	//u.m_double = 0.0 / u.m_double;
	//gb_showDoubleLongLongMemory(u);

	// Infinity
	//double num = numeric_limits<double>::infinity();
	//U_DoubleLongLong u(num);
	//gb_showDoubleLongLongMemory(u);

	//double num = -numeric_limits<double>::infinity();
	//U_DoubleLongLong u(num);
	//gb_showDoubleLongLongMemory(u);
}	
