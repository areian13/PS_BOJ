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
#include <random>

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

void Spin(vector<vector<int>>& map)
{
	int n = map.size();

	vector<vector<int>> temp(n, vector<int>(n));
	For(n)
	{
		Forj(n)
			temp[j][n - i - 1] = map[i][j];
	}
	map = temp;
}

void Move(vector<vector<int>>& map)
{
	int n = map.size();
	vector<vector<bool>> isFixed(n, vector<bool>(n, false));
	For(n)
	{
		Forj(n)
		{
			if (map[i][j] == 0)
				continue;

			int y = i;
			while (y > 0 && map[y - 1][j] == 0)
				y--;

			map[y][j] = map[i][j];

			if (y != i)
				map[i][j] = 0;

			if (y > 0 && map[y][j] == map[y - 1][j] && !isFixed[y - 1][j])
			{
				isFixed[y - 1][j] = true;
				map[y - 1][j] *= 2;
				map[y][j] = 0;
			}
		}
	}
}

int G2048(int cnt, vector<vector<int>>& map)
{
	int result = 0;
	if (cnt == 5)
	{
		int n = map.size();
		For(n)
		{
			Forj(n)
				result = max(result, map[i][j]);
		}
		return result;
	}

	For(4)
	{
		vector<vector<int>> temp = map;
		Move(temp);
		result = max(result, G2048(cnt + 1, temp));
		Spin(map);
	}
	return result;
}

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<vector<int>> map(n, vector<int>(n));
	For(n)
	{
		Forj(n)
			Cin map[i][j];
	}

	Cout G2048(0, map) Endl;
}