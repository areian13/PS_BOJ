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

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

struct Pos
{
	int y, x;
};

int main()
{
	FastIO;

	int n, m, k;
	Cin n >> m >> k;

	vector<vector<bool>> map(n, vector<bool>(m, false));
	For(k)
	{
		int r, c;
		Cin r >> c;

		map[r - 1][c - 1] = true;
	}

	vector<vector<bool>> isVisited(n, vector<bool>(m, false));
	int result = 0;
	For(n)
	{
		Forj(m)
		{
			if (isVisited[i][j] || !map[i][j])
				continue;

			int size = 1;
			
			isVisited[i][j] = true;
			
			queue<Pos> Q;
			Q.push({ i,j });

			while (!Q.empty())
			{
				int y = Q.front().y;
				int x = Q.front().x;
				Q.pop();

				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (ny < 0 || ny >= n || nx < 0 || nx >= m)
						continue;
					if (isVisited[ny][nx] || !map[ny][nx])
						continue;

					size++;
					isVisited[ny][nx] = true;
					Q.push({ ny,nx });
				}
			}
			result = max(result, size);
		}
	}
	Cout result Endl;
}