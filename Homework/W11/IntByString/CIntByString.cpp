#include <iostream>
#include <algorithm>
using namespace std;

#include "CIntByString.h"

CIntByString::CIntByString(const string &data, int flag)
{
    mb_setValue(flag, data);
}

void CIntByString::mb_getValue(int &flag, string &data) const
{
    flag = m_flag;
    data = m_data;
}

void CIntByString::mb_setValue(const string &data)
{
    int i;
    int n = data.size();
    int state = 0; // 状态 0初始状态 1符号位状态 2非零状态 3输入0状态 4结束状态
    m_flag = 1;
    m_data = "";
    for(i=0; i<n; i++)
    {
        switch(state)
        {
        case 0:
            if(data[i] == '+')
                state = 1;
            else if(data[i] == '-')
            {
                state = 1;
                m_flag = -1;
            }
            else if(data[i] == '0')
                state = 3;
            else if (('1'<=data[i]) && (data[i]<='9'))
            {
                state = 2;
                m_data += data[i];
            }
            break;
        case 1:
            if(data[i] == '-')
                m_flag *= -1;
            else if (('1'<=data[i]) && (data[i]<='9'))
                {
                    state = 2;
                    m_data += data[i];
                }
            break;
        case 2:
            if (('0'<=data[i]) && (data[i]<='9'))
                m_data += data[i];
            break;
        case 3:
            if(('1'<=data[i]) && (data[i]<='9'))
            {
                state = 2;
                m_data += data[i];
            }
            break;
        }
    }
}

void CIntByString::mb_setValue(int flag, const string &data)
{
    mb_setValue(data);
    m_flag *= flag;
}

void CIntByString::mb_show(const char *s) const
{
    cout << s;
    if(m_data.size() <= 0)
    {
        cout << "0";
        return;
    }
    if(m_flag == -1)
        cout << "-";
    cout << m_data;
}

bool isLower(const string &a, const string &b)
{
    return (a.size() < b.size()) || ((a.size() == b.size()) && (a < b));
}

string add(const string &a, const string &b)
{
    string result;

    int array = 0; // 进位
    int len = max(a.size(), b.size());

    for(int i=0; i<len; i++)
    {
        if(i<a.size())
            array += a[a.size()-1-i] - '0';
        if(i<b.size())
            array += b[b.size()-1-i] - '0';

        result = to_string(array % 10) + result;
        array /= 10;
    }

    if(array > 0)
        result = to_string(array) + result;

    return std::move(result);
}

string sub(const string &a, const string &b) // a >= b
{
    string result;

    int borrow = 0; // 借位
    int len = a.size();

    for(int i=0; i<len; i++)
    {
        borrow += a[a.size()-1-i] - '0';
        if(i<b.size())
            borrow -= b[b.size()-1-i] - '0';

        if(borrow < 0)
        {
            result = to_string(borrow + 10) + result;
            borrow = -1;
        }
        else
        {
            result = to_string(borrow) + result;
            borrow = 0;
        }
    }

    if(result[0] == '0')
        result.erase(0, result.find_first_not_of('0')); // 删除"0"

    return std::move(result);
}

CIntByString operator+(const CIntByString &a, const CIntByString &b)
{
    CIntByString result;

    if(a.m_flag == b.m_flag)
    {
        result.m_flag = a.m_flag;
        result.m_data = add(a.m_data, b.m_data);
    }
    else
    {
        if(isLower(a.m_data, b.m_data))
        {
            result.m_flag = b.m_flag;
            result.m_data = sub(b.m_data, a.m_data);
        }
        else
        {
            result.m_flag = a.m_flag;
            result.m_data = sub(a.m_data, b.m_data);
        }
    }

    return result;
}

CIntByString operator-(const CIntByString &a, const CIntByString &b)
{
    CIntByString result;

    if(a.m_flag != b.m_flag)
    {
        result.m_flag = a.m_flag;
        result.m_data = add(a.m_data, b.m_data);
    }
    else
    {
        if(isLower(a.m_data, b.m_data))
        {
            result.m_flag = -b.m_flag;
            result.m_data = sub(b.m_data, a.m_data);
        }
        else
        {
            result.m_flag = a.m_flag;
            result.m_data = sub(a.m_data, b.m_data);
        }
    }

    return result;
}
