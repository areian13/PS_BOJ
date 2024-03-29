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

LLONG GetTree(LLONG x, vector<LLONG>& a)
{
	LLONG result = 0;
	for (LLONG tree : a)
		result += max(tree - x, 0ll);
	return result;
}

LLONG BS(LLONG m, vector<LLONG>& a)
{
	LLONG start = 0;
	LLONG end = *max_element(stoe(a)) - 1;

	LLONG result = 0;
	while (start <= end)
	{
		LLONG mid = (start + end) / 2;
		LLONG tree = GetTree(mid, a);

		if (tree >= m)
		{
			start = mid + 1;
			result = max(result, mid);
		}
		else
			end = mid - 1;
	}
	return result;
}

int main()
{
	FastIO;

	LLONG n, m;
	Cin n >> m;

	vector<LLONG> a(n);
	For(n)
		Cin a[i];

	LLONG result = BS(m, a);
	Cout result Endl;
}