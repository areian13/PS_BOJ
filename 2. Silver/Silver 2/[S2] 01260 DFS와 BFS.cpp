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
#include <numeric>
#include <functional>

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
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

enum Type
{
	D, B
};

void DBFS(Type type, int start, vector<vector<int>>& graph)
{
	int n = graph.size();
	For(n)
	{
		if (type == D)
			sort(graph[i].begin(), graph[i].end(), greater<int>());
		else if (type == B)
			sort(graph[i].begin(), graph[i].end(), less<int>());
	}

	vector<bool> isVisited(n, false);

	deque<int> DQ;
	DQ.push_back(start - 1);

	while (!DQ.empty())
	{
		int curr = (type == D ? DQ.back() : DQ.front());
		type == D ? DQ.pop_back() : DQ.pop_front();

		if (isVisited[curr])
			continue;

		Cout curr + 1 fspc;
		isVisited[curr] = true;

		for (int next : graph[curr])
		{
			if (isVisited[next])
				continue;

			DQ.push_back(next);
		}
	}
	Enter;
}

void DFS(int start, vector<vector<int>>& graph)
{
	DBFS(D, start, graph);
}
void BFS(int start, vector<vector<int>>& graph)
{
	DBFS(B, start, graph);
}

int main()
{
	FastIO;

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> graph(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(v, graph);
	BFS(v, graph);
}