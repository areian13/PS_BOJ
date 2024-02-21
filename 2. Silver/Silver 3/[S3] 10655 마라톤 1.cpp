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

struct Pos {
	int x, y;
};

int Dist(Pos a, Pos b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int main()
{
	FastIO;

	int n;
	Cin n;
	
	vector<Pos> pos(n);
	For(n)
		Cin pos[i].x >> pos[i].y;

	int total = 0;
	For(n - 1)
		total += Dist(pos[i], pos[i + 1]);

	int skip = 0;
	for (int i = 1; i < n - 1; i++)
	{
		Pos pre = pos[i - 1];
		Pos cur = pos[i];
		Pos nxt = pos[i + 1];

		int course = Dist(pre, cur) + Dist(cur, nxt);
		int straight = Dist(pre, nxt);
		skip = max(skip, course - straight);
	}
	Cout total - skip;
}