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

struct Pos
{
	int y, x;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

int Dir(char c)
{
	if (c == 'L')
		return 0;
	if (c == 'D')
		return 1;
	if (c == 'R')
		return 2;
	return 3;
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<char>> map(n, vector<char>(m));
	For(n)
	{
		Forj(m)
			Cin map[i][j];
	}

	vector<vector<bool>> isVisited(n, vector<bool>(m, false)), isSafe(n, vector<bool>(m, false));
	int result = 0;
	For(n)
	{
		Forj(m)
		{
			if (isVisited[i][j])
				continue;

			int y = i;
			int x = j;

			stack<Pos> S;
			while (!isVisited[y][x])
			{
				isVisited[y][x] = true;
				S.push({ y,x });

				int ty = y;
				y += dy[Dir(map[ty][x])];
				x += dx[Dir(map[ty][x])];
			}

			if (!isSafe[y][x])
				result++;

			while (!S.empty())
			{
				isSafe[S.top().y][S.top().x] = true;
				S.pop();
			}
		}
	}
	Cout result Endl;
}
