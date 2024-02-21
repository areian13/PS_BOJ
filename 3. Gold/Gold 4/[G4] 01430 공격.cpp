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
#define ulf() cout.unsetf(ios::scientific);
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

struct Pos
{
	int x, y;
	friend istream& operator>>(istream& is, Pos& p)
	{
		is >> p.x >> p.y;
		return is;
	}
};
struct Info
{
	int nth, cnt;
};

double Dist(Pos& a, Pos& b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
	FastIO;

	int n, r;
	double d;
	Pos enemy;
	Cin n >> r >> d >> enemy;

	vector<Pos> tower(n + 1);
	tower[0] = enemy;
	Foro(n)
		Cin tower[i];

	vector<vector<int>> edge(n + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (Dist(tower[i], tower[j]) > r)
				continue;

			edge[i].push_back(j);
			edge[j].push_back(i);
		}
	}

	vector<bool> isVisited(n + 1, false);
	isVisited[0] = true;

	queue<Info> Q;
	Q.push({ 0,0 });

	double result = 0;
	while (!Q.empty())
	{
		int cur = Q.front().nth;
		int cnt = Q.front().cnt;
		Q.pop();

		for (int nxt : edge[cur])
		{
			if (isVisited[nxt])
				continue;

			isVisited[nxt] = true;
			result += d / pow(2, cnt);
			Q.push({ nxt,cnt + 1 });
		}
	}
	lf(2);
	Cout result Endl;	
}