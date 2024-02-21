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


struct Medal
{
	int gold, silver, bronze;
	int cnt;
	
	friend istream& operator>>(istream& is, Medal& m)
	{
		is >> m.gold >> m.silver >> m.bronze;
		m.cnt = m.gold + m.silver + m.bronze;
		return is;
	}
	friend ostream& operator<<(ostream& os, Medal& m)
	{
		os << m.gold spc m.silver spc m.bronze;
		return os;
	}
	friend bool BigColor(Medal& a, Medal& b)
	{
		if (a.gold != b.gold)
			return a.gold > b.gold;
		if (a.silver != b.silver)
			return a.silver > b.silver;
		return a.bronze > b.bronze;
	}
};

int main()
{
	FastIO;

	int tc;
	Cin tc;

	while (tc--)
	{
		Medal USA, RUS;
		Cin USA >> RUS;

		Cout USA spc RUS Endl;

		string result = "none";
		if (USA.cnt > RUS.cnt && BigColor(USA, RUS))
			result = "both";
		elif(USA.cnt > RUS.cnt)
			result = "count";
		elif(BigColor(USA, RUS))
			result = "color";
		Cout result Endl;
		Enter;
	}
}