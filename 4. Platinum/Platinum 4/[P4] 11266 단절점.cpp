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
#include <random>

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

struct Edge
{
	int u, v;

	bool operator!=(Edge c)
	{
		return u != c.u || v != c.v;
	}
	bool operator<(Edge c)
	{
		if (u != c.u)
			return u < c.u;
		return v < c.v;
	}
};

vector<vector<int>> edge;
vector<int> nthDFS;
vector<vector<Edge>> BCC;

stack<Edge> S;

int cntDFS = 0;

int DFS(int cur, int pre = 0)
{
	nthDFS[cur] = ++cntDFS;
	int result = nthDFS[cur];

	for (int nxt : edge[cur])
	{
		if (nxt == pre)
			continue;

		if (nthDFS[cur] > nthDFS[nxt])
			S.push({ cur,nxt });

		if (nthDFS[nxt] > 0)
			result = min(result, nthDFS[nxt]);
		else
		{
			int temp = DFS(nxt, cur);
			result = min(result, temp);

			if (temp < nthDFS[cur])
				continue;

			vector<Edge> curBCC;
			while (!S.empty() && S.top() != Edge{ cur, nxt })
			{
				curBCC.push_back(S.top());
				S.pop();
			}
			curBCC.push_back(S.top());
			S.pop();

			BCC.push_back(curBCC);
		}
	}

	return result;
}

int main()
{
	FastIO;

	int v, e;
	Cin v >> e;

	edge.resize(v + 1);
	For(e)
	{
		int a, b;
		Cin a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	nthDFS.resize(v + 1);
	Foro(v)
	{
		if (nthDFS[i] == 0)
			DFS(i);
	}

	int cntBCC = BCC.size();
	vector<int> cntNode(v + 1, 0), articPoint;
	for(vector<Edge>& curBCC : BCC)
	{
		vector<bool> isExisted(v + 1, false);
		for (Edge& edge : curBCC)
		{
			isExisted[edge.u] = true;
			isExisted[edge.v] = true;
		}
		Foro(v)
			cntNode[i] += isExisted[i];
	}

	Foro(v)
	{
		if (cntNode[i] >= 2)
			articPoint.push_back(i);
	}

	Cout articPoint.size() Endl;
	for (int& point : articPoint)
		Cout point fspc;
}