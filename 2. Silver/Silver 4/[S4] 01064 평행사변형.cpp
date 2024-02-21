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

struct Coord {
	double x, y;
};


double GetLine(Coord a, Coord b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double GetIncline(Coord a, Coord b)
{
	if (a.x == b.x)
		return DBL_MAX;
	return (a.y - b.y) / (a.x - b.x);
}

int main()
{
	FastIO;

	array<Coord, 3> coord;
	array<double, 3> line;
	double result = -1;

	double maxLen = 0;
	double minLen = DBL_MAX;

	For(3)
		Cin coord[i].x >> coord[i].y;
	
	For(3)
		line[i] = GetLine(coord[i], coord[(i + 1) % 3]);

	if (GetIncline(coord[0], coord[1]) == GetIncline(coord[1], coord[2]))
		goto IS_IMPOSSIBLE;

	For(3)
	{
		maxLen = max(maxLen, (line[i] + line[(i + 1) % 3]) * 2);
		minLen = min(minLen, (line[i] + line[(i + 1) % 3]) * 2);
	}
	result = maxLen - minLen;

IS_IMPOSSIBLE:
	lf(10);
	Cout result;
}