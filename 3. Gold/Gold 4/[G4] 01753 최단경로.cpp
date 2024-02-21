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

#define INF 1'000'000'000

struct Node
{
	int v, d;

	friend bool operator<(const Node& a, const Node& b)
	{
		return a.d > b.d;
	}
};

int main()
{
	FastIO;

	int v, e;
	Cin v >> e;

	int k;
	Cin k;
	k--;

	vector<vector<Node>> graph(v);
	For(e)
	{
		int u, v, w;
		Cin u >> v >> w;
		u--, v--;

		graph[u].push_back({ v,w });
	}

	vector<int> dist(v, INT_MAX);
	dist[k] = 0;

	priority_queue<Node> PQ;
	PQ.push({ k,0 });

	while (!PQ.empty())
	{
		int u = PQ.top().v;
		int d = PQ.top().d;
		PQ.pop();

		for (Node& node : graph[u])
		{
			int v = node.v;
			int nd = d + node.d;

			if (dist[v] <= nd)
				continue;

			dist[v] = nd;
			PQ.push({ v,nd });
		}
	}

	For(v)
		Cout (dist[i] != INT_MAX ? to_string(dist[i]) : "INF") Endl;
}