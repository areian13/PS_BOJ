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

struct Matrix
{
	int r, c;
};

void MCM(vector<Matrix>& matrix, vector<vector<int>>& dp)
{
	int n = matrix.size();

	For(n)
	{
		Forj(n - i)
		{
			int a = j;
			int b = i + j;

			if (a == b)
				continue;

			dp[a][b] = INT_MAX;
			for (int k = a; k < b; k++)
				dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a].r * matrix[k].c * matrix[b].c));
		}
	}
}

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<Matrix> matrix(n);
	For(n)
		Cin matrix[i].r >> matrix[i].c;

	vector<vector<int>> dp(n, vector<int>(n, 0));
	MCM(matrix, dp);

	Cout dp[0][n - 1] Endl;
}