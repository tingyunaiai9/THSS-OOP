#include "pch.h"

#include "CCalendar.h"

CCalendar::CCalendar()
{
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);

    mb_setYear(now.tm_year + 1900);
    mb_setMonth(now.tm_mon + 1);
    mb_setDay(now.tm_mday);
}

void CCalendar::mb_addDate(long long n)
{
    // 将日期挪至 1 1 4713 BC 计算
    // n为从 1 1 4713 BC 经过的天数
    n += 2460370; // 29 2 2024 -> 1 1 4713 BC
    for (int i = 3; i < m_month; i++)
        n += mb_getDayOfMonth(2024, i);
    n += m_day;

    int year = -4712;
    int month = 1;
    int day = 1;

    // ————————计算year开始————————
    if (n < 1721424 + 577737) // 1582.10.4之前
    {
        year += (n / 1461) * 4; // 每4年都有闰年
        n %= 1461;
    }
    else // 1582.10.15及以后
    {
        n -= 1721424; // 公元后
        n += 10 - 12; // 补上缺失的10天，下面将前1582当作100平年来算，减去少算的12天

        year = 1 + (n / 146097) * 400;
        n %= 146097;

        if (n >= 109572) //最后一个100年，最后一年是闰年，满足每4年有闰年
        {
            year += 300;
            n -= 109572;
            year += (n / 1461) * 4;
            n %= 1461;
        }
        else //不是最后一个100年，末尾没有闰年
        {
            year += (n / 36524) * 100;
            n %= 36524;
            if (n >= 35064) //最后一个四年，无闰年
            {
                year += 96;
                n -= 35064;
            }
            else {
                year += (n / 1461) * 4;
                n %= 1461;
            }
        }
    }

    while (n >= 365)
    {
        if (mb_isLeapYear(year))
        {
            if (n >= 366)
            {
                year++;
                n -= 366;
            }
            else // n== 365
                break;
        }
        else
        {
            year++;
            n -= 365;
        }
    }
    // ————————计算year结束————————

    // 计算month
    for (int i = 1; n >= mb_getDayOfMonth(year, i); i++)
    {
        month++;
        n -= mb_getDayOfMonth(year, i);
    }

    // 计算day
    day += n;

    mb_setYear(year);
    mb_setMonth(month);
    mb_setDay(day);
}

void CCalendar::mb_showDate()
{
    if (m_year > 0)
        cout << m_day << " " << m_month << " " << m_year << endl;
    else
        cout << m_day << " " << m_month << " " << 1 - m_year << " BC" << endl;
}

bool CCalendar::mb_isLeapYear(int year)
{
    if (year >= 1582) // 1582后特别判断100
        if ((year % 100) == 0)
        {
            if ((year % 400) == 0)
                return true;
            else
                return false;
        }

    if ((year % 4) == 0)
        return true;

    return false;
}

int CCalendar::mb_getDayOfMonth(int year, int month) //格里高利历year年month月的天数
{
    if (month == 2)
        return mb_isLeapYear(year) ? 29 : 28;
    else
        return month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31;
}

void CCalendar::mb_setYear(int year)
{
    m_year = year;
}

void CCalendar::mb_setMonth(int month)
{
    m_month = month;
}

void CCalendar::mb_setDay(int day)
{
    m_day = day;
}

int CCalendar::mb_getYear(int year)
{
    return m_year;
}

int CCalendar::mb_getMonth(int month)
{
    return m_month;
}

int CCalendar::mb_getDay(int day)
{
    return m_day;
}