#include <iostream>
#include <string>
#include <iomanip>
#pragma warning (disable:4996)


using namespace std;

class Time
{
public:
    void read(const char* number);
    bool lessThan(Time lt);
    Time subtract(Time less);
    void display();

private:
    int hour;
    int minute;
};

int main() {
    Time time1, time2, duration;

    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1.lessThan(time2)) {
        duration = time2.subtract(time1);
        cout << "Starting time was ";
        time1.display();
    }
    else {
        duration = time1.subtract(time2);
        cout << "Starting time was ";
        time2.display();
    }
    cout << "Duration was ";
    duration.display();

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

bool Time::lessThan(Time lt)
{
    if (hour < lt.hour || (hour == lt.hour && minute < lt.minute))
    {
        return true;
    }
    else
        return false;
}

Time Time::subtract(Time less)
{
    Time calc_a;
    int calc_b;
    calc_b = (hour * 60 + minute) - (less.hour * 60 + less.minute);
    calc_a.hour = calc_b / 60;
    calc_a.minute = calc_b % 60;
    return calc_a;
}


void Time::display()
{
    cout << setiosflags(ios::right); cout << setfill('0') << setw(2) << hour;
    cout << ":" << setfill('0') << setw(2) << minute << endl;
}