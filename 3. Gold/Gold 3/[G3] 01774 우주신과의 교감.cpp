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

int Find(int a, vector<int>& p)
{
	if (p[a] == -1)
		return a;
	return p[a] = Find(p[a], p);
}

void Union(int a, int b, vector<int>& p)
{
	a = Find(a, p);
	b = Find(b, p);
	if (a == b)
		return;
	p[b] = a;
}

struct Edge {
	int u = -1;
	int v = -1;
	double w = 0;
	bool operator<(const Edge& a) const
	{
		return w < a.w;
	}
};

struct Pos {
	double x;
	double y;
};

double Dist(Pos a, Pos b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<Pos> god(n + 1);
	Foro(n)
		Cin god[i].x >> god[i].y;

	vector<Edge> edge(n * (n - 1) / 2);
	for (int i = 1, idx = 0; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++, idx++)
			edge[idx] = { i,j,Dist(god[i], god[j]) };
	}
	sort(stoe(edge));

	vector<int> p(n + 1, -1);
	int connect = m;
	For(m)
	{
		int a, b;
		Cin a >> b;
		if (Find(a, p) != Find(b, p))
			Union(a, b, p);
		else
			connect--;
	}

	double result = 0;

	for (int i = 0, cnt = 0; ; i++)
	{
		if (Find(edge[i].u, p) != Find(edge[i].v, p))
		{
			Union(edge[i].u, edge[i].v, p);
			result += edge[i].w;
			cnt++;
			if (cnt == n - 1 - connect)
				break;
		}
	}
	lf(2);
	Cout result;
}