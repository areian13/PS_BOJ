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

enum Block
{
	BLINK = -2,
	BLACK,
	RAINBOW
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

struct Pos
{
	int y, x;
};

struct Info
{
	int size = 0;
	int nofRB = 0;
	Pos pos;

	bool operator<(Info a) const
	{
		if (size != a.size)
			return size < a.size;
		if (nofRB != a.nofRB)
			return nofRB < a.nofRB;
		if (pos.y != a.pos.y)
			return pos.y < a.pos.y;
		if (pos.x != a.pos.x)
			return pos.x < a.pos.x;
	}
};

void PrintBlock(Info block)
{
	Cout block.size spc block.nofRB spc block.pos.y spc block.pos.x Endl;
}

void PrintMap(vector<vector<int>> map)
{
	int n = map.size();
	For(n)
	{
		Forj(n)
		{
			if (map[i][j] == BLINK)
				Cout "   ";
			elif(map[i][j] == BLACK)
				Cout "-1 ";
			else
				Cout " " << map[i][j] fspc;
		}
		Enter;
	}
	Enter;
}
Info GetMaxBlock(int m, vector<vector<int>>& map)
{
	Info maxBlock = { 0,0,{ INT_MAX,INT_MAX } };

	int n = map.size();
	vector<vector<vector<bool>>> isVisited(n, vector<vector<bool>>(n, vector<bool>(m + 1, false)));

	For(n)
	{
		Forj(n)
		{
			int stdNum = map[i][j];
			if (map[i][j] > RAINBOW && !isVisited[i][j][stdNum])
			{
				Info block = { 1,0,{ i,j } };

				isVisited[i][j][stdNum] = true;

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

						if (ny < 0 || ny >= n || nx < 0 || nx >= n)
							continue;
						if (isVisited[ny][nx][stdNum] || (map[ny][nx] != RAINBOW && map[ny][nx] != map[i][j]))
							continue;

						isVisited[ny][nx][stdNum] = true;
						block.size++;
						block.nofRB += (map[ny][nx] == RAINBOW);
						Q.push({ ny,nx });
					}
				}
				maxBlock = max(maxBlock, block);
			}
		}
	}

	return maxBlock;
}

void EraseMaxBlock(Pos start, vector<vector<int>>& map)
{
	int n = map.size();

	vector<vector<bool>> isVisited(n, vector<bool>(n, false));
	isVisited[start.y][start.x] = true;

	queue<Pos> Q;
	Q.push(start);

	int stdNum = map[start.y][start.x];

	while (!Q.empty())
	{
		int y = Q.front().y;
		int x = Q.front().x;
		Q.pop();

		map[y][x] = BLINK;

		For(4)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n)
				continue;
			if (isVisited[ny][nx] || (map[ny][nx] != RAINBOW && map[ny][nx] != stdNum))
				continue;

			isVisited[ny][nx] = true;
			Q.push({ ny,nx });
		}
	}
}

void Gravity(vector<vector<int>>& map)
{
	int n = map.size();

	Forj(n)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (map[i][j] >= RAINBOW)
			{
				int y = i;
				while (y + 1 < n && map[y + 1][j] == BLINK)
				{
					map[y + 1][j] = map[y][j];
					map[y][j] = BLINK;
					y++;
				}
			}
		}
	}
}

void Spin(vector<vector<int>>& map)
{
	int n = map.size();
	
	vector<vector<int>> temp(n, vector<int>(n));
	For(n)
	{
		Forj(n)
			temp[i][j] = map[j][n - i - 1];
	}
	For(n)
	{
		Forj(n)
			map[i][j] = temp[i][j];
	}
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<int>> map(n, vector<int>(n));
	For(n)
	{
		Forj(n)
			Cin map[i][j];
	}

	int result = 0;
	while (true)
	{
		Info maxBlock = GetMaxBlock(m, map);
		//PrintBlock(maxBlock);
		if (maxBlock.size < 2)
			break;
		result += pow(maxBlock.size, 2);
		//PrintMap(map);

		EraseMaxBlock(maxBlock.pos, map);
		//PrintMap(map);

		Gravity(map);
		//PrintMap(map);

		Spin(map);
		//PrintMap(map);

		Gravity(map);
		//PrintMap(map);
	}
	Cout result;
}