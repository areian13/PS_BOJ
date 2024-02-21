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

struct Pos
{
	int y, x;
};

struct Info
{
	Pos pos;
	int key;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,-1,0,1 };

int BFS(Pos& start, vector<vector<char>>& map)
{
	int n = map.size();
	int m = map[0].size();

	array<int, 1 << 6> temp;
	fill(stoe(temp), -1);
	vector<vector<array<int, 1 << 6>>> dist(n, vector<array<int, 1 << 6>>(m, temp));
	dist[start.y][start.x][000000] = 0;

	queue<Info> Q;
	Q.push({ start, 000000 });

	while (!Q.empty())
	{
		int y = Q.front().pos.y;
		int x = Q.front().pos.x;
		int key = Q.front().key;
		Q.pop();

		if (map[y][x] == '1')
			return dist[y][x][key];

		For(4)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nKey = key;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (map[ny][nx] == '#' || dist[ny][nx][nKey] != -1)
				continue;

			if (among('A', map[ny][nx], 'F'))
			{
				if (!(nKey & 1 << (map[ny][nx] - 'A')))
					continue;
			}

			if (among('a', map[ny][nx], 'f'))
				nKey |= (1 << (map[ny][nx] - 'a'));

			dist[ny][nx][nKey] = dist[y][x][key] + 1;
			Q.push({ ny,nx,nKey });
		}
	}
	return -1;
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<char>> map(n, vector<char>(m));
	Pos start;
	For(n)
	{
		Forj(m)
		{
			Cin map[i][j];

			if (map[i][j] == '0')
			{
				start = { i,j };
				map[i][j] = '.';
			}
		}
	}

	Cout BFS(start, map) Endl;
}