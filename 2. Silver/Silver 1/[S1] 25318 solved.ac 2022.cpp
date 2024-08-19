#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Date
{
    array<int, 12 + 1> dayOfMonth = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int year;
    int month;
    int day;

    int hour;
    int minute;
    int second;

    long long time;

    bool isLeapYear;

    Date()
    {
        this->year = 0;
        this->month = 0;
        this->day = 0;
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
        this->time = 0;
        this->isLeapYear = false;
    }
    Date(int year, int month, int day, int hour, int minute, int second)
    {
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        this->second = second;

        isLeapYear = IsLeapYear(year);
        if (isLeapYear)
            dayOfMonth[2] = 29;

        time = 0;
        for (int y = 1; y < year; y++)
            time += IsLeapYear(y) ? 366 : 365;

        for (int m = 1; m < month; m++)
            time += dayOfMonth[m];

        time += day - 1;

        time = time * 24 * 60 * 60 + hour * 60 * 60 + minute * 60 + second;
    }

    bool IsLeapYear(int year)
    {
        return (year % 400) == 0 || (year % 100) != 0 && (year % 4) == 0;
    }

    friend bool operator<(Date& a, Date& b)
    {
        if (a.year != b.year)
            return a.year < b.year;
        if (a.month != b.month)
            return a.month < b.month;
        if (a.day != b.day)
            return a.day < b.day;
        if (a.hour != b.hour)
            return a.hour < b.hour;
        if (a.minute != b.minute)
            return a.minute < b.minute;
        return a.second < b.second;
    }
};

double MakeDay(long long time)
{
    double result = time;
    result /= 24 * 60 * 60;
    return result;
}

struct Opinion
{
    Date t;
    double p;
    int l;
};

int main()
{
    FastIO;

    int n;
    scanf("%d", &n);

    vector<Opinion> opinion(n);
    for (int i = 0; i < n; i++)
    {
        int year, month, day, hour, minute, second, rank;
        scanf("%d/%d/%d %d:%d:%d %d", &year, &month, &day, &hour, &minute, &second, &rank);

        opinion[i].t = { year,month,day,hour,minute,second };
        opinion[i].l = rank;
    }
    for (int i = 0; i < n; i++)
        opinion[i].p = max(pow(0.5, MakeDay(opinion[n - 1].t.time - opinion[i].t.time) / 365), pow(0.9, n - 1 - i));

    double p = 0;
    double q = 0;
    for (int i = 0; i < n; i++)
    {
        p += opinion[i].p * opinion[i].l;
        q += opinion[i].p;
    }

    int result = p / (q != .0 ? q : 1) + 0.50001;
    cout << result << '\n';
}