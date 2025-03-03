#include <iostream>
using namespace std;

#include "CIntByStringTest.h"

void CIntByStringTest::mb_run()
{
    char buffer[100];
    cout << "Please input a whole number: ";
    buffer[0] = 0;
    cin.getline(buffer, 100);
    m_input1 = buffer;
    cout << "Please input another whole number: ";
    cin.getline(buffer, 100);
    m_input2 = buffer;

    m_int1.mb_setValue(m_input1);
    m_int2.mb_setValue(m_input2);

    m_int1.mb_show("a: ");
    m_int2.mb_show("    b: ");
    cout << endl;

    (m_int1 + m_int2).mb_show("a + b = ");
    cout << endl;
    (m_int1 - m_int2).mb_show("a - b = ");
}
