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
#include <time.h>
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

struct Friend
{
	int root = -1;
	int candy = 0;
	int cnt = 1;
};

int Find(int a, vector<Friend>& p)
{
	if (p[a].root == a)
		return a;
	return p[a].root = Find(p[a].root, p);
}

void Union(int a, int b, vector<Friend>& p)
{
	a = Find(a, p);
	b = Find(b, p);

	p[max(a, b)].root = min(a, b);
}

int main()
{
	FastIO;

	int n, m, k;
	Cin n >> m >> k;

	vector<Friend> friends(n + 1);
	Foro(n)
	{
		Cin friends[i].candy;
		friends[i].root = i;
	}

	while (m--)
	{
		int a, b;
		Cin a >> b;

		Union(a, b, friends);
	}

	Foro(n)
	{
		if (friends[i].root == i)
			continue;

		int p = Find(i, friends);
		friends[p].candy += friends[i].candy;
		friends[p].cnt += friends[i].cnt;
	}

	vector<int> dp(k + 1, 0);
	Foro(n)
	{
		if (friends[i].root != i)
			continue;

		for (int j = k; j > friends[i].cnt; j--)
			dp[j] = max(dp[j], dp[j - friends[i].cnt] + friends[i].candy);
	}
	Cout dp[k] Endl;
}