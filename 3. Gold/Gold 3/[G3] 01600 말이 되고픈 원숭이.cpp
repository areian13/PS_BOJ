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
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

array<int, 12> dy = { 1,0,-1,0,2,1,-1,-2,-2,-1,1,2, };
array<int, 12> dx = { 0,1,0,-1,1,2,2,1,-1,-2,-2,-1, };

struct Pos
{
    int y, x, z;
};

int MinDist(int y, int x, vector<vector<vector<int>>>& dist)
{
    int k = dist[0][0].size() - 1;

    int result = INT_MAX;
    for (int z = 0; z <= k; z++)
    {
        if (dist[y][x][z] == -1)
            continue;
        result = min(result, dist[y][x][z]);
    }
    result = (result == INT_MAX ? -1 : result);
    return result;
}

int main()
{
    FastIO;

	int k, w, h;
	cin >> k >> w >> h;

	// w가 가로, h가 세로임에 유의하자
	vector<vector<int>> map(h, vector<int>(w));
	For(h)
	{
		Forj(w)
			Cin map[i][j];
	}

	// 진짜 3중vector선언하는거 질병이네
	// k번 뛸 수 있다는것은 0번~k번이므로 k+1로 선언해야한다.
	vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(k + 1, -1)));
	dist[0][0][0] = 0;

	queue<Pos> Q;
	Q.push({ 0,0,0 });

	while (!Q.empty())
	{
		int y = Q.front().y;
		int x = Q.front().x;
		int z = Q.front().z;
		Q.pop();

		for (int i = 0; i < 12; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nz = z + (i >= 4);


			if (ny < 0 || ny >= h || nx < 0 || nx >= w || nz > k)
				continue;
			if (map[ny][nx] == 1 || dist[ny][nx][nz] != -1)
				continue;

			dist[ny][nx][nz] = dist[y][x][z] + 1;
			Q.push({ ny,nx,nz });
		}
	}

	int result = MinDist(h - 1, w - 1, dist);
	Cout result Endl;
}