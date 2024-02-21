
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

array<array<int, 9>, 9> sudoku;
array<array<bool, 10>, 9> row;
array<array<bool, 10>, 9> col;
array<array<bool, 10>, 9> sqr;

void Toggle(int y, int x, int num)
{
	row[y][num] = !row[y][num];
	col[x][num] = !col[x][num];
	sqr[y / 3 * 3 + x / 3][num] = !sqr[y / 3 * 3 + x / 3][num];
}

void DFS(int cnt)
{
	if (cnt == 81)
	{
		For(9)
		{
			Forj(9)
				Cout sudoku[i][j] fspc;
			Enter;
		}
		exit(0);
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (sudoku[y][x] == 0)
	{
		Foro(9)
		{
			if (!row[y][i] && !col[x][i] && !sqr[y / 3 * 3 + x / 3][i])
			{
				Toggle(y, x, i);
				sudoku[y][x] = i;

				DFS(cnt + 1);

				sudoku[y][x] = 0;
				Toggle(y, x, i);
			}
		}
	}
	else
		DFS(cnt + 1);
}

int main()
{
	FastIO;

	For(9)
	{
		Forj(9)
		{
			Cin sudoku[i][j];
			if (sudoku[i][j] != 0)
				Toggle(i, j, sudoku[i][j]);
		}
	}

	DFS(0);
}