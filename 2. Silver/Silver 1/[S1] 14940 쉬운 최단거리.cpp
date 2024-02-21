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
	int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<int>> result(n, vector<int>(m, -1));
	Pos s;
	For(n)
	{
		Forj(m)
		{
			Cin map[i][j];
			if (map[i][j] == 2)
				s = { i,j };
			if (map[i][j] == 0)
				result[i][j] = 0;
		}
	}

	result[s.y][s.x] = 0;

	queue<Pos> Q;
	Q.push(s);

	while (!Q.empty())
	{
		int y = Q.front().y;
		int x = Q.front().x;
		Q.pop();

		For(4)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (result[ny][nx] != -1 || map[ny][nx] == 0)
				continue;

			result[ny][nx] = result[y][x] + 1;
			Q.push({ ny,nx });
		}
	}
	For(n)
	{
		Forj(m)
			Cout result[i][j] fspc;
		Enter;
	}
}
