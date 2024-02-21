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

array<int, 12> daysPerMonth = { 31,29,31,30,31,30,31,31,30,31,30,31 };

bool IsPossibleNum(int n, array<bool, 10>& num)
{
	while (n > 0)
	{
		if (num[n % 10] == true)
			return false;
		n /= 10;
	}
	return true;
}

int CountPossibleDayPerMonth(int month, array<bool, 10>& num)
{
	if (!IsPossibleNum(month, num))
		return 0;

	int result = 0;
	Foro(daysPerMonth[month - 1])
		result += IsPossibleNum(i, num);
	return result;
}

int main()
{
	FastIO;

	int tc;
	Cin tc;

	while (tc--)
	{
		array<bool, 10> num = { false, };
		For(10)
			Cin num[i];

		int result = 0;
		Foro(12)
			result += CountPossibleDayPerMonth(i, num);
		Cout result Endl;
	}
}