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

// 인접 리스트 방식

struct Edge
{
	int u, v;
};

void Eulerian(int cur, vector<Edge>& edge, vector<vector<int>>& adj, vector<int>& degree)
{
	//Cout cur + 1 fspc; 왜 여기다 출력하면 61퍼에서 틀림?
	while (!adj[cur].empty())
	{
		int e = adj[cur].back();
		int u = edge[e].u;
		int v = edge[e].v;
		
		if (degree[e] > 0)
		{
			degree[e]--;
			if (cur == u)
				Eulerian(v, edge, adj, degree);
			else
				Eulerian(u, edge, adj, degree);
		}
		else
			adj[cur].pop_back();
	}
	Cout cur + 1 fspc;
}
int main()
{
	FastIO;

	int n;
	Cin n;

	vector<Edge> edge;
	vector<vector<int>> adj(n);
	vector<int> degree(n * n, 0);
	int edgeCnt = 0;

	int isPossible = true;
	For(n)
	{
		int deg = 0;
		Forj(n)
		{
			int val;
			Cin val;

			deg += val;
			if (val == 0 || i >= j)
				continue;

			edge.push_back({ i,j });

			degree[edgeCnt] += val;
			adj[i].push_back(edgeCnt);
			adj[j].push_back(edgeCnt);
			edgeCnt++;
		}
		isPossible &= (deg % 2 == 0);
	}

	if (isPossible)
		Eulerian(0, edge, adj, degree);
	else
		Cout "-1";
}