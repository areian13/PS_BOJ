#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

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

#define MOD 1'000

typedef vector<vector<LLONG>> Matrix;

Matrix operator*(const Matrix& a, const Matrix& b)
{
	int n = a.size();
	Matrix result(n, vector<LLONG>(n));

	For(n)
	{
		Forj(n)
		{
			for (int k = 0; k < n; k++)
				result[i][j] += (a[i][k] * b[k][j]) % MOD;
			result[i][j] %= MOD;
		}
	}
	return result;
}

Matrix pow(const Matrix& mat, LLONG r)
{
	if (r == 1)
		return mat;
	Matrix result = pow(mat, r / 2);
	result = result * result;
	if (r % 2 == 1)
		result = result * mat;
	return result;
}
int main()
{
	int n;
	LLONG r;
	Cin n >> r;

	Matrix mat(n, vector<LLONG>(n, 0));
	For(n)
	{
		Forj(n)
			Cin mat[i][j];
	}
	mat = pow(mat, r);
	For(n)
	{
		Forj(n)
			Cout mat[i][j] % MOD fspc;
		Enter;
	}
}