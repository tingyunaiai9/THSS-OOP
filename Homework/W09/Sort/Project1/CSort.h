#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#include "CInt.h"

class CSort
{
public:
    vector<CInt> m_vec;
    set<CInt> m_set;

public:
    CSort();
    void mb_getNum();
    void mb_sort();
};
