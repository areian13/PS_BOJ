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

void TopologySort(vector<vector<int>>& node, vector<int>& indegree)
{
	int n = node.size() - 1;

	queue<int> Q;
	Foro(n)
	{
		if (indegree[i] == 0)
			Q.push(i);
	}

	vector<int> result(n + 1);
	Foro(n)
	{
		if (Q.empty())
		{
			Cout "0" Endl;
			return;
		}

		int cur = Q.front();
		Q.pop();

		result[i] = cur;
		for(int nxt : node[cur])
		{
			if (--indegree[nxt] == 0)
				Q.push(nxt);
		}
	}
	Foro(n)
		Cout result[i] Endl;
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<int>> node(n + 1);
	vector<int> indegree(n + 1);

	For(m)
	{
		int s;
		Cin s;

		vector<int> singer(s);
		Forj(s)
			Cin singer[j];

		Forj(s - 1)
		{
			node[singer[j]].push_back(singer[j + 1]);
			indegree[singer[j + 1]]++;
		}
	}
	TopologySort(node, indegree);
}