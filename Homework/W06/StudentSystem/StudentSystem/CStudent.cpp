#include "pch.h"

#include "CStudent.h"

void gb_swapStudent(CStudent &a, CStudent &b)
{
    // CStudent t = a;
    // a = b;
    // b = t;
    CStudent tmp = move(a); // 移动构造函数
    a = move(b);
    b = move(tmp);
}

void CStudent::mb_setId(long long id)
{
    m_ID = id;
}

void CStudent::mb_setScore(int score)
{
    m_score = score;
}

long long CStudent::mb_getId() const
{
    return m_ID;
}

int CStudent::mb_getScore() const
{
    return m_score;
}
