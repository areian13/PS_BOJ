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

#define N_MAX 30

int main()
{
	FastIO;

	int n, k, m;
	Cin n >> k >> m;

	vector<int> x(n);
	For(n)
		Cin x[i];

	vector<array<int, N_MAX>> f(k + 1);
	Foro(k)
		Cin f[i][0];

	for (int j = 1; j < N_MAX; j++)
	{
		Foro(k)
			f[i][j] = f[ f[i][j - 1] ][j - 1];
	}

	For(n)
	{
		int M = m - 1;
		int X = x[i];

		for (int j = N_MAX - 1; j >= 0; j--)
		{
			if (M >= 1 << j)
			{
				M -= 1 << j;
				X = f[X][j];
			}
		}
		Cout X fspc;
	}
}