#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

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

#define MAX 52

int CtoI(char c)
{
	if (among('A', c, 'Z'))
		return c - 'A';
	return c - 'a' + 26;
}
int main()
{
	FastIO;

	array<vector<int>, MAX> edge;
	array<array<int, MAX>, MAX> c = { 0, }, f = { 0, };
	
	int n;
	Cin n;

	For(n)
	{
		char u, v;
		int w;
		Cin u >> v >> w;

		u = CtoI(u);
		v = CtoI(v);

		c[u][v] += w;
		c[v][u] += w;

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	int result = 0;
	int s = CtoI('A');
	int e = CtoI('Z');

	while (true)
	{
		array<int, MAX> prv;
		fill(stoe(prv), -1);

		queue<int> Q;
		Q.push(s);
		while (!Q.empty() && prv[e] == -1)
		{
			int cur = Q.front();
			Q.pop();

			for (int nxt : edge[cur])
			{
				if (c[cur][nxt] > f[cur][nxt] && prv[nxt] == -1)
				{
					Q.push(nxt);
					prv[nxt] = cur;
					if (nxt == e)
						break;
				}
			}
		}

		if (prv[e] == -1)
			break;

		int flow = INT_MAX;
		for (int i = e; i != s; i = prv[i])
			flow = min(flow, c[prv[i]][i] - f[prv[i]][i]);
		for (int i = e; i != s; i = prv[i])
		{
			f[prv[i]][i] += flow;
			f[i][prv[i]] -= flow;
		}
		result += flow;
	}
	Cout result Endl;
}