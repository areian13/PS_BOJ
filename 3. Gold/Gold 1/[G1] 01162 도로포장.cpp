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

#define INF LLONG_MAX

struct Route
{
	LLONG v,k,w;

	bool operator>(Route c) const
	{
		return w > c.w;
	}
};
int main()
{
	FastIO;

	LLONG n, m, k;
	Cin n >> m >> k;

	vector<vector<Route>> road(n + 1);
	For(m)
	{
		LLONG u, v, w;
		Cin u >> v >> w;

		road[u].push_back({ v,0,w });
		road[v].push_back({ u,0,w });
	}

	vector<vector<LLONG>> dist(n + 1, vector<LLONG>(k + 1, INF));
	dist[1][0] = 0;

	heap<Route> H;
	H.push({ 1,0,0 });

	while (!H.empty())
	{
		LLONG cur = H.top().v;
		LLONG curDist = H.top().w;
		LLONG curK = H.top().k;
		H.pop();

		if (curDist > dist[cur][curK])
			continue;

		For(road[cur].size())
		{
			LLONG nxt = road[cur][i].v;
			LLONG nxtDist = curDist + road[cur][i].w;
			LLONG nxtK = curK + 1;

			if (nxtK <= k && curDist < dist[nxt][nxtK])
			{
				dist[nxt][nxtK] = curDist;
				H.push({ nxt,nxtK,curDist });
			}

			if (curK <= k && nxtDist < dist[nxt][curK])
			{
				dist[nxt][curK] = nxtDist;
				H.push({ nxt,curK,nxtDist });
			}
		}
	}

	LLONG result = dist[n][0];
	Foro(k)
		result = min(result, dist[n][i]);
	Cout result;
}