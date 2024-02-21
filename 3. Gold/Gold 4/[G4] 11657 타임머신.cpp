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

struct Node
{
	int u, v, w;
};

int BF(int n, int m, vector<Node>& node, vector<LLONG>& dist)
{
	For(n)
	{
		Forj(m)
		{
			int u = node[j].u;
			int v = node[j].v;
			int w = node[j].w;

			if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				if (i == n)
					return false;
			}
		}
	}
	return true;
}
int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<Node> node(m);
	For(m)
	{
		int u, v, w;
		Cin u >> v >> w;

		node[i] = { u,v,w };
	}

	vector<LLONG> dist(n + 1, INT_MAX);
	dist[1] = 0;

	if (!BF(n, m, node, dist))
		Cout -1;
	else
	{
		for (int i = 2; i <= n; i++)
			Cout(dist[i] != INT_MAX ? dist[i] : -1) Endl;
	}
}