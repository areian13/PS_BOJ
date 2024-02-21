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

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int nthZero = 0;
vector<int> zeroSize;

void BFS(int i, int j, vector<vector<int>>& map, vector<vector<int>>& zeroNum, vector<vector<bool>>& isVisited)
{
	int n = map.size();
	int m = map[0].size();

	isVisited[i][j] = true;

	queue<Pos> Q;
	Q.push({ i,j });

	zeroNum[i][j] = nthZero;
	int cnt = 1;

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
			if (map[ny][nx] == 1 || isVisited[ny][nx])
				continue;

			isVisited[ny][nx] = true;
			zeroNum[ny][nx] = nthZero;
			Q.push({ ny,nx });
			cnt++;
		}
	}
	zeroSize.push_back(cnt);
	nthZero++;
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	For(n)
	{
		string num;
		Cin num;

		Forj(m)
			map[i][j] = (num[j] - '0');
	}

	vector<vector<int>> zeroNum(n, vector<int>(m));
	vector<vector<bool>> isVisited(n, vector<bool>(m, false));
	For(n)
	{
		Forj(m)
		{
			if (map[i][j] == 1 || isVisited[i][j])
				continue;

			BFS(i, j, map, zeroNum, isVisited);
		}
	}

	For(n)
	{
		Forj(m)
		{
			if (map[i][j] == 0)
			{
				Cout 0;
				continue;
			}

			set<int> Set;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m)
					continue;
				if (map[ny][nx] == 1 || !isVisited[ny][nx])
					continue;
				Set.insert(zeroNum[ny][nx]);
			}
			for (int value : Set)
				map[i][j] += zeroSize[value];

			Cout map[i][j] % 10;
		}
		Enter;
	}
}