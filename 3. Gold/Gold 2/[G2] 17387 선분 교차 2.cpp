#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
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

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define	COUT cout << "OUT: " <<
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
#define ulf cout.unsetf(ios::scientific);
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

struct Point
{
	LLONG x, y;

	bool operator>(Point c)
	{
		if (x != c.x)
			return x > c.x;
		return y > c.y;
	}

	bool operator>=(Point c)
	{
		if (x != c.x)
			return x >= c.x;
		return y >= c.y;
	}
};

struct Line
{
	Point p1, p2;
};

LLONG Cross(LLONG x1, LLONG y1, LLONG x2, LLONG y2)
{
	return x1 * y2 - x2 * y1;
}

int CCW(Point a, Point b, Point c)
{
	LLONG result = Cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
	if (result > 0)
		return 1;
	elif(result < 0)
		return -1;
	return 0;
}

int CrossJudgment(Line a, Line b)
{
	int p1p2 = CCW(a.p1, a.p2, b.p1) * CCW(a.p1, a.p2, b.p2);
	int p3p4 = CCW(b.p1, b.p2, a.p1) * CCW(b.p1, b.p2, a.p2);

	if (p1p2 == 0 && p3p4 == 0)
	{
		if (a.p1 > a.p2)
			swap(a.p1, a.p2);
		if (b.p1 > b.p2)
			swap(b.p1, b.p2);

		return a.p2 >= b.p1 && b.p2 >= a.p1;
	}
	return p1p2 <= 0 && p3p4 <= 0;
}

int main()
{
	FastIO;

	array<Line, 2> line;
	For(2)
		Cin line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;

	Cout CrossJudgment(line[0], line[1]) Endl;
}