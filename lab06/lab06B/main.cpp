#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Header.h"
#pragma warning (disable:4996)
#pragma once


using namespace std;

void print(const vector<Time>& v)
{
    for (auto& t : v)
    {
        cout << t << endl;
    }
}

int main()
{
    Time time1, time2, duration;

    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1 < time2) {
        duration = time2 - time1;
        cout << "Starting time was " << time1 << endl;
    }else{
        duration = time1 - time2;
        cout << "\nStarting time was " << time2 << endl;
    }
    cout << "\nDuration was " << duration << endl;

    vector<Time> tv(5);
    for (auto& t : tv) {
        t.read("Enter time:");
    }

    cout << "\nTimes: " << endl;
    print(tv);

    Time sum;
    for (auto t : tv) {
        sum = sum + t;
    }

    cout << "\nSum of times: " << sum << endl;

    cout << "\nPost increment: " << endl;
    print(tv);
    for (auto& t : tv) {
        cout << t++ << endl;
    }

    print(tv);

    cout << "Pre increment: " << endl;
    for (auto& t : tv) {
        cout << ++t << endl;
    }

    sort(tv.begin(), tv.end());

    cout << "Sorted times: " << endl;
    print(tv);

    return 0;
}

void Time::read(const char* input)
{
    char i;
    int n = 0;
    cout << input << endl;
    while (n == 0)
    {
        cin >> hour >> i >> minute;
        if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 60)
        {
            n = 1;
        }
        else
        {
            printf("\nError");
        }
    }
}

istream& operator>>(istream& in, Time& time)
{
    cin >> time.hour >> time.minute;
    return in;
}

ostream& operator<<(ostream& out, const Time& time)
{
    out << setiosflags(ios::right) << setfill(' ') <<
        setw(2) << time.hour << ":" << setfill('0')
        << setw(2) << time.minute;
    return out;
}

Time::Time(int hh, int mm) : hour(hh), minute(mm)
{

}



Time Time::operator+(const Time& more) const
{
    int minutes_o;
    int minutes_t;
    int time_f;
    Time return_calc = Time(0, 0);
    minutes_o = hour * 60 + minute;
    minutes_t = more.hour * 60 + more.minute;
    time_f = minutes_o + minutes_t;
    return_calc.hour = time_f / 60;
    return_calc.hour = return_calc.hour % 24;
    return_calc.minute = time_f % 60;
    return return_calc;
}

Time Time::operator-(const Time& less) const
{
    int minutes_o;
    int minutes_t;
    int time_f;
    Time return_calc = Time(0, 0);
    minutes_o = hour * 60 + minute;
    minutes_t = less.hour * 60 + less.minute;
    time_f = minutes_o - minutes_t;
    return_calc.hour = time_f / 60;
    return_calc.hour = return_calc.hour % 24;
    return_calc.minute = time_f % 60;

    return return_calc;
}

bool Time::operator<(const Time& less) const
{
    int minutes_o;
    int minutes_t;
    int time_f;
    minutes_o = hour * 60 + minute;
    minutes_t = less.hour * 60 + less.minute;
    time_f = minutes_t - minutes_o;

    if (time_f > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Time::operator>(const Time& more) const
{
    int minutes_o;
    int minutes_t;
    int time_f;
    minutes_o = hour * 60 + minute;
    minutes_t = more.hour * 60 + more.minute;
    time_f = minutes_o - minutes_t;
    if (time_f > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Time& Time::operator++()
{
    minute = hour * 60 + minute;
    minute++;
    hour = minute / 60;
    hour = hour % 24;
    minute = minute % 60;
    return *this;
}

Time Time::operator++(int)
{
    Time rev = *this;
    minute = hour * 60 + minute;
    minute++;
    hour = minute / 60;
    hour = hour % 24;
    minute = minute % 60;
    return rev;
}


bool Time::operator==(const Time& equal) const
{
    int minutes_o;
    int minutes_t;
    int time_f;
    minutes_o = hour * 60 + minute;
    minutes_t = equal.hour * 60 + equal.minute;
    time_f = minutes_o - minutes_t;
    if (time_f == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}