#include <iostream>
#include <Windows.h>
#include <stdio.h>

#include "CSort.h"
#include "CMyVector.h"

void gb_test()
{
    CSort sort_test;
    sort_test.mb_getNum();
    sort_test.mb_sort();
}

void gb_testMyVector()
{
    DWORD dwStart;
    DWORD dwEnd;

    dwStart = GetTickCount();
    CMyVector<int> vec1;
    for (int i = 0; i < 10000000; i++)
    {
        vec1.push_back(i);
    }
    dwEnd = GetTickCount();
    cout << "CMyVector push_back time: " << dwEnd - dwStart << "ms" << endl;

    dwStart = GetTickCount();
    vector<int> vec2;
    for (int i = 0; i < 10000000; i++)
    {
        vec2.push_back(i);
    }
    dwEnd = GetTickCount();
    cout << "vector push_back time: " << dwEnd - dwStart << "ms" << endl;
    cout << endl;

    dwStart = GetTickCount();
    for (int i = 0; i < 10000000; i++)
    {
        vec1.pop_back();
    }
    dwEnd = GetTickCount();
    cout << "CMyVector pop_back time: " << dwEnd - dwStart << "ms" << endl;

    dwStart = GetTickCount();
    for (int i = 0; i < 10000000; i++)
    {
        vec2.pop_back();
    }
    dwEnd = GetTickCount();
    cout << "vector pop_back time: " << dwEnd - dwStart << "ms" << endl;
    cout << endl;

    dwStart = GetTickCount();
    CMyVector<int> vec3;
    for (int i = 0; i < 10000; i++)
    {
        vec3.insert(0, i);
    }
    dwEnd = GetTickCount();
    cout << "CMyVector insert time: " << dwEnd - dwStart << "ms" << endl;

    dwStart = GetTickCount();
    vector<int> vec4;
    for (int i = 0; i < 10000; i++)
    {
        vec4.insert(vec4.begin(), i);
    }
    dwEnd = GetTickCount();
    cout << "vector insert time: " << dwEnd - dwStart << "ms" << endl;
    cout << endl;

    dwStart = GetTickCount();
    for(int i = 0; i < 10000; i++)
    {
        vec3.erase(0);
    }
    dwEnd = GetTickCount();
    cout << "CMyVector erase time: " << dwEnd - dwStart << "ms" << endl;

    dwStart = GetTickCount();
    for (int i = 0; i < 10000; i++)
    {
        vec4.erase(vec4.begin());
    }
    dwEnd = GetTickCount();
    cout << "vector erase time: " << dwEnd - dwStart << "ms" << endl;
    cout << endl;
}

int main()
{
    gb_test();
    return 0;
}
