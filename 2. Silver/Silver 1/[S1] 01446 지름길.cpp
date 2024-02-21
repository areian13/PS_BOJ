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
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cfloat>
#include <cstring>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

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

#define LEN 10'000

struct Road
{
	int v, d;
};

int main()
{
	FastIO;

	int n, d;
	Cin n >> d;

	array<vector<Road>, LEN + 1> shortcut;
	for (int i = 0; i < n; i++)
	{
		int s, e, w;
		Cin s >> e >> w;

		shortcut[s].push_back({ e,w });
	}

	array<int, LEN + 1> dist;
	fill(dist.begin(), dist.end(), INT_MAX);

	for (int i = 0; i <= LEN; i++)
	{
		dist[i] = min(dist[i], (i == 0 ? 0 : dist[i - 1] + 1));

		for (Road& road : shortcut[i])
			dist[road.v] = min(dist[road.v], dist[i] + road.d);
	}
	Cout dist[d] Endl;
}