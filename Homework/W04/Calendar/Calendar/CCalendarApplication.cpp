#include "pch.h"

#include "CCalendar.h"
#include "CCalendarApplication.h"

void CCalendarApplication::mb_run()
{
    CCalendar* p_calendar = NULL;
    p_calendar = new CCalendar();

    cout << "Today: ";
    p_calendar->mb_showDate();

    long long n;
    cout << "Please input n for the date n days later: ";
    cin >> n;

    p_calendar->mb_addDate(n);

    cout << n << " days later: ";
    p_calendar->mb_showDate();

    delete p_calendar;
}