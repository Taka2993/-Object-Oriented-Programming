#include <iostream>
#pragma warning (disable:4996)
#pragma once  

using namespace std;

class Time
{
public:
	Time& dst();
	string to_str();
	Time(int hh = 0, int mm = 0);

private:
	int hour;
	int minute;

	friend istream& operator>>(istream& in, Time& time);
	friend ostream& operator<<(ostream& out, const Time& time);
};