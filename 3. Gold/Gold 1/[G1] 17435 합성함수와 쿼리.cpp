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

#define N_MAX 19

int main()
{
	FastIO;

	int m;
	Cin m;

	vector<array<int, N_MAX>> f(m + 1);
	Foro(m)
		Cin f[i][0];

	for (int j = 1; j < N_MAX; j++)
	{
		Foro(m)
			f[i][j] = f[ f[i][j - 1] ][j - 1];
	}

	int q;
	Cin q;
	
	while (q--)
	{
		int n, x;
		Cin n >> x;

		for (int i = N_MAX - 1; i >= 0; i--)
		{
			if (n >= 1 << i)
			{
				n -= 1 << i;
				x = f[x][i];
			}
		}
		Cout x Endl;
	}
}