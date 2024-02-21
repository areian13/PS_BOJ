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

	p[b] = a;
}

struct Edge {
	int u = -1;
	int v = -1;
	int w = 0;
	bool operator<(const Edge& a) const
	{
		return w < a.w;
	}
};

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<pair<int, int>> xi(n);
	vector<pair<int, int>> yi(n);
	vector<pair<int, int>> zi(n);

	For(n)
	{
		int x, y, z;
		Cin x >> y >> z;
		xi[i] = { x,i };
		yi[i] = { y,i };
		zi[i] = { z,i };
	}
	sort(stoe(xi));
	sort(stoe(yi));
	sort(stoe(zi));

	vector<Edge> tunnel(3 * (n - 1));
	For(n - 1)
	{
		tunnel[3 * i + 0] = { xi[i].second, xi[i + 1].second,xi[i + 1].first - xi[i].first };
		tunnel[3 * i + 1] = { yi[i].second, yi[i + 1].second,yi[i + 1].first - yi[i].first };
		tunnel[3 * i + 2] = { zi[i].second, zi[i + 1].second,zi[i + 1].first - zi[i].first };
	}
	sort(stoe(tunnel));

	vector<int> p(n, - 1);
	int result = 0;
	for (int i = 0, cnt = 0; ; i++)
	{
		if (Find(tunnel[i].u, p) != Find(tunnel[i].v, p))
		{
			Union(tunnel[i].u, tunnel[i].v, p);
			result += tunnel[i].w;
			cnt++;
			if (cnt == n - 1)
				break;
		}
	}
	Cout result Endl;
}