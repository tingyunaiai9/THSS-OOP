#pragma once

#include <string>

class CIntByString
{
private:
    int m_flag;    // 1: 普通正整数或0; -1: 普通负整数
    string m_data; //全部字符由'0'~'9'组成，而且不以'0'开头。m_data=""表示0。

public:
    CIntByString():
        m_flag(1) { }
    CIntByString(const string &data, int flag = 1);

    int mb_getFlag() const { return m_flag; }
    string mb_getData() const { return m_data; }
    void mb_getValue(int &flag, string &data) const;
    void mb_setValue(const string &data);
    void mb_setValue(int flag, const string &data);
    void mb_show(const char *s) const;

public:
    friend CIntByString operator+(const CIntByString &a, const CIntByString &b);
    friend CIntByString operator-(const CIntByString &a, const CIntByString &b);

public:
    friend bool isLower(const string &a, const string &b);

    friend string add(const string &a, const string &b);
    friend string sub(const string &a, const string &b);
};
