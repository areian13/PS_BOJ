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

int main()
{
	FastIO;

	int a, b, c, d, e;
	Cin a >> b >> c >> d >> e;

	array<int, 3> p = { a * d * d,2 * a * d * e + b * d,a * e * e + b * e + c };
	array<int, 3> q = { a * d,b * d,c * d + e };
	array<int, 3> r;
	For(3)
		r[i] = p[i] - q[i];

	int D = r[1] * r[1] - 4 * r[0] * r[2];

	string result = "";
	if (r[0] != 0)
	{
		if (D > 0)
			result = "Go ahead";
		elif(D == 0)
			result = "Remember my character";
		elif(D < 0)
			result = "Head on";
	}
	elif(r[1] != 0)
		result = "Remember my character";
	else
	{
		if (r[2] == 0)
			result = "Nice";
		else
			result = "Head on";
	}
	Cout result Endl;
}