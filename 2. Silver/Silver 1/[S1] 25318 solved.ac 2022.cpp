#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <random>
#include <type_traits>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

struct Date
{
	array<int, 12 + 1> dayOfMonth = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year;
	int month;
	int day;
	
	int hour;
	int minute;
	int second;

	LLONG time;

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

double MakeDay(LLONG time)
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

	vector<Opinion> opinion(n + 1);
	Foro(n)
	{
		int year, month, day, hour, minute, second, rank;
		scanf("%d/%d/%d %d:%d:%d %d", &year, &month, &day, &hour, &minute, &second, &rank);

		opinion[i] = { {year,month,day,hour,minute,second} };
		opinion[i].l = rank;
	}
	Foro(n)
		opinion[i].p = max(pow(0.5, MakeDay(opinion[n].t.time - opinion[i].t.time) / 365), pow(0.9, n - i));

	double ja = 0;
	double mo = 0;
	Foro(n)
	{
		ja += opinion[i].p * opinion[i].l;
		mo += opinion[i].p;
	}
	int result = ja / (mo != .0 ? mo : 1) + 0.50001;
	Cout result Endl;
}