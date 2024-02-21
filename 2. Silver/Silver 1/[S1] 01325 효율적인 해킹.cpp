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

int BFS(int start, vector<vector<int>>& graph)
{
	int n = graph.size();

	vector<int> isVisited(n, false);
	isVisited[start] = true;

	queue<int> Q;
	Q.push(start);

	int result = 1;
	while (!Q.empty())
	{
		int curr = Q.front();
		Q.pop();

		for (int next : graph[curr])
		{
			if (isVisited[next])
				continue;

			result++;
			isVisited[next] = true;
			Q.push(next);
		}
	}
	return result;
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<int>> graph(n);
	For(m);
	{
		int a, b;
		Cin a >> b;
		a--; b--;

		graph[b].push_back(a);
	}

	vector<int> cnt(n, 0);
	For(n)
		cnt[i] = BFS(i, graph);

	int maxHacking = *max_element(cnt.begin(), cnt.end());
	For(n)
	{
		if (maxHacking == cnt[i])
			Cout i + 1 fspc;
	}
}