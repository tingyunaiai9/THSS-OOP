#pragma once

class CCalendar
{
private:
    int m_year; // 用负数表示公元前 0=公元前1年 -4712=公元前4713
    int m_month;
    int m_day;

public:
    CCalendar();
    void mb_addDate(long long n);
    void mb_showDate();

    int mb_getYear(int year);
    int mb_getMonth(int month);
    int mb_getDay(int day);

private:
    void mb_setYear(int year);
    void mb_setMonth(int month);
    void mb_setDay(int day);

    bool mb_isLeapYear(int year);
    int mb_getDayOfMonth(int year, int month);
};