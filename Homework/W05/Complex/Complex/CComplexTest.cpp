#include "pch.h"

#include "CComplex.h"
#include "CComplexTest.h"

void CComplexTest::mb_CComplexTest1()
{
    CComplex c1, c2;
    cout << "Please input two complex numbers to test + - * / :" << endl;
    cin >> c1 >> c2;

    c1.mb_show("c1 = ");
    c2.mb_show("c2 = ");
    cout << endl;

    CComplex c3 = c1 + c2;
    c3.mb_show("c1 + c2 = ");
    CComplex c4 = c1 - c2;
    c4.mb_show("c1 - c2 = ");
    CComplex c5 = c1 * c2;
    c5.mb_show("c1 * c2 = ");
    CComplex c6 = c1 / c2;
    c6.mb_show("c1 / c2 = ");
    cout << endl;
}

void CComplexTest::mb_CComplexTest1Plus()
{
    CComplex c1;
    float f1;
    cout << "Please input a complex number to test + - * / :" << endl;
    cin >> c1;
    cout << "Please input a float number to test + - * / :" << endl;
    cin >> f1;

    c1.mb_show("c1 = ");
    cout << "f1 = " << f1 << endl;
    cout << endl;

    cout << "c1 + " << f1 << " = " << c1 + f1 << endl;
    cout << f1 << " + c1 = " << f1 + c1 << endl;
    cout << "c1 - " << f1 << " = " << c1 - f1 << endl;
    cout << f1 << " - c1 = " << f1 - c1 << endl;
    cout << "c1 * " << f1 << " = " << c1 * f1 << endl;
    cout << f1 << " * c1 = " << f1 * c1 << endl;
    cout << "c1 / " << f1 << " = " << c1 / f1 << endl;
    cout << f1 << " / c1 = " << f1 / c1 << endl;
}

void CComplexTest::mb_CComplexTest2()
{
    CComplex c1, c2;
    cout << "Please input two complex numbers to test == != :" << endl;
    cin >> c1 >> c2;

    c1.mb_show("c1 = ");
    c2.mb_show("c2 = ");
    cout << endl;

    cout << "test ==: ";
    if (c1 == c2)
        cout << "c1 == c2" << endl;
    else
        cout << "c1 != c2" << endl;
    cout << "test !=: ";
    if (c1 != c2)
        cout << "c1 != c2" << endl;
    else
        cout << "c1 == c2" << endl;
    cout << endl;
}

void CComplexTest::mb_CComplexTest3()
{
    CComplex c1;
    cout << "Please input a complex number to test ++ -- :" << endl;
    cin >> c1;

    CComplex c1_record = c1;
    c1_record.mb_show("c1 = ");
    cout << endl;

    CComplex c2 = c1++;
    cout << "c1 = " << c1_record << "  c1++ = " << c2 << "  c1 = " << c1 << endl;
    c1 = c1_record;
    c2 = ++c1;
    cout << "c1 = " << c1_record << "  ++c1 = " << c2 << "  c1 = " << c1 << endl;
    c1 = c1_record;
    c2 = c1--;
    cout << "c1 = " << c1_record << "  c1-- = " << c2 << "  c1 = " << c1 << endl;
    c1 = c1_record;
    c2 = --c1;
    cout << "c1 = " << c1_record << "  --c1 = " << c2 << "  c1 = " << c1 << endl;
    cout << endl;
}

void CComplexTest::mb_CComplexTest4()
{
    CComplex c1, c2;
    cout << "Please input two complex numbers to test += -= *= /= :" << endl;
    cin >> c1 >> c2;

    c1.mb_show("c1 = ");
    c2.mb_show("c2 = ");
    cout << endl;

    CComplex c3 = c1;
    c3 += c2;
    c3.mb_show("c1 += c2 = ");
    CComplex c4 = c1;
    c4 -= c2;
    c4.mb_show("c1 -= c2 = ");
    CComplex c5 = c1;
    c5 *= c2;
    c5.mb_show("c1 *= c2 = ");
    CComplex c6 = c1;
    c6 /= c2;
    c6.mb_show("c1 /= c2 = ");
    cout << endl;
}

void CComplexTest::mb_CComplexTest4Plus()
{
    CComplex c1;
    float f1;
    cout << "Please input a complex number to test += -= *= /= :" << endl;
    cin >> c1;
    cout << "Please input a float number to test += -= *= /= :" << endl;
    cin >> f1;

    c1.mb_show("c1 = ");
    cout << "f1 = " << f1 << endl;
    cout << endl;

    CComplex c2 = c1;
    c2 += f1;
    cout << "c1 += " << f1 << " = " << c2 << endl;
    CComplex c3 = c1;
    c3 -= f1;
    cout << "c1 -= " << f1 << " = " << c3 << endl;
    CComplex c4 = c1;
    c4 *= f1;
    cout << "c1 *= " << f1 << " = " << c4 << endl;
    CComplex c5 = c1;
    c5 /= f1;
    cout << "c1 /= " << f1 << " = " << c5 << endl;
    cout << endl;
}
