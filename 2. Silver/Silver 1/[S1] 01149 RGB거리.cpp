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

int n;

int MinPrice(int idx, int color, vector<array<int, 3>>& home, vector<array<int, 3>>& dp)
{
	if (idx == n - 1)
		return home[idx][color];
	if (dp[idx][color] != 0)
		return dp[idx][color];

	int a = (color + 1) % 3;
	int b = (color + 2) % 3;

	return dp[idx][color] = home[idx][color] + min(MinPrice(idx + 1, a, home, dp), MinPrice(idx + 1, b, home, dp));
}

int main()
{
	FastIO;

	Cin n;

	vector<array<int, 3>> home(n), dp(n);
	For(n)
	{
		Forj(3)
			Cin home[i][j];
	}

	array<int, 3> result;
	For(3)
		result[i] = MinPrice(0, i, home, dp);

	Cout min({ result[0],result[1],result[2] });
}