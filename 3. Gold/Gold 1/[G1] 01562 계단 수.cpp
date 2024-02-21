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

#define MOD 1'000'000'000

int DFS(int depth, int num, int isVisited, vector<vector<vector<int>>>& dp)
{
	int n = dp.size() - 1;
	int result = dp[depth][num][isVisited];

	if (result != -1)
		return result;
	if (depth == n)
		return isVisited == (1 << 10) - 1;

	result = 0;
	if (num + 1 <= 9)
		result += DFS(depth + 1, num + 1, isVisited | 1 << (num + 1), dp);
	if (num - 1 >= 0)
		result += DFS(depth + 1, num - 1, isVisited | 1 << (num - 1), dp);
	result %= MOD;

	return dp[depth][num][isVisited] = result;
}
int main()
{
	FastIO;

	int n;
	Cin n;

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(10, vector<int>(1 << 10, -1)));
	int result = 0;
	Foro(9)
	{
		result += DFS(1, i, 1 << i, dp);
		result %= MOD;
	}
	Cout result Endl;
}