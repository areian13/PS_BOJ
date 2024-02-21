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
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cfloat>
#include <cstring>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

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

int BT(int y, int x, vector<vector<int>>& dist, int k, vector<vector<char>>& map)
{
	int r = dist.size();
	int c = dist[0].size();

	if (y == 0 && x == c - 1)
		return (dist[y][x] == k);

	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			continue;
		if (map[ny][nx] == 'T' || dist[ny][nx] != -1)
			continue;

		dist[ny][nx] = dist[y][x] + 1;
		result += BT(ny, nx, dist, k, map);
		dist[ny][nx] = -1;
	}
	return result;
}

int main()
{
	FastIO;

	int r, c, k;
	Cin r >> c >> k;

	vector<vector<char>> map(r, vector<char>(c));
	For(r)
	{
		Forj(c)
			Cin map[i][j];
	}

	vector<vector<int>> dist(r, vector<int>(c, -1));
	dist[r - 1][0] = 1;

	int result = BT(r - 1, 0, dist, k, map);
	Cout result Endl;
}