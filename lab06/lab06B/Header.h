#include <iostream>
#pragma warning (disable:4996)
#pragma once


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
	bool operator>(const Time& more) const;
	bool operator==(const Time& equal) const;
	Time(int hh = 0, int mm = 0);

private:
	int hour;
	int minute;

	friend istream& operator>>(istream& in, Time& time);
	friend ostream& operator<<(ostream& out, const Time& time);
};