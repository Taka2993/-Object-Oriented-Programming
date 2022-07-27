#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)


using namespace std;

class Time
{
public:
    void read(const char* number);
    Time operator+(const Time& more) const;
    Time operator-(const Time& less) const;
    Time& operator++();
    Time operator++(int);
    bool operator<(const Time& less) const;
    Time(int hh = 0, int mm = 0);
private:
    int hour;
    int minute;

    friend ostream& operator<<(ostream& out, const Time& t);
};

void print(const vector<Time>& v)
{
    for (auto& t : v) {
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

Time::Time(int hh, int mm) : hour(hh), minute(mm)
{

}

ostream& operator<<(ostream& out, const Time& time)
{
    out << setiosflags(ios::right) << setfill(' ') <<
        setw(2) << time.hour <<":" << setfill('0')
        << setw(2) << time.minute;
    return out;
}

bool Time::operator<(const Time& less) const
{
    int minutes_o;
    int minutes_t;
    int time_f;
    minutes_o = hour * 60 + minute;
    minutes_t = less.hour * 60 + less.minute;
    time_f = minutes_o - minutes_t;

    if (0 < time_f)
    {
        return false;
    }
    else
    {
        return true;
    }
}


Time Time::operator+(const Time& more) const
{
    int minutes_o;
    int minutes_t;
    int time_f;
    Time return_calc;
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
    Time return_calc;
    minutes_o = hour * 60 + minute;
    minutes_t = less.hour * 60 + less.minute;
    time_f = minutes_o + minutes_t;
    return_calc.hour = time_f / 60;
    return_calc.minute = time_f % 60;

    if (return_calc.hour > 23)
        return_calc.hour = return_calc.hour - 24;
    if (return_calc.minute > 59)
        return_calc.minute = return_calc.minute - 60;
    return return_calc;
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