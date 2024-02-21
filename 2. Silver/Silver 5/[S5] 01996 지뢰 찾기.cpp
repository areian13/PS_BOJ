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
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

array<int, 8> dy = { 1,1,1,0,-1,-1,-1,0 };
array<int, 8> dx = { -1,0,1,1,1,0,-1,-1 };
int main()
{
	FastIO;

	int n;
	Cin n;

	vector<vector<char>> field(n, vector<char>(n));
	vector<vector<int>> result(n, vector<int>(n, 0));

	For(n)
	{
		Forj(n)
			Cin field[i][j];
	}

	For(n)
	{
		Forj(n)
		{
			if (field[i][j] == '.')
				continue;
			for (int k = 0; k < 8; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n)
					continue;
				if (field[ny][nx] != '.')
					continue;
				result[ny][nx] += (field[i][j] - '0');
			}
		}
	}
	For(n)
	{
		Forj(n)
		{
			if (field[i][j] != '.')
				Cout '*';
			elif(result[i][j] >= 10)
				Cout 'M';
			else
				Cout result[i][j];
		}
		Enter;
	}
}