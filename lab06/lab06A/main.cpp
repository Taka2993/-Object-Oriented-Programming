#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Header.h"
#pragma warning (disable:4996)
#pragma once


using namespace std;

class Day
{
public:
    Day();
    bool from_str(const string& stg);
    string to_str();
    void dst(int offset);

private:
    int day;
    string month;
    vector<Time> list;
};


int main()
{
    ifstream inputFile("lab6_calendar.txt");

    if (!inputFile.is_open())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<Day> cal;
    Day day;

    while (getline(inputFile, line))
    {
        if (day.from_str(line))
        {
            cal.push_back(day);
        }
    }
    cout << "Calendar" << endl;

    for (auto& e : cal)
    {
        cout << e.to_str() << endl;
    }

    // DST shift
    for (auto& e : cal)
    {
        e.dst(1);
    }
    cout << "DST" << endl;

    for (auto& e : cal)
    {
        cout << e.to_str() << endl;
    }

    cout << "End" << endl;

    return 0;
}



istream& operator>>(istream& in, Time& time)
{
    char stg = ':';
    in >> time.hour >> stg >> time.minute;
    return in;
}

ostream& operator<<(ostream& out, const Time& time)
{
    out << setiosflags(ios::right) << setfill('0') <<
        setw(2) << time.hour << ":" << setfill('0')
        << setw(2) << time.minute;
    return out;
}

Day::Day()
{
    day = 0;
    month = "";
    list.clear();
}



bool Day::from_str(const string& op_line)
{
    int re = 0;
    string temp;
    vector<Time> new_l;
    istringstream string(op_line);
    bool loop = true;
    while (loop)
    {
        if (re == 0)
        {
            string >> day;
            if (!string)
            {
                loop = false;
            }
        }
        else if (re == 1)
        {
            string >> month;
            if (!string)
            {
                loop = false;
            }
        }
        else
        {
            Time time;
            string >> time;
            if (!string)
            {
                loop = false;
            }
            else
            {
                new_l.push_back(time);
            }
            re++;
        }
        re++;
    }

    list = new_l;

    return true;
}

string Day::to_str()
{
    string out;
    out = to_string(day) + " " + month;
    for (auto t : list)
    {
        out += " " + t.to_str();
    }
    return out;
}

void Day::dst(int)
{
    for (auto& stg : list)
    {
        stg.dst();
    }
}

Time::Time(int hh, int mm)
{
    hour = hh;
    minute = mm;
}

Time& Time::dst()
{
    hour++;
    hour = hour % 24;
    return *this;
}

string Time::to_str()
{
    string out, mm;
    if (minute < 10 || hour < 10)
    {
        if (minute < 10 && !(hour < 10))
        {
            out = to_string(hour) + ":0" + to_string(minute);
        }
        else if (!(minute < 10) && hour < 10)
        {
            out = "0" + to_string(hour) + ":" + to_string(minute);
        }
        else
        {
            out = "0" + to_string(hour) + ":0" + to_string(minute);
        }
    }
    else
    {
        out = to_string(hour) + ":" + to_string(minute);
    }
    return out;

}