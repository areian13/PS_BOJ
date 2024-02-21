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

#define INF 1'000'000'000

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

struct Pos
{
	int y, x;
};

int main()
{
	FastIO;

	while (true)
	{
		static int tc = 0;

		int n;
		Cin n;

		if (n == 0)
			break;

		vector<vector<int>> cave(n, vector<int>(n));
		For(n)
		{
			Forj(n)
				Cin cave[i][j];
		}

		vector<vector<int>> dist(n, vector<int>(n, INF));
		dist[0][0] = cave[0][0];

		queue<Pos> Q;
		Q.push({ 0,0 });

		while (!Q.empty())
		{
			int y = Q.front().y;
			int x = Q.front().x;
			Q.pop();

			For(4)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n)
					continue;
				if (dist[ny][nx] <= dist[y][x] + cave[ny][nx])
					continue;

				dist[ny][nx] = dist[y][x] + cave[ny][nx];
				Q.push({ ny,nx });
			}
		}
		printf("Problem %d: %d\n", ++tc, dist[n - 1][n - 1]);
	}
}