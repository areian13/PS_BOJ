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
#include <time.h>
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

struct Maal
{
	bool can;
	int cnt;
};

struct Pos
{
	int y, x;
	int d;
};

array<int, 8> dy = { 2,1,-1,-2,-2,-1,1,2 };
array<int, 8> dx = { 1,2,2,1,-1,-2,-2,-1 };

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<Maal>> distSum(n, vector<Maal>(m, { true,0 }));
	For(n)
	{
		Forj(m)
		{
			char maal;
			Cin maal;

			if (maal == '.')
				continue;

			int k = maal - '0';
			vector<vector<int>> dist(n, vector<int>(m, -1));
			dist[i][j] = 0;

			queue<Pos> Q;
			Q.push({ i,j,0 });

			while (!Q.empty())
			{
				int y = Q.front().y;
				int x = Q.front().x;
				int d = Q.front().d;
				Q.pop();

				for (int t = 0; t < 8; t++)
				{
					int ny = y + dy[t];
					int nx = x + dx[t];
					int nd = (d - 1 + k) % k;

					if (ny < 0 || ny >= n || nx < 0 || nx >= m)
						continue;
					if (dist[ny][nx] != -1)
						continue;

					dist[ny][nx] = dist[y][x] + (d == 0);
					Q.push({ ny,nx,nd });
				}
			}

			for (int t = 0; t < n; t++)
			{
				for (int l = 0; l < m; l++)
				{
					distSum[t][l].can &= (dist[t][l] != -1);
					distSum[t][l].cnt += dist[t][l];
				}
			}
		}
	}
	int result = INT_MAX;
	For(n)
	{
		Forj(m)
		{
			if (distSum[i][j].can)
				result = min(result, distSum[i][j].cnt);
		}
	}
	result = (result != INT_MAX ? result : -1);
	Cout result Endl;
}